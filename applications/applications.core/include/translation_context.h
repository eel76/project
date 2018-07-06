#pragma once
#include "applications_core_export.h"

#include "unicodestring.h"

#define TRANSLATION_CONTEXT(_identifier_)                 \
namespace                                                 \
{                                                         \
  class _identifier_                                      \
  {                                                       \
  public:                                                 \
    static UnicodeString tr (char const* text, char const* = nullptr) \
    {                                                     \
      return UnicodeString::fromUtf8 (text);              \
    }                                                     \
  };                                                      \
}
