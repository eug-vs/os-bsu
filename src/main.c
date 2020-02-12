#include <stdio.h>
#include <windows.h>


int main() {
  char* cmd = "build\\creator.exe filename 2";

  STARTUPINFO info = {sizeof(info)};
  PROCESS_INFORMATION processInfo;

  if (CreateProcess(NULL, cmd, NULL, NULL, TRUE, 0, NULL, NULL, &info, &processInfo)) {
    WaitForSingleObject(processInfo.hProcess, INFINITE);
  }
  else printf("Error while creating process!");

  return 0;
}

