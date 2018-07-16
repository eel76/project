#pragma once
#include "algorithm_simplification_export.h"

class Callback;

class ALGORITHM_SIMPLIFICATION_EXPORT Simplification
{
public:
  void operator() (Callback& report);
};
