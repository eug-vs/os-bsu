#include "header.h"

#define HEADLINE_TEMPLATE "Report for file: %s \n\n%-10s%-10s%-10s%-10s\n"
#define ROW_TEMPLATE "%-10d%-10s%-10g%-10g\n"


int main(int argc, char** argv) {
  FILE* file = fopen(argv[1], "rb");
  FILE* report = fopen(argv[2], "w+");
  double payment = strtod(argv[3], NULL);

  fprintf(report, HEADLINE_TEMPLATE, argv[1], "Id", "Name", "Hours", "Salary");

  Employee e;
  while(fread(&e, sizeof(Employee), 1, file)) {
    fprintf(report, ROW_TEMPLATE, e.id, e.name, e.hours, e.hours * payment);
  };

  fclose(file);
  fclose(report);
  return 0;
}

