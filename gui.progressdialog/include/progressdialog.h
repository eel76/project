#pragma once
#include "gui_progressdialog_export.h"

#include "subscriptions.h"

class Callback;
class ToText;

class GUI_PROGRESSDIALOG_EXPORT ProgressDialog
{
public:
  ProgressDialog(Callback& report, ToText& toText);

private:
  Subscriptions mSubscriptions;
};
