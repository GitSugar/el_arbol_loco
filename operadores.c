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
  int res;
  res = pow(args[0],args[1]);
  return res;
}