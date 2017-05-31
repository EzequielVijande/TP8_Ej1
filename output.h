//Modulo que se encarga de todo lo que el programa imprime.

#ifndef OUTPUT_H
#define OUTPUT_H

#include<stdio.h>
#include"const.h"
#include "allegro5/allegro5.h"
#include <allegro5/allegro_audio.h>

void imprimir_instrucciones(void);
//Imprime en pantalla como funciona el programa

void imprimir_formato_equivocado(void);
//Avisa en pantalla que se ingreso un formato invalido y
//que este debe ser ingresado nuevamente.

void imprimir_presionar_tecla(void);
//Imprime que se esta esperando el ingreso de una tecla.

int imprimir_estado_del_puerto(void*, ALLEGRO_BITMAP  *(imagen[BIT8]));
//Imprime en pantalla como se encuentra el puerto de 8 bits.

bool empezar_musica(ALLEGRO_SAMPLE * sample, ALLEGRO_SAMPLE_ID **sample_id);
//funcion que inicializa la musica

#endif //OUTPUT_H
