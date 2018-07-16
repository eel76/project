#include "simplification.h"
#include "simplificationstatus.h"
#include "callback.h"

void Simplification::operator() (Callback& report)
{
  int currentNumberOfTriangles{ 100 };
  while (currentNumberOfTriangles --> 0)
  {
    report(SimplificationStatus{ currentNumberOfTriangles });
  }
}
