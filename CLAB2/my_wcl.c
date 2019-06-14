#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

char buff[256];
int ret;

void error_y_exit(char* msg, int error_status) {
	perror(msg);
	exit(error_status);
}

void Usage() {
  sprintf(buff, "Usage: ./my_wcl\n");
  ret = write(1,buff,strlen(buff));
  if (ret == -1)
    error_y_exit("write", 1);
}

int main(int argc,char *argv[]) {
  if (argc != 1)
    Usage();
  else {
    char c;
    int count = 0;
    while (ret = read(0, &c, sizeof(char)) > 0) {
      if (c == '\n')
        count++;
    }
    if (ret == -1)
      error_y_exit("read", 1);
    sprintf(buff, "El numero de lineas es %d\n", count);
    ret = write(1,buff,strlen(buff));
    if (ret == -1)
      error_y_exit("write", 1);
  }
}
