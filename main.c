// gcc main.c funciones.c operadores.c -std=c99 -o a.out
// git commit -a -m "lcdsm all boys"
// git push

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Incluyo las librerias donde estan definidas las funciones.
//Luego compilo con los .c donde esta el codigo.
#include "funciones.h"
#include "operadores.h"

int main(int argc, char const *argv[]) {
//modifique aca: hay que pasar todo esto a una funcion void interpretar(tablaOps *tabla)

  Nodo* raiz = NULL;
  Bosque* tabla = NULL;

  Bosque* l_temp = NULL;

  char* input = malloc(sizeof(char)*500);
  char* token;
  
  printf("Trabajo practico I, Estructura de Datos I\n");
  printf(" |.....................................| ");
  printf("Powered by GlaDOS\n");

  while(1) {
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
      free(l_temp);
      return 0; //modifique aca
    }
    else {
      if (strcmp(token, "evaluar") == 0) {
        token = strtok(NULL, " ");

        l_temp = encontrar(tabla, token);
        if(l_temp) {
          evaluar(l_temp -> raizOp); //modifique aca
        }
        else{
          printf("ALIAS < %s > no fue encontrado en la lista\n", token);
        }
        
      }
      else {
        if (strcmp(token, "imprimir") == 0) {
          token = strtok(NULL, " ");

          l_temp = encontrar(tabla, token);
          if(l_temp) {
            imprimir(l_temp -> raizOp); // modifique aca
          }
          else{
            printf("ALIAS < %s > no fue encontrado en la lista\n", token);
          }
          
        }
        else {
          char* temp = malloc(sizeof(char)*strlen(token));
          strcpy(temp,token);

          //mueve el token hasta despues del cargar
          token = strtok(NULL, " "); // =
          token = strtok(NULL, " "); // cargar
          token = strtok(NULL, " "); // la wea operaica

          //checkeo el alias
          if(alias_check(temp) == 1){
            printf("El Alias es una palabra reservada\n");
            while (alias_check(temp) == 1) {
              printf("Ingrese un nuevo alias> \n");
              fgets(temp, 50, stdin);
            }
          }
          // ya con alias y operacion llamo a la func que crea el arbol
          
          if (encontrar(tabla, temp)) {
            printf("El nodo ha sido encontrado en la tabla y sera sobreescrito.");
          }

          // cargo el string en el arbol
          Nodo* arb_t = cargar(token);

          // lo planto en el bosque. Go team trees
          plantar(*tabla, arb_t, token, temp);
          free(temp);
        }
      }
    }
  }    
}