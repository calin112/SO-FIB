#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

#define SYSCALL_ERROR 1

char buf[256];
int ITERACION_ACTUAL;

void usage() {
        sprintf(buf, "usage: ./calcular arg1 arg2 arg3\n");
        write(1,buf,strlen(buf));
}

void error_y_exit(char *msg, int exit_status)
{
    perror(msg);
    exit(exit_status);
}

// Esta funcion no es relevante, solo pierde tiempo
void calcula(int i)
{
	int it;
	int fd;
	for (it=0;it<i;it++){
		fd=open("F",O_WRONLY|O_CREAT|O_TRUNC,S_IRWXU);
		if (fd<0){
			perror("Error en el open");
			exit(SYSCALL_ERROR);
		}
		write(fd,&it,sizeof(it));
		close(fd);
	}
}

void funcion_sigusr1(int signal)
{
	sprintf(buf,"Iteración actual: %d\n",ITERACION_ACTUAL);
	write(1, buf, strlen(buf) );
}

void funcion_sigalrm(int signal)
{
	sprintf(buf,"El tiempo se ha acabado\n");
	write(1, buf, strlen(buf) );
	exit(1);
}

void main(int argc,char *argv[])
{
	if (argc != 4)
		usage();
	else {
		int i, ITERACIONES_MAIN = atoi(argv[1]), ITERACIONES_CALCULA = atoi(argv[2]), TIEMPO = atoi(argv[3]);
		struct sigaction sa;
    sigset_t mask;

    /* EVITAMOS TRATAR EL SIGUSR1 FUERA DEL SIGSUSPEND */

    sigemptyset(&mask);
    sigaddset(&mask, SIGUSR1);
		sigaddset(&mask, SIGALRM);
    sigprocmask(SIG_BLOCK,&mask, NULL);

    /* REPROGRAMAMOS EL SIGNAL SIGUSR1 */
    sa.sa_handler = &funcion_sigusr1;
    sa.sa_flags = SA_RESTART;
    sigfillset(&sa.sa_mask);

    if (sigaction(SIGUSR1, &sa, NULL) < 0) error_y_exit("sigaction", 1);

		/* REPROGRAMAMOS EL SIGNAL SIGALRM */
    sa.sa_handler = &funcion_sigalrm;
    sa.sa_flags = SA_RESTART;
    sigfillset(&sa.sa_mask);

    if (sigaction(SIGALRM, &sa, NULL) < 0) error_y_exit("sigaction", 1);
		char b[128];
		sigemptyset(&mask);
		sigaddset(&mask, SIGUSR1);
		sigaddset(&mask, SIGALRM);
		sigaddset(&mask, SIGINT);
		sigprocmask(SIG_UNBLOCK,&mask, NULL);
		alarm(TIEMPO);
		for (i=0;i<ITERACIONES_MAIN;i++){
			ITERACION_ACTUAL=i;
			calcula(ITERACIONES_CALCULA);
		}
	}
}
