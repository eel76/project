#pragma once
#include "algorithms_core_export.h"

#include <functional>

class [[nodiscard]] ALGORITHMS_CORE_EXPORT Subscription
{
public:
    template <class Cancellation>
    explicit Subscription (Cancellation&& cancellation)
        : mCancellation (std::forward<Cancellation> (cancellation))
    {
    }
    explicit Subscription(std::nullptr_t) = delete;

    ~Subscription ();

    Subscription (Subscription&&);
    Subscription& operator= (Subscription&&);

    void cancel ();

    std::function<void()> release ();

private:
    std::function<void()> mCancellation;
};
