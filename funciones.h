#ifndef __FUNCIONES_H__
#define __FUNCIONES_H__
	
	/*
	Estructura basica para un árbol.
	Contiene nodo Izq, nodo Der y el contenido.
	No pidas mas.
	*/
	typedef struct NODO {
		Nodo *izq;
	  Nodo *der;
	  int flag;
	  char* dato;
	}Nodo;

	/*
	Estructura para Guardar los Aliases
	Contiene Lista Simplemente Enlazada
	Nombre, operacion y el arbol donde se guarda.
	*/
	typedef struct BOSQUE {
		char* alias;
		char* operacion;
		bosque *sig;
		Nodo *raizOp;
	}Bosque;

	/*
	Estructura para almacenar las operaciones.
	*/
	typedef struct TABLAOPS {
		tablaops *sig;
		char* simbolo;
		int aridad;
		FuncionEvaluacion* eval;
	}tablaOps;

	/*
	Funcion para reordenar la cadena y leerla de atras para adelante.
	*/
	char* reordenada(char* string);

	void quemar_arbol(Nodo* raiz);

	void quemar_bosque(Bosque* bosque);

	/*
	Función para cargar los datos al árbol.
	*/
	void cargar(char* string, Nodo* raiz);

	/*
	Función para imprimir los datos en notacion infija.
	*/
	void imprimir(Nodo* raiz);

	/*
	Carga los distintos operadores disponibles en una lista.
	*/
	void cargar_operador(tablaOps* tabla, char* simbolo, int aridad, FuncionEvaluacion Eval);

	/*
	Interpreta los comandos ingresados y los resuelve usando la tabla de operadores.
	*/
	void interpretar(tablaOps* tabla);

  /*
  Se asegura de que la entrada sea numerica.
  */
  int no_palabra(char* entrada);

  /*
  Resuelve el arbol
  */
  int evaluar(Nodo* raiz);
#endif  __FUNCIONES_H__