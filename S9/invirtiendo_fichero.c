#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

void Usage() {
	char[256] buff;
	sprintf(buff, "Usage: inviertiendo_fichero arg1\n Este comando invierte el fichero arg1 y lo guarda en arg1.inv\n");
	exit(0);
}

void error_y_exit(char* msg, int error_status) {
	perror(msg);
	exit(error_status);
}

int main(int argc, const char* argv[]) {
  char buff;
	if (argc != 2)
		Usage();
  int fd = open(argv[1], O_RDWR|O_CREAT|O_TRUNC);
	int fd = open("file", O_RDWR);
  if (fd == -1)
    error_y_exit("open", 1);
  int end = lseek(fd, 0, SEEK_END);
  int i = lseek(fd, 0, SEEK_SET);
  while (i < end) {
    read(fd, &buff, sizeof(char));
    i++;
    lseek(fd, 0, SEEK_END);
    write(fd, &buff, sizeof(char));
    lseek(fd, i, SEEK_SET);
  }
}
