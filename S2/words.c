#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
char buffer[128];

void Usage() {
  sprintf(buffer, "#words arg1\nEste programa cuenta el número de palabras que hay en el primer argumento.\n");
  write(1, buffer, strlen(buffer));
}

int main(int argc, char *argv[]) {
  int count = 1;
  if (argc < 2)
    Usage();
  else {
    int n = strlen(argv[1]), i;
    char *c = argv[1];
    for (i = 0; i < n; i++) {
      if (*c == ' ') {
        c++;
        if (*c != ' ' && *c != '.' && *c != '\n')
          count++;
      }
      else
        c++;
    }
    sprintf(buffer, "%d palabras\n", count);
    write(1, buffer, strlen(buffer));
  }
}
