#include "redux.h"

#include <iostream>
#include <tuple>
#include <vector>

enum class VisibilityFilter { SHOW_ALL, SHOW_COMPLETED, SHOW_ACTIVE };

struct Todo
{
  std::string text;
  bool        completed;
};

using Todos = std::vector<Todo>;

// using State = std::tuple<VisibilityFilter, Todos>;

struct State
{
  VisibilityFilter visibilityFilter;
  Todos            todos;
};

struct AddTodo
{
  std::string text;

  Todos operator()(Todos todos) const {
    todos.push_back(Todo{ text, false });
    return todos;
  }
};

struct ToggleTodo
{
  int index;

  Todos operator()(Todos todos) const {
    todos[index].completed = !todos[index].completed;
    return todos;
  }
};

struct SetVisibilityFilter
{
  VisibilityFilter visibilityFilter;

  VisibilityFilter operator()(VisibilityFilter) const {
    return visibilityFilter;
  }
};

void debug_helper() {
  std::cout << "draw\n";
}

auto draw() {
  return [](auto) { debug_helper(); };
}

int main() {
  auto const visibilityFilter = redux::Reducer<SetVisibilityFilter>();
  auto const todos            = redux::Reducer<AddTodo, ToggleTodo>();

  auto const todoApp = combineReducers(visibilityFilter, todos);

  auto store = redux::Store{ State{}, todoApp, draw() };

  store.dispatch(AddTodo{ "Learn about actions" });
  store.dispatch(AddTodo{ "Learn about reducers" });
  store.dispatch(AddTodo{ "Learn about store" });
  store.dispatch(ToggleTodo{ 0 });
  store.dispatch(ToggleTodo{ 1 });
  store.dispatch(SetVisibilityFilter{ VisibilityFilter::SHOW_COMPLETED });

  // auto event = char{};

  // while (std::cin >> event)
  //  dispatch (store, event);
}
