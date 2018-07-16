#pragma once
#include "algorithm_callback_export.h"
#include "subscription.h"

#include <any>
#include <map>

class ALGORITHM_CALLBACK_EXPORT Callback
{
public:
  template <class NewsHandler>
  Subscription subscribe(NewsHandler&& newsHandler)
  {
    mRecipients.emplace(mLastID, std::forward<NewsHandler>(newsHandler));
    return Subscription{ [this,id{ mLastID++ }]{ mRecipients.erase(id); } };
  }

  template <class News>
  void operator() (News&& news) const
  {
    auto const anyNews = std::any{ std::forward<News>(news) };

    for (auto&& handler : mRecipients)
      std::invoke(handler.second, anyNews);
  }

private:
  using ID = int;
  using Recipient = std::function<void(std::any const&)>;

  std::map<ID, Recipient> mRecipients;
  ID                      mLastID{ 0 };
};
