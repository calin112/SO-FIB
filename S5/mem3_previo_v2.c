#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>

#define REGION_SIZE		4096

int *p;

char buff[256];

void error_y_exit(char *msg,int exit_status)
{
    perror(msg);
    exit(exit_status);
}

void funcion_sigsegv(int s)
{
    sprintf(buff, "Error! violación de segmento!\n");
    write(1, buff, strlen(buff));
		exit(1);
}

int main(int argc, char *argv[])
{

	struct sigaction sa;
	sigset_t mask;

	sigemptyset(&mask);
	sigaddset(&mask, SIGSEGV);
	sigprocmask(SIG_BLOCK,&mask, NULL);

	/* REPROGRAMAMOS EL SIGNAL SIGALRM */
	sa.sa_handler = &funcion_sigsegv;
	sa.sa_flags = SA_RESTART;
	sigfillset(&sa.sa_mask);

	if (sigaction(SIGSEGV, &sa, NULL) < 0) error_y_exit("sigaction", 1);

	sigemptyset(&mask);
  sigaddset(&mask, SIGSEGV);
	sigaddset(&mask, SIGINT);
  sigprocmask(SIG_UNBLOCK,&mask, NULL);

	sprintf( buff, "Addresses:\n");
	write(1, buff, strlen(buff));
	sprintf( buff, "\tp: %p\n", &p);
	write(1, buff, strlen(buff));

	*p = 5;

	sprintf( buff, "\tp Address: %p, p value: %p, *p: %d\n", &p, p, *p);
	write(1, buff, strlen(buff));

	exit(0);

}
