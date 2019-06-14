#include "mis_funciones.h"

void main(int argc,char *argv[]) {
  int i, b = 1, suma = 0;
  if (argc <= 2)
    Usage();
  else {
    for (i = 1; i < argc; i++) {
      if (esNumero(argv[i]))
        suma += mi_atoi(argv[i]);
      else {
        sprintf(buf, "Error: el parámetro ""%s"" no es número\n", argv[i]);
        b = 0;
        break;
      }
    }
    if (b)
    	sprintf(buf, "La suma es %d\n", suma);
    write(1, buf, strlen(buf));
  }
}
