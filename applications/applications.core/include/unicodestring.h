#pragma once
#include "applications_core_export.h"

#include <iosfwd>
#include <optional>
#include <string>

class APPLICATIONS_CORE_EXPORT UnicodeString
{
public:
    explicit UnicodeString (std::nullptr_t)
        : mData ()
    {
    }
    explicit UnicodeString (char const* data)
      : mData(data ? std::optional<std::string> {data} : std::nullopt)
    {
    }

    UnicodeString arg (int value) const;

    friend std::ostream& operator<< (std::ostream& stream, UnicodeString const& string);

    static UnicodeString fromUtf8 (char const* data)
    {
        return UnicodeString{ data };
    }

private:
    std::optional<std::string> mData;
};
