#include <unistd.h>
#include <string.h>
#include <stdio.h>

main(){
int numero = 10562;
int fd;
char buf[128];
read(0, &numero, sizeof(int));
sprintf(buf, "%d\n", numero);
write(1, buf, strlen(buf));
}
