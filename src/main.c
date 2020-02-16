#include "header.h"


void await(char* cmd) {
  STARTUPINFO info = {sizeof(info)};
  PROCESS_INFORMATION processInfo;

  if (CreateProcess(NULL, cmd, NULL, NULL, TRUE, 0, NULL, NULL, &info, &processInfo)) {
    WaitForSingleObject(processInfo.hProcess, INFINITE);
  } else puts("Error while creating process!");
}

void cat(char* filepath, char* mode) {
  char c;
  FILE* file;

  if ((file = fopen(filepath, mode))) {
    do {
      c = fgetc(file);
      printf("%c", c);
    } while (c != EOF);
    fclose(file);
    puts("");
  } else puts("Error while reading file!");
}


int main() {
  char cmd[256];
  char binary_path[64];
  char report_path[64];
  char records[8];
  double hour_payment;

  printf("Enter binary file path: ");
  scanf("%s", binary_path);
  printf("Enter records number: ");
  scanf("%s", records);
  puts("");
  sprintf(cmd, "build\\creator.exe %s %s", binary_path, records);
  await(cmd);
  printf("Binary file saved to \"%s\" with the following contents:\n", binary_path);
  cat(binary_path, "rb");

  puts("");

  printf("Enter report path: ");
  scanf("%s", report_path);
  printf("Enter payment amount per hour: ");
  scanf("%lf", &hour_payment);
  puts("");
  sprintf(cmd, "build\\reporter.exe %s %s %lf", binary_path, report_path, hour_payment);
  await(cmd);
  printf("Report saved to \"%s\" with the following contents:\n", report_path);
  cat(report_path, "r");

  return 0;
}

