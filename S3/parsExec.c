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
  sprintf(buffer, "#parsExec arg1 [arg2 ... argn]\nEste programa necesita mínimo un usuario como argumento.\n");
  write(1, buffer, strlen(buffer));
}

int main(int argc,char *argv[]) {

    int pid, i;
    for (i = 0; i < 4; i++) {
      pid = fork();
      switch (pid) {
        case -1:
          error_y_exit("error en el fork", 1);
          break;
        case 0:
          if (i == 0)
            execlp("~/SO/S2/listaParametros", "listaParametros", "a", "b", (char *) 0);
          else if (i == 1)
            execlp("~/SO/S2/listaParametros", "listaParametros", "25", "4", (char *) 0);
          else if (i == 2)
            execlp("~/SO/S2/listaParametros", (char *) 0);
          else if (i == 3)
            execlp("~/SO/S2/listaParametros", "listaParametros", "1024", "hola", "adios", (char *) 0);
          error_y_exit("error en el execlp", 1);
        default:
          waitpid(-1, NULL, 0);
      }
    }
}
