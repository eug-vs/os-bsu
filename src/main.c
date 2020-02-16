#include "header.h"


void await(char* cmd) {
  STARTUPINFO info = {sizeof(info)};
  PROCESS_INFORMATION processInfo;

  if (CreateProcess(NULL, cmd, NULL, NULL, TRUE, 0, NULL, NULL, &info, &processInfo)) {
    WaitForSingleObject(processInfo.hProcess, INFINITE);
  } else puts("Error while creating process!");
}

void cat(char* filepath, int is_binary) {
  char c;
  FILE* file;

  if ((file = fopen(filepath, is_binary? "rb" : "r"))) {
    do {
      c = fgetc(file);
      printf("%c", c);
    } while (c != EOF);
    printf("\n\n");
    fclose(file);
  } else puts("Error while reading file!");
}


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
  sprintf(cmd, "build\\creator.exe %s %s", binary, records);
  await(cmd);
  printf("Binary file saved to \"%s\" with the following contents:\n", binary);
  cat(binary, 1);

  printf("Enter report filename: ");
  scanf("%s", report);
  printf("Enter payment amount per hour: ");
  scanf("%lf", &payment);
  puts("");
  sprintf(cmd, "build\\reporter.exe %s %s %lf", binary, report, payment);
  await(cmd);
  printf("Report saved to \"%s\" with the following contents:\n", report);
  cat(report, 0);

  return 0;
}

