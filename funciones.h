#ifndef __FUNCIONES_H__
#define __FUNCIONES_H__
//ESTRUCTURAS

typedef int (*FuncionEvaluacion)(int *args);

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

typedef int (*FuncionEvaluacion)(int *args);

/*
Función para cargar los datos al árbol.
*/
Nodo* cargar(char *string);

/*

*/
void plantar(Bosque** tabla, Nodo* arbolito, char* operacion, char* nombre);

/*
Carga los distintos operadores disponibles en una lista.
*/
void cargar_operador(TablaOps** tabla, char* simbolo, int aridad, FuncionEvaluacion Eval);


//SALIDA

/*

*/
void salir(Bosque* tabla); 

/*
Funcion para liberar memoria. 
Recorre el arbol liberando la memoria reservada en cada nodo.
*/
void quemar_arbol(Nodo* raiz);

/*
Funcion para liberar memoria.
Recorre la lista simplemente enlanzada llamando a quemar_arbol()
Liberando las raices y la memoria de los chars.
*/
void quemar_bosque(Bosque* tabla);



//AUX

/*
Función para imprimir los datos en notacion infija.
*/
void imprimir(Nodo* raiz);

/*
Funcion para reordenar la cadena y leerla de atras para adelante.
Toma un string y devuelve las palabras en orden inverso, pero no invertidas.
*/
char* reordenada(char* string);

/*
Interpreta los comandos ingresados y los resuelve usando la tabla de operadores.
*/
void interpretar(TablaOps* tabla);

/*

*/
int alias_check(char* alias);

/*

*/
int op_check(char* operacion); 

/*

*/
char* cortar(char* string);

/*

*/
int op_alpha(char* operacion);

/*
Resuelve el arbol
*/
int evaluar(Nodo* raiz);

/*

*/
int bot(char* dato);

/*

*/
char* tolower_string(char* string);

/*

*/
char* reordenada(char* string);

/*

*/
Bosque* encontrar(Bosque* tabla, char* alias);
#endif





