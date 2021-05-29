#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
void cargar(char *string, struct Nodo* raiz) {
  //Notacion postfija = izq der op
  struct Nodo* newNodo;
  char *token;
  char *temp = malloc(sizeof(char)* (strlen(string) + 1));
  strcpy(temp, string);

  token = strtok(temp, " ");
  
  // Supongo entrada sanitizada.
  // Ejemplo: 5 -- 13 + 2 7 * + 

  while(token != NULL) { 
    if (raiz == NULL) {
      raiz = malloc(sizeof(struct Nodo));
      raiz -> der = NULL;
      raiz -> izq = NULL;
      raiz -> dato = malloc(sizeof(char) * (strlen(token)+1));
      strcpy(raiz -> dato, token);
    }
    else {
      newNodo = malloc(sizeof(struct Nodo));
      newNodo -> izq = NULL;
      newNodo -> der = NULL;
      newNodo -> dato = malloc(sizeof(char) * (strlen(token)+1));

      if( strcmp(token, "%") == 0 || strcmp(token ,"--") == 0 ) {
        newNodo -> izq = raiz;
        strcpy(newNodo -> dato, token);
        raiz = newNodo;
      }
      else {
        strcpy(newNodo -> dato, token);
        if ( raiz -> izq == NULL) {
          raiz -> izq = newNodo;
        }
        else {
          raiz -> der = newNodo;
        }
      }
    }
    printf("%s",raiz->dato);
    token = strtok(NULL, " ");
  }

  free(token);
  free(temp);
}
*/

struct Nodo* insert(char *string){
  struct Nodo* newNodo;
  struct Nodo* raiz = malloc(sizeof(struct Nodo));

  char *token;
  char *temp = malloc(sizeof(char)* (strlen(string) + 1));
  strcpy(temp, string);

  token = strtok(temp, " ");
  raiz -> dato = malloc(sizeof(char) * (strlen(token)+1));
  strcpy(raiz->dato, token);

  raiz -> izq = NULL;
  raiz -> der = NULL;

  token = strtok (NULL, " ");

  while (token != NULL) {
    newNodo = malloc(sizeof(struct Nodo));
    newNodo -> izq = NULL;
    newNodo -> der = NULL;
    newNodo -> dato = malloc(sizeof(char) * (strlen(token)+1));

      if( strcmp(token, "%") == 0 || strcmp(token ,"--") == 0 ) {
        newNodo -> izq = raiz;
        strcpy(newNodo -> dato, token);
        raiz = newNodo;
      }
      else {
        strcpy(newNodo -> dato, token);
        if ( raiz -> izq == NULL) {
          raiz -> izq = newNodo;
        }
        else {
          raiz -> der = newNodo;
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


int main(int argc, char const *argv[]) {
  //La concha de tu madre all boys
  return 0;
}