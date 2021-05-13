/*
 ============================================================================
Apellido: Amarilla
Nombre: Juan Sebastian
Division: 1B
Fecha: 13/05/2021
 ============================================================================
 */

#include <stdio.h>
#define VACIO 0
#define OCUPADO 1
#include "bicicleteria.h"
#define T 4

int main(void) {
	eServicio servicios[T] = {{20000,"Limpieza",250,1},{20001,"Parche",300,1},{20002,"Centrado",400,1},{20003,"Cadena",350,1}};

	eTrabajo trabajos [T];
	int opcion;
	int retorno;

	inicializarTrabajos(trabajos, T);

	setbuf(stdout, NULL);

	do
	{
	   opcion=menu();

	   switch(opcion)
	   {
	          case 1:
	            retorno =  altaTrabajo(trabajos, T, servicios);
	            if(retorno !=-1)
	            {
	                printf("trabajo ingresado con exito!!!\n");
	            }
	            else
	            {
	                printf("No hay mas lugar en la lista!!\n");
	            }
	            break;

	          case 2:
	        	  modificarTrabajo(trabajos, T, servicios);
	          break;

	          case 3:
	        	  bajaTrabajo(trabajos, T);
	          break;

              case 4:
            	  ordenarTrabajosPorAnio(trabajos, T);
            	  mostrarListadoDeTrabajos(trabajos, T);
              break;

              case 5:
            	  mostrarListadoDeServicios(servicios, T);
              break;

              case 6:
                  totalPesosDeServicio(trabajos, T, servicios, T);
              break;
	   }

  } while(opcion!=7);

  return 0;
}
