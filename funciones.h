#ifndef __FUNCIONES_H__
#define __FUNCIONES_H__

	/*
	Estructura basica para un árbol.
	Contiene nodo Izq, nodo Der y el contenido.
	No pidas mas.
	*/
	struct Nodo {
		struct Nodo *izq;
	  struct Nodo *der;
	  char* dato;
	};

	struct Nodo* raiz = NULL;

	/*
	Función para cargar los datos al árbol.
	*/
	void cargar(const char* string, Nodo* raiz)

	/*
	Función para imprimir los datos en notacion infija.
	*/
	void imprimir(Nodo* raiz);

	/*
	Genera un nodo en el arbol con los valores laterales.
	*/
	void cargar_operador(TablaOps* tabla, char* simbolo, int aridad, FuncionEvaluacion Eval);

	/*
	Interpreta los comandos ingresados y los resuelve usando la tabla de operadores.
	*/
	void interpretar(TablaOps* tabla);

  /*
  Se asegura de que la entrada sea numerica.
  */
  int no_palabra(char* entrada);

  /*
  Resuelve el arbol
  */
  int evaluar(Nodo* raiz);
#endif  __FUNCIONES_H__