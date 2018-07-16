#include "smoothing.h"
#include "smoothingstatus.h"
#include "callback.h"

void Smoothing::operator() (Callback& report)
{
  report(SmoothingStatus{});
}
