#include "reducer.h"
#include "store.h"

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
using Model = std::tuple<VisibilityFilter, Todos>;

struct AddTodo
{
  std::string text;

  Todos operator()(Todos todos) const {
    todos.push_back(Todo{ text, false });
    return todos;
  }
};

auto addTodo(std::string text) {
  return AddTodo{ text };
}

struct ToggleTodo
{
  int index;

  Todos operator()(Todos todos) const {
    todos[index].completed = !todos[index].completed;
    return todos;
  }
};

auto toggleTodo(int index) {
  return ToggleTodo{ index };
}

struct SetVisibilityFilter
{
  VisibilityFilter visibilityFilter;

  VisibilityFilter operator()(VisibilityFilter) const {
    return visibilityFilter;
  }
};

auto setVisibilityFilter(VisibilityFilter visibilityFilter) {
  return SetVisibilityFilter{ visibilityFilter };
}

auto draw() {
  return [](auto) { std::cout << "draw\n"; };
}

int main() {
  auto const visibilityFilter = makeReducer<SetVisibilityFilter>();
  auto const todos            = makeReducer<AddTodo, ToggleTodo>();

  auto const todoApp = combineReducers(visibilityFilter, todos);

  auto store = Store{ Model{}, todoApp, draw() };

  store.dispatch(addTodo("Learn about actions"));
  store.dispatch(addTodo("Learn about reducers"));
  store.dispatch(addTodo("Learn about store"));
  store.dispatch(toggleTodo(0));
  store.dispatch(toggleTodo(1));
  store.dispatch(setVisibilityFilter(VisibilityFilter::SHOW_COMPLETED));

  // auto event = char{};

  // while (std::cin >> event)
  //  dispatch (store, event);
}
