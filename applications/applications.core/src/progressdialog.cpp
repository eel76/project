#include "progressdialog.h"

#include "callback.h"
#include "totext.h"

#include <iostream>

ProgressDialog::ProgressDialog(Callback& report, ToText& toText)
{
  mSubscriptions += report.subscribe([&](std::any const& news)
  {
    std::cout << "news: " << toText (news).value_or("<unknown news>") << "\n";
  });
}
