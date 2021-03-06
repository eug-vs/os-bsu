#include <stdio.h>
#include <windows.h>

void await(char* cmd) {
  STARTUPINFO info = {sizeof(info)};
  PROCESS_INFORMATION processInfo;

  if (CreateProcess(NULL, cmd, NULL, NULL, TRUE, CREATE_NEW_CONSOLE, NULL, NULL, &info, &processInfo)) {
    WaitForSingleObject(processInfo.hProcess, INFINITE);
    CloseHandle(processInfo.hProcess);
  } else puts("Error while creating process!");
}

