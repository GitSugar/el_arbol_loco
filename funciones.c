#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Nodo* cargar(char *string) {
  struct Nodo* newNodo;
  struct Nodo* raiz = malloc(sizeof(struct Nodo));

  char *token;
  char *temp = malloc(sizeof(char)* (strlen(string) + 1));
  strcpy(temp, revstring(string));

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
      printf("cossa rara pero con acento italiano\n");
    }
    else {
      strcpy(newNodo -> dato, token);
      if (raiz -> der == NULL) {
        raiz -> der = newNodo;
      }
      else {
        raiz -> izq = newNodo;
      }
    }
    token = strtok(NULL, " ");
  }

  return raiz;
}

char* revstring(char* string) {
  int len = strlen(string);
  char* rev = malloc( sizeof(char) * (strlen(string)) );
  
  for(int i = 0; i <= len ; i++){
    rev[i] = string[len - i -1];
  }
  
  rev[len + 1] = '\0';
  return rev;
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
