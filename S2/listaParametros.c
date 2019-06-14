#include <stdio.h>
#include <string.h>
#include <unistd.h>

char buf[80];

void Usage() {
        sprintf(buf, "Usage: listaParametros arg1 [arg2...argn]\n");
        write(1,buf,strlen(buf));
        sprintf(buf, "Este programa escribe por su salida la lista de argumentos que recibe\n");
        write(1,buf,strlen(buf));
}

void main(int argc,char *argv[]) {
	int i;
	if (argc == 1)
		Usage();
	else
		for (i=0;i<argc;i++){
			if (i==0){
				sprintf(buf,"El argumento %d es %s (es el nombre del ejecutable)\n",i,argv[i]);
			}
			else{
				sprintf(buf,"El argumento %d es %s\n",i,argv[i]);
			}
			write(1,buf,strlen(buf));
		}
}
