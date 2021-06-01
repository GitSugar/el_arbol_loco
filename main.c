// gcc main.c funciones.c operadores.c -std=c99 -h funciones.h operadores.h -o a.out
// git commit -a -m "lcdsm all boys"
// git push

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funciones.h"
#include "operadores.h"

int main(int argc, char const *argv[]) {

  Nodo* raiz = NULL;
  TablaOps* tabla = NULL;

  char* input = malloc(sizeof(char)*500);
  char* token;
  
  printf("Trabajo practico I, Estructura de Datos I\n");
  printf(" |.....................................| ");
  printf("Powered by GlaDOS\n");

  while (f != 1){
    //Best menu LAS, gg jg papá.
    printf("Fucniones disponibles:\n");
    printf("\tcargar\n");
    printf("\timprimir\n");
    printf("\tevaluar\n");
    printf("\tsalir\n\n");

    printf("Aguardando input>");
    fgets(input, 500, stdin);
    
    token = strtok(input, " ");

    //The eternal IF statement.

    if (strcmp(token, "salir") == 0) {
      salir(tabla);
      break;
    }
    else {
      if (strcmp(token, "evaluar") == 0) {

        //pregunto que, y evaluo esa wea
        evaluar();
      }
      else {
        if (strcmp(token, "imprimir") == 0) {
          
          //pregunto que, e imprimo esa wea

          imprimir()
        }
        else {
          // aca se ingresa uvu
        }
      }
    }

  }    
  return 0;
}