#pragma once
#include "applications_core_export.h"

#include "subscriptions.h"

class Callback;
class ToText;

class APPLICATIONS_CORE_EXPORT ProgressDialog
{
public:
  ProgressDialog(Callback& report, ToText& toText);

private:
  Subscriptions mSubscriptions;
};
