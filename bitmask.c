#include <allegro5/bitmap.h>

#include"bitmask.h"



void bitset( void* port , int nbit)
{
	if( (nbit>=BIT0) && (nbit<=BIT7) ) 
	//Interpreta si es el puerto D o no, dependiendo de que bit se quiere prender

	{
		char by=1;

		by <<= nbit; //se crea una mascara con el bit que se desea prender.
			
		(*((char*)port))|= by; //se prende el bit del puerto
		
	}
	else
	//Si se desea prender un bit mayor al bit7 interpreta el puerto como el D.
	{
		char by=1;
		char* p_portb = (char*)port+BYTE; //apunta al puerto B
		by<<= (nbit-BIT8); //le resta 8 bits para trabajar dentro del byte del puerto B.
		
		*p_portb |= by;
	}
	

}


void bitclr( void* port , int nbit)
{
	if( (nbit>=BIT0) && (nbit<=BIT7) )
	//Interpreta si es el puerto D o no, dependiendo de que bit se quiere prender
	{
		char by=1;

		by <<= nbit; 
		by=(~by);
		(*(char*)port)&= by; //Apaga el bit del puerto correspondiente
	}
	
	else
	//Si se desea prender un bit mayor al bit7 interpreta el puerto como el D.
	{
		char by=1;
		char* p_portb = (char*)port+BYTE; //apunta al puerto B
		by <<= (nbit-BIT8); 
		by=(~by);

		*p_portb &= by; //Apago el bit correspondiente del puerto B.		
	}

}

void bit_toggle(void* port, int nbit)
{

	if( (nbit>=BIT0) && (nbit<=BIT7) ) 
	//Interpreta si es el puerto D o no, dependiendo de que bit se quiere alterar

	{
		char by=1;

		by <<= nbit; //se crea una mascara con el bit que se desea alterar.
			
		(*((char*)port))^= by; 
		
	}
	else
	//Si se desea prender un bit mayor al bit7 interpreta el puerto como el D.
	{
		char by=1;
		char* p_portb = (char*)port+BYTE; //apunta al puerto B
		by<<= (nbit-BIT8); //le resta 8 bits para trabajar dentro del byte del puerto B.
		
		*p_portb ^= by;
	}
	


}


void mask_toggle(void* p_port, uint16_t mask, char port)
{
	if( (port==PORTA)||(port==PORTB) )
	{
		*((char*)p_port) ^= (char)mask;  
	}
	else
	{
		*((char*)p_port) ^=	mask;
	}
}

void mask_on(void* p_port, uint16_t mask, char port)
{
	if( (port==PORTA)||(port==PORTB) )
	{
		*((char*)p_port)|= (char)mask;
	} 
	else
	{
		*((char*)p_port)|= mask;
	}
}

void mask_off(void* p_port, uint16_t mask, char port )
{
	if( (port==PORTA)||(port==PORTB) )
	{
		*((char*)p_port) &= (char)(~mask);
	}
	else
	{
		*((char*)p_port) &= (~mask);
	}
}


void parpadear(void* port, ALLEGRO_BITMAP  *(imagen[BIT8]))
{
	int i;
	char* p_porta = (char*)port;
	for(i=0; i<TIEMPO_PARPADEANDO; i++)
		{
			*p_porta= ON;
                        imprimir_estado_del_puerto(port, imagen );
			sleep(UN_SEGUNDO);
			*p_porta= OFF;
                        (imprimir_estado_del_puerto(port, imagen ));
			sleep(UN_SEGUNDO);
		}

}



