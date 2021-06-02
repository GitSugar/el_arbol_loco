#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

Nodo* cargar(char *string){
  Nodo* newNodo;
  Nodo* raiz = malloc(sizeof(struct Nodo));

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

void imprimir(Nodo* raiz) {   
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

void quemar_arbol(Nodo* raiz) {

  if ( raiz -> izq != NULL ) {
    quemar_bosque(raiz -> izq);
  }

  free(raiz -> dato);

  if(raiz -> der != NULL) {
    quemar_bosque(raiz -> der);
  }
  else {
    free(raiz);
  }
}

void quemar_bosque(TablaOps* Tabla) {
  if ( Tabla -> sig != NULL )
    quemar_bosque(Tabla -> sig);
  
  free(Tabla -> alias);
  free(Tabla -> operacion);
  quemar_arbol(Tabla -> raizOp);
  free(Tabla);
}

void salir(TablaOps* Tabla) {

  printf("Saliendo del programa.\n");
  printf("Liberando datos...\n");

  quemar_bosque(Tabla);

  printf("Datos Liberados!\n");
  printf("Gracias, vuelva prontos\n");
}

char* tolower_string(char* string) {
  for(int i = 0; string[i] != '\0'; i++) {
    string[i] = tolower(string[i]);
  }
  return string;
}

int alias_check(char* alias) {
  char* temp = tolower_string(alias);
  return (strcmp(temp, "cargar") == 0 || strcmp(temp, "imprimir") == 0 || strcmp(temp, "salir") == 0 || strcmp(temp, "evaluar") == 0);}


int op_check(char* operacion) {
  return (isalpha(operacion[0]) || isdigit(operacion[0]));
}

int op_alpha(char* operacion) {
  for(int i = 0; operacion[i] != '\0'; i++) {
    if (isalpha(operacion[i])) {
      return 1;
    }
  }
  return 0;
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

int evaluar(struct Nodo raiz){

}

  

/* deberiamos usar la funcion bot para comprobar que no haya mas de 2 numeros
consecutivos, ya que las operaciones son binarias como mucho, y eso llevaria a 
conflictos en la construccion del arbol mas adelante
*/
