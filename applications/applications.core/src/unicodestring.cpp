#include "unicodestring.h"

#include <iostream>

    UnicodeString UnicodeString::arg (int value) const
    {
        if (! mData)
            return *this;

        auto placeholder = 0;
        auto position    = std::string::npos;
        auto data        = mData.value ();

        while (position == std::string::npos)
        {
            if (++placeholder >= 10)
                return *this;

            position = data.find ("%" + std::to_string (placeholder));
        }

        data.replace (position, 2, std::to_string (value));
        return UnicodeString { data.c_str () };
    }

std::ostream& operator<< (std::ostream& stream, UnicodeString const& string)
{
    return stream << string.mData.value_or ("");
}
