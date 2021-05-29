#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Nodo* cargar(char *string){
  struct Nodo* newNodo;
  struct Nodo* raiz = malloc(sizeof(struct Nodo));

  char *token;
  char *temp = malloc(sizeof(char)* (strlen(string) + 1));
  temp = reordenada(string);
  
  token = strtok(temp, " ");

  raiz -> izq = NULL;
  raiz -> der = NULL;
  raiz -> dato = malloc(sizeof(char) * (strlen(token)+1));
  strcpy(raiz->dato, token);

  token = strtok (NULL, " ");

  while (token != NULL) {
    newNodo = malloc(sizeof(struct Nodo));
    newNodo -> izq = NULL;
    newNodo -> der = NULL;
    newNodo -> dato = malloc(sizeof(char) * (strlen(token)+1));
    strcpy(newNodo -> dato , token);

      if( strcmp(token, "%") == 0 || strcmp(token ,"--") == 0 ) {
        raiz -> izq = newNodo;
      }
      else {
        if ( raiz -> der == NULL) {
          raiz -> der = newNodo;
          newNodo = raiz;
        }
        else {
          raiz -> izq = newNodo;
          newNodo = raiz;
        }
      }
    token = strtok(NULL, " ");
  }
 
 return raiz;
}

void imprimir(struct Nodo* raiz) {   
  /* La wea in order, primero el sub arbol de la izq */
  if ( raiz -> izq != NULL )
    imprimir(raiz -> izq);

  /* luego el nodo actual. */
  printf(" %s ", raiz -> dato);

  /* Por ultimo del de la derecha */
  if ( raiz -> der != NULL )
    imprimir(raiz -> der);
}

int bot(char* dato){
  if(strcmp(dato,"+") == 0 || strcmp(dato,"-") == 0 || strcmp(dato,"/") == 0 ||
    strcmp(dato,"*") == 0 || strcmp(dato,"^") == 0 ){
      return 1;
  }
  return 0;
}

int check() {

}

char* reordenada(char* string) {
  int largo = strlen(string);
   
  char* newString = malloc(sizeof(char) * (largo + 1));
  char* temp1 = malloc(sizeof(char) * (largo + 1));
  char* temp2 = malloc(sizeof(char) * largo);
  
  strcpy(temp2,string);
  
  char* token;
  token = strtok(temp2, " ");
  strcpy(newString, "");
  
  while (token != NULL) {
    strcpy(temp1, "");
    strcat(temp1, token);
    strcat(temp1, " ");
    strcat(temp1, newString);

    strcpy(newString, temp1);
       
    token = strtok(NULL, " ");  
  }

  newString[largo + 1] = '\0';

  return newString;
}



/* deberiamos usar la funcion bot para comprobar que no haya mas de 2 numeros
consecutivos, ya que las operaciones son binarias como mucho, y eso llevaria a 
conflictos en la construccion del arbol mas adelante
*/
