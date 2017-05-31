
#include"output.h"

#define OFFSET 90






void imprimir_instrucciones(void)
{
	printf("Este programa es una simulacion de un puerto de 8 bits\n");
	printf("en el cual cada bit representa un LED.\n");
	printf(" Cada LED puede tener dos estado posibles, apagado (0),\n");
	printf("o prendido (1).\n");
	printf("Se permite elegir entre las siguientes opciones por teclado:\n");
	printf("-Un numero del 0 al 7 que representa el LED que desea prender\n");
	printf("-La letra 'b' para que todos los LED parpadien.\n");
	printf("-La letra 'c' para apagar todos los LED.\n");
	printf("-La letra 's' para prender todos los LED\n");
	printf("-La tecla Esc para terminar el programa.\n");
}


void imprimir_presionar_tecla(void)
{
	printf("\nPor favor ingresar una tecla...\n");

}

void imprimir_formato_equivocado(void)
{
	printf("\nEl formato ingresado es invalido, recuerde que las\n");
	printf("entradas permitidas son 'b', 'c', 's', Esc o un\n");
	printf("numero del 0 al 7.\n");
	printf("Por favor ingresar nuevamente una opcion.\n");
}


int imprimir_estado_del_puerto(void* p_port, ALLEGRO_BITMAP  *(imagen[BIT8]))
{
	int i;
	printf("\nEstado del puerto:\n ");
	char mascara= 0X80; //mascara con solo el bit7 prendido.
	char port= *((char*)p_port);   
        int validez=VALIDO;
        

	for(i=0; (i<=BIT7)&&(validez); i++) //imprime la representacion en binario del puerto.
	{
            
            
		if(port&mascara)
		{
                        
                        imagen[i] = al_load_bitmap("YellowChocobo2.png");
                        if(!(imagen[i]))
                        {
                            fprintf(stderr, "failed to load image !\n");
                            validez = INVALIDO;
                        }
                        
                        al_draw_bitmap(imagen[i], OFFSET*i, 150, 0);
 
                        al_flip_display();
                        
                        
                        
		}
		else
		{
			imagen[i] = al_load_bitmap("BlackChocobo2.png");
                        if(!(imagen[i]))
                        {
                            fprintf(stderr, "failed to load image !\n");
                            validez =  INVALIDO;
                        }
                        
                        al_draw_bitmap(imagen[i], OFFSET*i, 150, 0);
 
                        al_flip_display();
		}
		port<<=1;
		
	}
        return validez;
	
}

bool empezar_musica(ALLEGRO_SAMPLE * sample, ALLEGRO_SAMPLE_ID **sample_id)
{
   ALLEGRO_SAMPLE_ID * id=NULL;
    if(!al_play_sample(sample, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_LOOP,id))
    {
        return false;
    }
   *sample_id= id;
    return true;
        
}






