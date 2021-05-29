#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cargar(const char *string, Nodo *raiz) {
  /* Notacion postfija = izq der op */
  Nodo *newNodo;
  char *token = strtok(string, " ");
  
  /* Supongo entrada sanitizada. */
  /* Ejemplo: 5 -- 13 + 2 7 * + */
  
  while(token!=NULL) { 
    newNodo = malloc(sizeof(Nodo));
    newNodo -> izq = NULL;
    newNodo -> der = NULL;

    if (raiz == NULL) {
      newNodo -> dato = malloc(sizeof(char) * (strlen(token)+1));
      strcpy(newNodo -> dato, token);
      raiz = newNodo;
    }
    else {
      if( strcmp(token, "%") == 0 || strcmp("--") == 0 ) {
        newNodo->izq = raiz;
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

    token = strtok(NULL, s);
  }

  free(token);
}


void imprimir(Nodo *raiz) {   
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