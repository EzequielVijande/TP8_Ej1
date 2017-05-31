#include"input.h"




int validacion_input(int);
//recibe el caracter ingresado por input y se fija
//si la misma es un a tecla de ingreso valida.




int validacion_input(int caracter)
{
	if( (caracter>=ALLEGRO_KEY_0)&&(caracter<= ALLEGRO_KEY_9) )
	{
		return VALIDO;	
	}
	else if( (caracter==TERMINAR)||(caracter==APAGAR)||(caracter==PRENDER)||(caracter==PARPADEAR) )
	{
		return VALIDO;
	}
	else
	{
		return INVALIDO;
	}


}


