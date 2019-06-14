#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>


char buff[256];
int ret;

void error_y_exit(char* msg, int error_status) {
	perror(msg);
	exit(error_status);
}

void Usage() {
  sprintf(buff, "Usage: ./1deN\n");
  write(1,buff,strlen(buff));
  if (ret == -1)
    error_y_exit("write", 1);
}

int main(int argc,char *argv[]) {
  if (argc != 2)
    Usage();
  else {
    char c;
    int x, y = atoi(argv[1]);
    while (read(0, &c, sizeof(char)) > 0) {
      if (c != ' ') {
        x = atoi(c);
        if (x % )
      }
    }
  }
}
