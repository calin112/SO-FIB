#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void error_y_exit(char* msg,int error_status) {
	perror(msg);
	exit(error_status);
}

int main() {
	char buf[256];
	int f = creat("salida.txt", 0600);
	if(f == -1)
		error_y_exit("creat", 1);
	sprintf(buf,"ABCD");
	write(f,buf,strlen(buf));
}
