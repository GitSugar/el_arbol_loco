// gcc main.c funciones.c operadores.c -std=c99 -h funciones.h operadores.h -o a.out
// git commit -a -m "lcdsm all boys"
// git push

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funciones.h"
#include "operadores.h"

int main(int argc, char const *argv[]) {

  

//modifique aca: hay que pasar todo esto a una funcion void interpretar(tablaOps *tabla)


  Nodo* raiz = NULL;
  bosque* tabla = NULL;

  char* input = malloc(sizeof(char)*500);
  char* token;
  
  printf("Trabajo practico I, Estructura de Datos I\n");
  printf(" |.....................................| ");
  printf("Powered by GlaDOS\n");

  while (f != 1){
    //Best menu LAS, gg jg papÃ¡.
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
      free(token);
      free(input);
      return 0; //modifique aca
    }
    else {
      if (strcmp(token, "evaluar") == 0) {
        token = strtok(NULL, " ");
        evaluar(token); //modifique aca
      }
      else {
        if (strcmp(token, "imprimir") == 0) {
          token = strtok(NULL, " ");
          imprimir(token); // modifique aca
        }
        else {
          char* temp = malloc(sizeof(char)*strlen(token));
          strcpy(temp,token);

          //mueve el token hasta despues del cargar
          token = strtok(NULL, " "); // =
          token = strtok(NULL, " "); // cargar
          token = strtok(NULL, " "); // la wea operaica

          bosque newNodo = malloc(sizeof(bosque));
          struct Nodo *nuevaRaiz = NULL;
          newNodo->sig = NULL;

          if(alias_check(temp) == 1){
            printf("El Alias es una palabra reservada\n");
            while (alias_check(temp) == 1) {
              printf("Ingrese un nuevo alias> \n");
              fgets(temp, 50, stdin);
            }
          }
          strcpy(newNodo-> alias, temp);


          //modifique aca : necesitamos comprobar el primer elemento del alias, si es numero o no
          newNodo->raizOp = nuevaRaiz;
          
          //comprobar si es numero o no la operacion en token.

          strcpy(newNodo -> operacion , token);
          nuevaRaiz = cargar(token);

          free(temp);
          }
      }
    }

  }    
  //modifique aca
}