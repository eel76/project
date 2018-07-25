#pragma once
#include "eventloop.h"
#include <functional>

template <class Model>
class Store
{
public:
  template <class Model, class View>
  Store (Model&& initial, View&& view)
    : mModel (std::forward<Model> (initial))
    , mView (std::forward<View> (view))
    , mEventLoop ()
  {
  }

  void update ()
  {
    mEventLoop.post ([=] {
      mView (mModel);
    });
  }

  template <class Action>
  void dispatch (Action&& action)
  {
    mEventLoop.post ([=, applyAction{std::forward<Action> (action)}]
    {
      mModel = applyAction (mModel);
    });

    update ();
  }

private:
  std::decay_t<Model> mModel;
  std::function<void(Model const&)> mView;
  EventLoop mEventLoop;
};

template <class Model, class View>
Store(Model&& initial, View&& view)->Store<Model>;
