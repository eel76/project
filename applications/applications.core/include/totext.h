#pragma once
#include "applications_core_export.h"

#include "subscription.h"
#include "unicodestring.h"

#include <any>
#include <functional>
#include <map>
#include <typeindex>

class APPLICATIONS_CORE_EXPORT ToTextService
{
public:
    template <class Type, class Provider>
    Subscription allowFor (Provider&& provider)
    {
        using decay_type = std::decay_t<Type>;

        auto const subscription = std::type_index{ typeid (decay_type) };
        mProviders.emplace (subscription, [provider{std::move (provider)}] (std::any const& object)
        {
            return provider (std::any_cast<decay_type> (object));
        });

        return Subscription{[&,subscription] { mProviders.erase (subscription); }};
    }

    UnicodeString operator() (std::any const& object) const
    {
        auto const provider = mProviders.find (object.type ());
        if (provider == end (mProviders))
            return UnicodeString{ nullptr };

        return provider->second (object);
    }

private:
    std::map<std::type_index, std::function<UnicodeString(std::any const&)>> mProviders;
};
