//Modulo que se encarga de recibir el input y de validarlo

#ifndef INPUT_H
#define INPUT_H

#include<stdio.h>
#include "const.h"
#include "allegro5/allegro5.h"

char get_input(void);
//funcion que busca el caracter ingresado por el input
//y devuelve cual es dicho caracter.

int validacion_input(int);
//recibe el caracter ingresado por input y se fija
//si la misma es un a tecla de ingreso valida.

#endif //INPUT_H

