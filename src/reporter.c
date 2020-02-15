#include "header.h"

#define HEADLINE_TEMPLATE "Report for file %s\n"


int main(int argc, char** argv) {
  FILE* file = fopen(argv[1], "rb");
  FILE* report = fopen(argv[2], "w+");
  double hour_payment = strtod(argv[3], NULL);

  fprintf(report, HEADLINE_TEMPLATE, argv[1]);

  fclose(file);
  fclose(report);
  return 0;
}

