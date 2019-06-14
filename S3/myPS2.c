#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

char buffer[128];

void error_y_exit(char *msg, int exit_status) {
  perror(msg);
  exit(exit_status);
}

void Usage() {
  sprintf(buffer, "#myPS2 arg1 [arg2 ... argn]\nEste programa necesita mínimo un usuario como argumento.\n");
  write(1, buffer, strlen(buffer));
}

void muta_a_PS(char *username) {
  execlp("ps", "ps", "-u", username, (char*)NULL);
  error_y_exit("Ha fallado la mutación al ps", 1);
}

int main(int argc,char *argv[]) {
  if (argc == 1) {
    Usage();
  }
  else {
    int i, pid;
    for (i=0; i < argc - 1; i++) {
      pid = fork();
      switch (pid) {
        case -1:
          error_y_exit("Error en fork", 1);
          break;
        case 0:
          sprintf(buffer, "Soy un hijo, mi PID es %d y el argumento es %s\n", getpid(), argv[1]);
          write(1, buffer, strlen(buffer));
          muta_a_PS(argv[1]);
          exit(0);
          break;
        default:
          sprintf(buffer, "Soy el padre y mi PID es %d\n", getpid());
          write(1, buffer, strlen(buffer));
          waitpid(-1, NULL, 0);
          break;
      }
    }
  }
}
