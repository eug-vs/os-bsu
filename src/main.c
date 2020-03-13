#include <stdio.h>
#include "await.h"
#include "cat.h"

int main() {
  char cmd[256];
  char binary[64];
  char report[64];
  char records[8];
  double payment;

  printf("Enter binary filename: ");
  scanf("%s", binary);
  printf("Enter records number: ");
  scanf("%s", records);
  puts("");
  sprintf(cmd, "bin\\creator.exe %s %s", binary, records);
  await(cmd);
  printf("Binary file saved to \"%s\" with the following contents:\n", binary);
  cat(binary, 1);

  printf("Enter report filename: ");
  scanf("%s", report);
  printf("Enter payment amount per hour: ");
  scanf("%lf", &payment);
  puts("");
  sprintf(cmd, "bin\\reporter.exe %s %s %lf", binary, report, payment);
  await(cmd);
  printf("Report saved to \"%s\" with the following contents:\n", report);
  cat(report, 0);

  return 0;
}

