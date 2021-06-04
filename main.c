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

  printf("Trabajo practico I, Estructura de Datos I\n");
  printf(" |.....................................| \n");
  printf("Powered by GlaDOS\n");

  TablaOps *tabla = NULL;

  Nodo* raiz = NULL;
  Bosque* l_arboles = NULL;

  Bosque* l_temp = NULL;

  char* input = malloc(sizeof(char)*500);
  char* token;
  
  cargar_operador(&tabla , "+" , 2 , suma);
  cargar_operador(&tabla , "-" , 2 , resta);
  cargar_operador(&tabla , "*" , 2 , producto);
  cargar_operador(&tabla , "/" , 2 , division);
  cargar_operador(&tabla , "%" , 1 , modulo);
  cargar_operador(&tabla , "--", 1 , opuesto);
  cargar_operador(&tabla , "^" , 2 , potencia);

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
      salir(l_arboles);
      free(token);
      free(input);
      free(l_temp);
      return 0; //modifique aca
    }
    else {
      if (strcmp(token, "evaluar") == 0) {
        token = strtok(NULL, " ");  //token = alias

        l_temp = encontrar(l_arboles, token);
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

          l_temp = encontrar(l_arboles, token);
          if(l_temp) {
            imprimir(l_temp -> raizOp); // modifique aca
          }
          else{
            printf("ALIAS < %s > no fue encontrado en la lista\n", token);
          }
          
        }
        else {
          char* temp = malloc(sizeof(char)*strlen(token));
          strcpy(temp, token);

          // mueve el token hasta despues del cargar
          // token = strtok(input, "=");
          // token = operacion
          token = strtok(NULL, "=");
          token = cortar(token);

          printf("OPERACION: %s\n", token); //juan = cargar 5 -- 13 + 2 7 * +

          //checkeo el alias
          if(alias_check(temp) == 1){
            printf("El Alias es una palabra reservada\n");
            while (alias_check(temp) == 1) {
              printf("Ingrese un nuevo alias> \n");
              fgets(temp, 50, stdin);
            }
          }
          // ya con alias y operacion llamo a la func que crea el arbol
          
          if (encontrar(l_arboles, temp)) {
            printf("El nodo ha sido encontrado en la tabla y sera sobreescrito.");
          }

          // cargo el string en el arbol
          Nodo* arb_t = cargar(token);

          // lo planto en el bosque. Go team trees
          plantar(&l_arboles, arb_t, token, temp);
          free(temp);
        }
      }
    }
  }    
}