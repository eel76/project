#pragma once
#include "service_core_export.h"
#include "subscription.h"

#include <vector>

class SERVICE_CORE_EXPORT Subscriptions
{
public:
    Subscriptions ();
    ~Subscriptions ();
    
    void operator+= (Subscription&& other);

    Subscription join ();

private:
    std::vector<std::function<void()>> mCancellations;
};
