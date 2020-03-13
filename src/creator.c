#include <stdio.h>
#include <stdlib.h>
#include "employee.h"

int main(int argc, char** argv) {
  FILE* file = fopen(argv[1], "wb+");
  int records = atoi(argv[2]);

  for (int i = 0; i < records; i++) {
    Employee e;
    printf("Employee #");
    scanf("%d", &e.id);
    printf("Name: ");
    scanf("%s", e.name);
    printf("Hours: ");
    scanf("%lf", &e.hours);
    puts("");
    fwrite(&e, sizeof(Employee), 1, file);
  }

  fclose(file);
  return 0;
}

