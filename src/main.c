#include "header.h"


int main() {
  char filename[64];
  char records[8];

  printf("Enter filename: ");
  scanf("%s", filename);
  printf("Enter records number: ");
  scanf("%s", records);

  char cmd[128] = "build\\creator.exe ";
  strcat(cmd, filename);
  strcat(cmd, " ");
  strcat(cmd, records);

  STARTUPINFO info = {sizeof(info)};
  PROCESS_INFORMATION processInfo;

  if (CreateProcess(NULL, cmd, NULL, NULL, TRUE, 0, NULL, NULL, &info, &processInfo)) {
    WaitForSingleObject(processInfo.hProcess, INFINITE);
  }
  else printf("Error while creating process!");

  FILE* file = fopen("data", "rb");
  if (file == NULL) return 1;
  for (int i = 0; i < atoi(records); i++){
    Employee e;
    fread(&e, sizeof(Employee), 1, file);
    printf("Employee #%d\n", e.num);
    printf("Name: %s\n", e.name);
    printf("Hours: %lf\n", e.hours);
    printf("\n");
  }
  fclose(file);

  return 0;
}

