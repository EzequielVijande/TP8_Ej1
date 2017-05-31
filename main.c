#include <stdio.h>
#include"output.h"
#include"input.h"
#include"const.h"
#include"bitmask.h"
#include "allegro5/allegro5.h"
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>



void destruir_imagenes(ALLEGRO_BITMAP  *(imagen[BIT8]));
//Funcion que destruye toda la memoria ocupada por las imagenes.

void poner_en_null(ALLEGRO_BITMAP  *(imagen[BIT8]), int largo);
//Funcion que inicializa los punteros a imagenes en NULL

typedef struct  //definicion de un puerto de 16 bits 
{
	char porta;
	char portb;
	
}portd_t;



int main(void)
{
	int valido= VALIDO;
	portd_t portd;
        
        ALLEGRO_EVENT_QUEUE *event_queue = NULL;
        ALLEGRO_DISPLAY * display = NULL;
        ALLEGRO_BITMAP  *(imagen[BIT8]); //crea un arreglo con las imagenes
                                         //que representan los LED.
        
        bool salir = false;
        
        poner_en_null(imagen, BIT8);
	
	if(!al_init())
        {
		fprintf(stderr, "failed to initialize allegro!\n");
		return -1;
	}
        
        if(!al_init_image_addon())
        {
		fprintf(stderr, "failed to initialize image addon !\n");
		return -1;
        }
        if(!al_init_acodec_addon())
        {
            fprintf(stderr, "failed to initialize audio!\n");
            return -1;
        }
        
        if(!al_install_audio())
        {
            fprintf(stderr, "failed to initialize audio!\n");
            return -1;
        } 
        if (!al_reserve_samples(1))
        {
            fprintf(stderr, "failed to reserve samples!\n");
            return -1;
        }
           
            
        if(!al_install_keyboard()) 
        {
		fprintf(stderr, "failed to initialize the keyboard!\n");
		return -1;
	}
	
        
        event_queue = al_create_event_queue();
	if(!event_queue) 
        {
		fprintf(stderr, "failed to create event_queue!\n");
		return -1;
        }
        
	display = al_create_display(1080, 1080); // Intenta crear display de 800x600 de fallar devuelve NULL
	if(!display)
        {
		fprintf(stderr, "no se logro crear el display\n");
		return -1;
	}
 
	al_clear_to_color(al_map_rgb(255,255,255)); //Hace clear del backbuffer del diplay al color blanco
 
	al_flip_display(); //Flip del backbuffer, pasa a verse a la pantalla
        
        al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_keyboard_event_source()); 
        
        
	
	imprimir_instrucciones();
        
        if( !(imprimir_estado_del_puerto((void*) (&(portd.porta)), imagen )) ) //imprime el estado del puerto A
                    {
                        al_destroy_display(display);
                        destruir_imagenes(imagen);
                        return -1;
                    }
        
        ALLEGRO_SAMPLE * sample= NULL;
        ALLEGRO_SAMPLE_ID *sample_id=NULL;
    
    sample = al_load_sample("Mambo_De_Chocobo_.flac");
    if(sample==NULL)
    {
        fprintf(stderr, "failed to initialize sample!\n");
        al_destroy_display(display);
        destruir_imagenes(imagen);
        return -1;
    }
         
        if(!(empezar_musica(sample,&sample_id)) )
        {
            al_destroy_display(display);
            destruir_imagenes(imagen);
            return -1;
        }

	while(!salir)
	{
                ALLEGRO_EVENT ev;
                if( al_get_next_event(event_queue, &ev) )
                {
                
                    if( !(imprimir_estado_del_puerto((void*) (&(portd.porta)), imagen )) ) //imprime el estado del puerto A
                    {
                        al_destroy_display(display);
                        destruir_imagenes(imagen);
                        return -1;
                    }

                    if(ev.type == ALLEGRO_EVENT_KEY_DOWN)
                    {
                        int tecla= ev.keyboard.keycode;
                     if(validacion_input(tecla));  
                     {

                        switch(tecla)
                        {
                                case PRENDER:
                                        mask_on((void*) (&(portd.porta)) , ON, PORTA);
                                        break;


                                case APAGAR:
                                        mask_off((void*) (&(portd.porta)) , ON, PORTA );
                                        break;

                                case PARPADEAR:
                                        parpadear( (void*)(&(portd.porta)), imagen );

                                        break;

                                case TERMINAR:
                                        salir= true;

                                        break;

                                default: 
                                        bitset( (void*)(&(portd.porta)), (int)(tecla-ALLEGRO_KEY_0) ); //Prende el numero de bit ingresado.
                        }
                     }
                    }
                    else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
                    {
                        salir=true;
                    }
                }
	}
	al_stop_sample(sample_id);
        al_destroy_display(display); //cierra el display y libera la memoria del mismo.
        destruir_imagenes(imagen);
        al_destroy_sample(sample);
        al_uninstall_audio();
	return 0;
	
	
}


void destruir_imagenes(ALLEGRO_BITMAP  *(imagen[BIT8]))
{
    int i;
    for(i=0; i<=BIT7; i++)
    {
        al_destroy_bitmap(imagen[i]);
    }
}
    
void poner_en_null(ALLEGRO_BITMAP  *(imagen[BIT8]), int largo)
{
    int i;
    for(i=0; i<largo; i++)
    {
        imagen[i]= NULL;
    }    
    
}
    
    



