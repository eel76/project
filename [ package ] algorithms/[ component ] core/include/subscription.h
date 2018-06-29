#pragma once
#include "core_export.h"
#include <functional>

class [[nodiscard]] CORE_EXPORT Subscription
{
public:
    template <class Cancellation>
    explicit Subscription (Cancellation&& cancellation)
        : mCancellation (std::forward<Cancellation> (cancellation))
    {
    }

    ~Subscription ();

    Subscription (Subscription&&);
    Subscription& operator= (Subscription&&);

    void cancel ();

    std::function<void()> release ();

private:
    std::function<void()> mCancellation;
};
