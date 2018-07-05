#pragma once
#include "algorithms_core_export.h"
#include "subscription.h"

#include <any>
#include <functional>
#include <map>

class ALGORITHMS_CORE_EXPORT Report
{
public:
  template <class Recipient>
  Subscription subscribe(Recipient&& recipient)
  {
    mRecipients.emplace(mLastID, std::forward<Recipient>(recipient));
    return Subscription{ [&,id{ mLastID++ }]{ mRecipients.erase(id); } };
  }

  template <class Info>
  void operator() (Info&& info) const
  {
    auto const anyInfo = std::any{ std::forward<Info>(info) };

    for (auto&& handler : mRecipients)
      std::invoke(handler.second, anyInfo);
  }

private:
  std::map<int, std::function<void(std::any const&)>> mRecipients;
  int                                                 mLastID{ 0 };
};
