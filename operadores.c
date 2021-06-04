#include <math.h>
typedef int (*FuncionEvaluacion)(int *args);

int suma(int *args) {
  int res;
  res = args[0] + args[1];
  return res;
}

int resta(int *args) {
  int res;
  res = args[0] - args[1];
  return res;
}

int opuesto(int *args) {
  int op;
  op = args[0] * (-1);
  return op;
}

int producto(int *args) {
  int res;
  res = args[0] * args[1];
  return res;
}

int division(int *args) {
  int res;
  if (args[1] != 0){
    res = args[0] / args[1];
    return res;
  }
}

int modulo(int *args) {
  int res;
  if (args[0] < 0){
    res = opuesto(args);
    return res;
  }
  return args[0];
}

int potencia(int *args) {
  int res = 1;
  if(args[1] < 0){
    return 0;
  }
  for(int i = args[1]; i<0; i--){
    res = res * args[0];
  }
  return res;
}