#include <stdio.h>
#include <windows.h>


typedef struct {
  int num;
  char name[10];
  double hours;
} Employee;


int main(int argc, char** argv) {
  FILE* file = fopen(argv[1], "wb");
  int records = atoi(argv[2]);

  for (int i = 0; i < records; i++) {
    Employee e;
    printf("Employee #");
    scanf("%d", &e.num);
    printf("Name: ");
    scanf("%s", e.name);
    printf("Hours: ");
    scanf("%lf", &e.hours);
    printf("\n");
    fwrite(&e, sizeof(Employee), 1, file);
  }

  fclose(file);
  return 0;
}
