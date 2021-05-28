#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cargar(const char *string, Nodo *raiz) {
    /* Notacion postfija = izq der op */
    Nodo *newNodo;

    /* Supongo entrada sanitizada. */
    /* Ejemplo: 5 -- 13 + 2 * 7 + */
    


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