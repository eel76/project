#include "simplification.h"
#include "simplificationinfo.h"
#include "report.h"

void simplificationAlgorithm(Report& report)
{
  int currentNumberOfTriangles{ 100 };
  while (currentNumberOfTriangles--> 0)
  {
    report(SimplificationInfo{ currentNumberOfTriangles });
  }
}
