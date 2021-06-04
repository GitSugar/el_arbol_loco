#ifndef __OPERADORES_H__
#define __OPERADORES_H__

typedef int (*FuncionEvaluacion)(int *args);

/*
Suma:
La funcion suma toma los valores dentro del arreglo *args como elementos para 
ser sumados, y devuelve la suma de los mismos.

Simbolo: +
*/
int suma(int *args);

/*
Resta:
La funcion resta toma los valores dentro del arreglo *args como elementos para 
ser restados, y devuelve la resta de los mismos.

Simbolo: -
*/
int resta(int *args);

/*
Opuesto:
La funcion opuesto toma el unico valor int en *args y devuelve el opuesto

Simbolo: --
*/
int opuesto(int *args);

/*
Producto:
La funcion producto toma los valores dentro del arreglo *args como elementos 
para ser multiplicados, y devuelve el producto de los mismos

Simbolo: *
*/
int producto(int *args);

/*
Division:
La funcion division toma los valores dentro del arreglo *args como elementos 
para ser divididos, y devuelve el cociente de los mismos, redondeando los 
valores decimales hacia la parte entera

Simbolo: /
*/
int division(int *args);

/*
Modulo:
La funcion modulo toma el unico valor int en *args y devuelve el opuesto si es
negativo, o el mismo valor si es positivo o cero

Simbolo: %
*/
int modulo(int *args);

/*
Potencia:
La funcion potencia toma los valores dentro del arreglo *args, siendo el
primer elemento la base y el segundo elemento el exponente, y devuelve la base
elevada a la potencia

Simbolo: ^
*/
int potencia(int *args);
#endif