#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>


char buf[256];

void usage() {
        sprintf(buf, "usage: mstat nomfitxer1 [nom_fitxer2.. nom_fitxerN]\n");
        write(1,buf,strlen(buf));
}

void error_y_exit(char *msg, int exit_status)
{
    perror(msg);
    exit(exit_status);
}

int main(int argc,char *argv[]) {
  int i, res, pid, exec, extstat;
  if (argc == 1)
    usage();
  else {
    for (i = 1; i < argc; i++) {

      switch (fork()) {
        case -1:
          error_y_exit("Error en el fork\n", 1);
        case 0:
          sprintf(buf, "Ejecutamos el comando stat del fichero %s\n", argv[i]);
          write(1,buf,strlen(buf));
          exit(0);
        default:
          pid = waitpid(-1, &res, 0);
          if (pid == -1)
            error_y_exit("error en waitpid", 1);
          else {
            extstat = WEXITSTATUS(res);
            if (!extstat) {
              sprintf(buf, "stat ejecutado correctamente\n");
              write(1,buf,strlen(buf));
            }
            else if (extstat) {
              sprintf(buf, "stat ha detectado un problema con el fichero\n");
              write(1,buf,strlen(buf));
            }
          }
      }
    }
  }
}
