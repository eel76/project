#pragma once
#include <functional>
#include <tuple>

template<class... Ts> struct Overloaded : Ts... { using Ts::operator()...; };
template<class... Ts> Overloaded(Ts...) ->Overloaded<Ts...>;

template <class... Actions>
auto makeReducer()
{
  return Overloaded
  {
    ([=](auto state, Actions action)
    {
      return action (state);
    })...,
    [=](auto state, auto&&)
    {
      return state;
    }
  };
}

template <size_t... Indexes, class ReducerTuple>
auto combineReducersImpl(std::index_sequence<Indexes...>, ReducerTuple&& reducerTuple)
{
  return[reducers{std::forward<ReducerTuple>(reducerTuple)}](auto state, auto&& action) -> decltype (state)
  {
    return { (std::invoke (std::get<Indexes> (reducers), std::get<Indexes>(state), action))... };
  };
}

template <class... Reducers>
auto combineReducers(Reducers&&... reducers)
{
  return combineReducersImpl(std::make_index_sequence<sizeof...(Reducers)>{}, std::make_tuple(std::forward<Reducers>(reducers)...));
}

