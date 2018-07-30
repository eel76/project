#pragma once
#include "detail/get.h"
#include "detail/overloaded.h"

namespace redux {
  template <class... Actions>
  auto makeReducer() {
    return Overloaded{ ([=](auto state, Actions action) { return action(state); })...,
                       [=](auto state, auto&&) { return state; } };
  }

  template <size_t... Indexes, class ReducerTuple>
  auto combineReducersImpl(std::index_sequence<Indexes...>, ReducerTuple&& reducerTuple) {
    return [reducers{ std::forward<ReducerTuple>(
           reducerTuple) }](auto state, auto&& action) -> decltype(state) {
      return { (std::invoke(std::get<Indexes>(reducers),
                            redux::get<Indexes, sizeof...(Indexes)>(state), action))... };
    };
  }

  template <class... Reducers>
  auto combineReducers(Reducers&&... reducers) {
    return combineReducersImpl(std::make_index_sequence<sizeof...(Reducers)>{},
                               std::make_tuple(std::forward<Reducers>(reducers)...));
  }
}
