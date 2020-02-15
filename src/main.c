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
  char filepath[64];
  char records[8];
  double hour_payment;
  char cmd[128];


  printf("Enter binary file path: ");
  scanf("%s", filepath);
  printf("Enter records number: ");
  scanf("%s", records);
  puts("");
  sprintf(cmd, "build\\creator.exe %s %s", filepath, records);
  await(cmd);

  FILE* file = fopen("data", "rb");
  char c;
  if (file == NULL) return 1;
  printf("Binary file saved to %s with the following contents:\n", filepath);
  do {
    c = fgetc(file);
    printf("%c", c);
  } while (c != EOF);
  fclose(file);
  puts("");

  return 0;
}

