#include <stdio.h>
#include <windows.h>


struct employee {
  int num;
  char name[10];
  double hours;
};


int main(int argc, char** argv) {
  printf("creator: started\n");

  const char* FILENAME = argv[1];
  const int RECORDS = atoi(argv[2]);

  printf("filename: %s\n", FILENAME);
  printf("number of records: %d\n", RECORDS);

  printf("creator: finished\n");
  return 0;
}

