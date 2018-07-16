#pragma once
#include "applications_core_export.h"

#include <string>

#define TRANSLATION_CONTEXT(_identifier_)                 \
namespace                                                 \
{                                                         \
  class _identifier_                                      \
  {                                                       \
  public:                                                 \
    static std::string tr (char const* text, char const* = nullptr) \
    {                                                     \
      return std::string {text};                          \
    }                                                     \
  };                                                      \
}
