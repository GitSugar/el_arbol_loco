#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cargar(const char *string, Nodo *Operador) {
    /* Notacion postfija = izq der op */

    Nodo *newNodo;
    /* Supongo entrada sanitizada y sin espacios. */
    for (int i=0; i<strlen(string); i++) {
      
    }


}


void imprimir(Nodo *Operador) {   
    /* La wea in order, primero el sub arbol de la izq */
    if ( Operador -> izq != NULL )
        imprimir(Operador -> izq);

    /* luego el nodo actual. */
    printf(" %s ", Operador -> dato);

    /* Por ultimo del de la derecha */
    if ( Operador -> der != NULL )
        imprimir(Operador -> der);
}

int main(int argc, char const *argv[]) {
  //La concha de tu madre all boys
  return 0;
}