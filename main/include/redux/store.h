#pragma once
#include "eventloop.h"
#include <functional>

template <class Model, class Reducer>
class Store
{
  public:
  template <class Model, class Reducer, class View>
  Store(Model&& initial, Reducer&& reducer, View&& view)
  : mModel(std::forward<Model>(initial)), mReducer(std::forward<Reducer>(reducer)),
    mView(std::forward<View>(view)), mEventLoop() {
  }

  void update() {
    mEventLoop.post([=] { mView(mModel); });
  }

  template <class Action>
  void dispatch(Action&& action) {
    mEventLoop.post([=, applyAction{ std::forward<Action>(action) }] {
      mModel = mReducer(std::move(mModel), applyAction);
    });

    update();
  }

  private:
  std::decay_t<Model>               mModel;
  std::decay_t<Reducer>             mReducer;
  std::function<void(Model const&)> mView;
  EventLoop                         mEventLoop;
};

template <class Model, class Reducer, class View>
Store(Model&& initial, Reducer&& reducer, View&& view)->Store<Model, Reducer>;
