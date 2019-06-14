#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

void error_y_exit(char* msg,int error_status) {
	perror(msg);
	exit(error_status);
}

int main() {
	char buf1[256];
	char buf2[256];
	int fp = open("salida.txt", O_RDWR);
	if(fp == -1) error_y_exit("error en abrir el archivo",1);
	lseek(fp,-1,SEEK_END);
	read(fp,buf1,sizeof(char));
	lseek(fp,-1,SEEK_CUR);
	sprintf(buf2,"X");

	write(fp,buf2,strlen(buf2));
	write(fp,buf1,strlen(buf1));
}
