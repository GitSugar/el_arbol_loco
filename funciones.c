#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "operadores.h"

/*
Estructura basica para un árbol.
Contiene nodo Izq, nodo Der y el contenido.
*/
typedef struct NODO {
  struct NODO *izq;
  struct NODO *der;
  int flag;
  char* dato;
}Nodo;

/*
Estructura para Guardar los Aliases.
Contiene un puntero al siguiente elemento.
Nombre, operacion y el arbol donde se guarda.
*/
typedef struct BOSQUE {
  char* alias;
  char* operacion;
  struct BOSQUE *sig;
  struct NODO *raizOp;
}Bosque;

/*
Estructura para almacenar las operaciones.
*/
typedef struct TABLAOPS {
  struct TABLAOPS *sig;
  char* simbolo;
  int aridad;
  FuncionEvaluacion* eval;
}TablaOps;


char* tolower_string(char* string) {
  for(int i = 0; string[i] != '\0'; i++) {
    string[i] = tolower(string[i]);
  }
  return string;
}

int alias_check(char* alias) {
  char* temp = tolower_string(alias);
  return (strcmp(temp, "cargar") == 0 || strcmp(temp, "imprimir") == 0 || strcmp(temp, "salir") == 0 || strcmp(temp, "evaluar") == 0);
}

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

Bosque* encontrar(Bosque* tabla, char* alias) {
  Bosque* temp = tabla;

  while(strcmp(alias, temp -> alias) != 0) {
    temp = temp -> sig;
  }
  return temp;
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

int bot(char* dato) {
  if(strcmp(dato,"+") == 0 || strcmp(dato,"-") == 0 || strcmp(dato,"/") == 0 ||
    strcmp(dato,"*") == 0 || strcmp(dato,"^") == 0 ){
    return 1;
  }
  return 0;
}

int evaluar(Nodo* raiz) {
  printf("UWU");
}

char* cortar(char* string) {
  int ctr = 0;
  int flag = 1;
  while (flag == 1){
    ctr++;
    if(string[ctr] == 'r' && ctr >= 4){
      flag = 0;
    }
  }
  char* newString = malloc(sizeof(char) * (strlen(string) - ctr));

  for(int i = 0; string[i] != '\0'; i++){
    newString[i] = string[ctr + 2 + i];
  }

  return newString;
}


Nodo* cargar(char *string) {
  Nodo* newNodo;
  Nodo* raiz = malloc(sizeof(Nodo));

  char *token;
  char *temp = reordenada(string);
  
  token = strtok(temp, " ");

  raiz -> izq = NULL;
  raiz -> der = NULL;
  raiz -> dato = malloc(sizeof(char) * (strlen(token)+1));
  strcpy(raiz->dato, token);

  token = strtok (NULL, " ");

  while (token != NULL) {
    newNodo = malloc(sizeof(Nodo));
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

void plantar(Bosque** tabla, Nodo* arbolito, char* operacion, char* nombre) {
  //creo un nuevo elemento

  Bosque* ult = NULL;

  Bosque* newItem = malloc(sizeof(Bosque));

  newItem -> alias = malloc(sizeof(char) * strlen(nombre));
  newItem -> operacion = malloc(sizeof(char) * strlen(operacion));
  newItem -> raizOp = malloc(sizeof(Nodo));
  newItem -> sig = NULL;

  if(*tabla == NULL) {
    *tabla = newItem;
  }
  else {
    ult = *tabla;
    while(ult -> sig) {
      ult = ult -> sig;
    }
    ult -> sig = newItem;
  }
}

void cargar_operador(TablaOps** tabla , char* simbolo , int aridad , FuncionEvaluacion eval) {
  TablaOps *newItem = malloc(sizeof(TablaOps));
  
  newItem -> simbolo = malloc(sizeof(char) * (strlen(simbolo) + 1)); 
  strcpy(newItem -> simbolo , simbolo);
  newItem -> aridad = aridad;
  newItem -> eval = &eval;
  newItem -> sig = NULL;
  
  if(*tabla != NULL) {
    newItem -> sig = *tabla;
  }
  *tabla = newItem;
}


void quemar_arbol(Nodo* raiz) {

  if ( raiz -> izq != NULL ) {
    quemar_arbol(raiz -> izq);
  }

  free(raiz -> dato);

  if(raiz -> der != NULL) {
    quemar_arbol(raiz -> der);
  }
  else {
    free(raiz);
  }
}

void quemar_bosque(Bosque* tabla) {
  if (tabla -> sig != NULL)
    quemar_bosque(tabla -> sig);
  
  free(tabla -> alias);
  free(tabla -> operacion);
  quemar_arbol(tabla -> raizOp);
  free(tabla);
}

void salir(Bosque* tabla) {

  printf("Saliendo del programa.\n");
  printf("Liberando datos...\n");

  quemar_bosque(tabla);

  printf("Datos Liberados!\n");
  printf("Gracias, vuelva prontos\n");
}

/* deberiamos usar la funcion bot para comprobar que no haya mas de 2 numeros
consecutivos, ya que las operaciones son binarias como mucho, y eso llevaria a 
conflictos en la construccion del arbol mas adelante
*/
