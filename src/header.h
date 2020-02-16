#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

typedef struct {
  int num;
  char name[10];
  double hours;
} Employee;

void await(char* cmd);

void cat(char* filename, char* mode);

