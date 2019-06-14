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
  sprintf(buff, "Usage: ./cuantaslineas arg1 arg2\n");
  write(1,buff,strlen(buff));
  if (ret == -1)
    error_y_exit("write", 1);
}

int main(int argc,char *argv[]) {
  if (argc != 3)
    Usage();
  else {
    int p[2];
    pipe(p);
    int pid = fork();
    if (pid == 0) {
      dup2(p[1], 1);
      close(p[0]); close(p[1]);
      ret = execlp("grep", "grep", argv[1], argv[2], (char *) NULL);
      if (ret == 0)
        error_y_exit("execlp", 1);
    }
    pid = fork();
    if (pid == 0) {
      dup2(p[0], 0);
      close(p[0]); close(p[1]);
      ret = execlp("wc", "wc", "-l", (char *) NULL);
    }
    close(p[0]);
    while (waitpid(-1, NULL, 0) > 0);
  }
}
