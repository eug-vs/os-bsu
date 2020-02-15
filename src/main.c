#include "header.h"


int main() {
  char filename[64];
  char records[8];

  printf("Enter filename: ");
  scanf("%s", filename);
  printf("Enter records number: ");
  scanf("%s", records);
  printf("\n");

  char cmd[128] = "build\\creator.exe ";
  strcat(cmd, filename);
  strcat(cmd, " ");
  strcat(cmd, records);

  STARTUPINFO info = {sizeof(info)};
  PROCESS_INFORMATION processInfo;

  if (CreateProcess(NULL, cmd, NULL, NULL, TRUE, 0, NULL, NULL, &info, &processInfo)) {
    WaitForSingleObject(processInfo.hProcess, INFINITE);
  } else {
    printf("Error while creating process!");
    return 1;
  }

  FILE* file = fopen("data", "rb");
  char c;
  if (file == NULL) return 1;
  printf("Binary file saved to ./%s with the following contents:\n", filename);
  do {
    c = fgetc(file);
    printf("%c", c);
  } while (c != EOF);
  fclose(file);

  return 0;
}

