#ifndef __FUNCIONES_H__
#define __FUNCIONES_H__
	
	/*
	Estructura basica para un árbol.
	*/
	struct Nodo {
		struct node *left;
	    struct node *right;
	    char *string;
	};

	struct *Operador;

	/*
	Función para cargar los datos al árbol.
	*/
	struct Nodo cargar(char *datoCargar);


	/*
	Función para imprimir los datos en notacion infija.
	*/
	void imprimir(Nodo *Operador);

	void cargar_operador(TablaOps *tabla, char *simbolo, int aridad, FuncionEvaluacion Eval);

	void interpretar(TablaOps *tabla);


#endif  __FUNCIONES_H__