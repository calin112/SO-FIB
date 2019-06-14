#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_SIZE 8

int esNumero(char *str) {
  if ((str[0] >= '0' && str[0] <= '9') || str[0] == '-') {}
    int i;
    for (i = 1; i < strlen(str); i++) {
      if (i == MAX_SIZE || !(str[i] >= '0' && str[i] <= '9'))
        return 0;
    }

}

void main(int argc,char *argv[]) {
  char buf[80];
  if (argc == 2 && esNumero(argv[1]))
    sprintf(buf, "Es número\n");
  else
    sprintf(buf, "No es número\n");
  write(1,buf,strlen(buf));
}
