#include "simplification.h"
#include "simplificationinfo.h"
#include "callback.h"

void simplificationAlgorithm(Callback& report)
{
  int currentNumberOfTriangles{ 100 };
  while (currentNumberOfTriangles--> 0)
  {
    report(SimplificationInfo{ currentNumberOfTriangles });
  }
}
