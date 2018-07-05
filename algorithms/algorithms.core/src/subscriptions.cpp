#include "subscriptions.h"

Subscriptions::Subscriptions () = default;

Subscriptions::~Subscriptions ()
{
	join ().cancel ();
}

void Subscriptions::operator+= (Subscription&& other)
{
	mCancellations.emplace_back (other.release ());
}

Subscription Subscriptions::join ()
    {
        return Subscription{[cancellations{std::move(mCancellations)}]
        {
            std::vector<Subscription> subscriptions;

            for (auto&& cancellation : cancellations)
                subscriptions.emplace_back (cancellation);
        }};
    }
