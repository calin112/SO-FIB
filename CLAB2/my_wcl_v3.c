#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


char buff[256];
int ret;

void error_y_exit(char* msg, int error_status) {
	perror(msg);
	exit(error_status);
}

void Usage() {
  sprintf(buff, "Usage: ./my_wcl_v3 arg1 arg2\n");
  write(1,buff,strlen(buff));
  if (ret == -1)
    error_y_exit("write", 1);
}

int main(int argc,char *argv[]) {
  if (argc != 3)
    Usage();
  else {
    int fd = open(argv[1], O_RDONLY);
    if (fd == -1)
      error_y_exit("open1", 1);
    int fd2 = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (fd2 == -1)
      error_y_exit("open2", 1);
    dup2(fd, 0);
    close(fd);
    dup2(fd2, 1);
    close(fd2);
    char c[32];
    int count = 0;
    while (ret = read(0, &c, 32) > 0) {
      int n = strlen(c), i;
      for (i = 0; i < n; i++)
        if (c[i]=='\n')
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
