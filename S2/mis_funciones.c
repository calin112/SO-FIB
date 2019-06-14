#include "mis_funciones.h"

void Usage() {
  sprintf(buf, "Usage: suma arg1 arg2 [arg3...argn]\n");
  write(1,buf,strlen(buf));
  sprintf(buf, "Este programa escribe por su salida la suma de los números enteros que recibe\n");
  write(1,buf,strlen(buf));
}

int esNumero(char *str) {
//printf("%s\n", str);

  if (((str[0] >= '0') && (str[0] <= '9')) || str[0] == '-') {
    int i;
    for (i = 1; i < strlen(str); i++) {
      if (i == MAX_SIZE || !((str[i] >= '0') && (str[i] <= '9')))
        return 0;
    }
    return 1;
  }
  return 0;
}

unsigned int char2int (char c) {
  return (c - '0');
}

int mi_atoi(char *s) {
  int numero = 0, i, multi = 1;
  if (s[0] == '-') {
    for(i = strlen(s) - 1; i >= 1; i--) {
      numero += char2int(s[i]) * multi;
      multi *= 10;
    }
    numero *= -1;
  }
  else {
    for (i = strlen(s) - 1; i >= 0; i--) {
      numero += char2int(s[i]) * multi;
      multi *= 10;
    }
  }
  return numero;
}
