#pragma once
#include "applications_core_export.h"

#include "subscriptions.h"

class Report;
class ToText;

class APPLICATIONS_CORE_EXPORT ProgressDialog
{
public:
  ProgressDialog(Report& report, ToText& toText);

private:
  Subscriptions mSubscriptions;
};
