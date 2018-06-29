#include "subscription.h"

    Subscription::~Subscription ()
    {
        cancel ();
    }

    Subscription::Subscription (Subscription&&) = default;
    Subscription& Subscription::operator= (Subscription&&) = default;

    void Subscription::cancel ()
    {
        mCancellation ();
        mCancellation = [] {};
    }

    std::function<void()> Subscription::release ()
    {
        auto cancellation {std::move (mCancellation)};
        return cancellation;
    }
