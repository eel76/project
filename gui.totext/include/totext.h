#pragma once
#include "gui_totext_export.h"

#include "subscription.h"

#include <any>
#include <functional>
#include <map>
#include <optional>
#include <string>
#include <typeindex>

class GUI_TOTEXT_EXPORT ToText
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

    std::optional<std::string> operator() (std::any const& object) const
    {
        auto const provider = mProviders.find (object.type ());
        if (provider == end (mProviders))
            return std::nullopt;

        return std::make_optional (provider->second (object));
    }

private:
    std::map<std::type_index, std::function<std::string(std::any const&)>> mProviders;
};
