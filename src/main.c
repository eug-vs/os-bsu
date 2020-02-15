#include "header.h"


void await(char* cmd) {
  STARTUPINFO info = {sizeof(info)};
  PROCESS_INFORMATION processInfo;

  if (CreateProcess(NULL, cmd, NULL, NULL, TRUE, 0, NULL, NULL, &info, &processInfo)) {
    WaitForSingleObject(processInfo.hProcess, INFINITE);
  } else {
    puts("Error while creating process!");
  }
}


int main() {
  char binary_path[64];
  char report_path[64];
  char records[8];
  double hour_payment;
  char cmd[256];


  printf("Enter binary file path: ");
  scanf("%s", binary_path);
  printf("Enter records number: ");
  scanf("%s", records);
  puts("");
  sprintf(cmd, "build\\creator.exe %s %s", binary_path, records);
  await(cmd);

  FILE* file = fopen(binary_path, "rb");
  char c;
  if (file == NULL) return 1;
  printf("Binary file saved to %s with the following contents:\n", binary_path);
  do {
    c = fgetc(file);
    printf("%c", c);
  } while (c != EOF);
  fclose(file);
  puts("");

  printf("Enter report path: ");
  scanf("%s", report_path);
  printf("Enter payment amount per hour: ");
  scanf("%lf", &hour_payment);
  puts("");
  sprintf(cmd, "build\\reporter.exe %s %s %lf", binary_path, report_path, hour_payment);
  await(cmd);

  return 0;
}

