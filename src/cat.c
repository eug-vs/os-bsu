#include <stdio.h>

void cat(char* filepath, int is_binary) {
  char c;
  FILE* file;

  if ((file = fopen(filepath, is_binary? "rb" : "r"))) {
    do {
      c = fgetc(file);
      printf("%c", c);
    } while (c != EOF);
    printf("\n\n");
    fclose(file);
  } else puts("Error while reading file!");
}

