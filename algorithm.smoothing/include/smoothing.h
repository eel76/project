#pragma once
#include "algorithm_smoothing_export.h"

class Callback;

class ALGORITHM_SMOOTHING_EXPORT Smoothing
{
public:
  void operator() (Callback& report);
};
