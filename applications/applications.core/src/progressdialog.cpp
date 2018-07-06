#include "progressdialog.h"

#include "report.h"
#include "totext.h"

#include <iostream>

ProgressDialog::ProgressDialog(Report& report, ToText& toText)
{
  mSubscriptions += report.subscribe([&](std::any const& news)
  {
    std::cout << "news: " << toText(news) << "\n";
  });
}
