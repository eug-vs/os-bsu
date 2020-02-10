#include <stdio.h>
#include <windows.h>


typedef struct {
  int num;
  char name[10];
  double hours;
} employee;


int main(int argc, char** argv) {
  const char* FILENAME = argv[1];
  const int RECORDS = atoi(argv[2]);

  for (int i = 0; i < RECORDS; i++) {
    employee emp;
    printf("Employee #");
    scanf("%d", &emp.num);
    printf("Name: ");
    scanf("%s", emp.name);
    printf("Hours: ");
    scanf("%lf", &emp.hours);
    printf("\n");
  }

  printf("creator: finished\n");
  return 0;
}

