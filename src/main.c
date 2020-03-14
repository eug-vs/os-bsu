#include <stdio.h>
#include "await.h"
#include "cat.h"

#define DATA_DIR_PREFIX "data\\"

int main() {
  char cmd[256];
  char binary[64] = DATA_DIR_PREFIX;
  char report[64] = DATA_DIR_PREFIX;
  int records;
  double payment;

  printf("Enter binary filename: ");
  scanf("%s", binary + 5);
  printf("Enter records number: ");
  scanf("%i", &records);
  puts("");
  sprintf(cmd, "bin\\creator.exe %s %i", binary, records);
  await(cmd);
  printf("Binary file saved to \"%s\" with the following contents:\n", binary);
  cat(binary, 1);

  printf("Enter report filename: ");
  scanf("%s", report + 5);
  printf("Enter payment amount per hour: ");
  scanf("%lf", &payment);
  puts("");
  sprintf(cmd, "bin\\reporter.exe %s %s %lf", binary, report, payment);
  await(cmd);
  printf("Report saved to \"%s\" with the following contents:\n", report);
  cat(report, 0);

  scanf("");
  return 0;
}

