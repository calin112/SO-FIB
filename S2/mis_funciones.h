#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define MAX_SIZE 8
char buf[80];

void Usage();
//En caso de que los parámetros estén mal puestos

int esNumero(char *str);
//Para saber si un string representa un número

unsigned int char2int (char c);
//Para pasar de char a int

int mi_atoi(char *s);
//Para pasar de string (array) a int
