/*
 * servicio.c
 *
 *
 *
 */

#include "servicio.h"
#define VACIO 0
#define OCUPADO 1
#include <stdio.h>

void mostrarListadoDeServicios(eServicio lista[], int tam)
{
	int i;

		for(i=0; i<tam; i++)
		{
		    if(lista[i].isEmpty == OCUPADO)
		    {
		        mostrarUnServicio(lista[i]);
		    }

		}
}

void mostrarUnServicio(eServicio unServicio)
{
	printf(" la id de servicio %d, la descripcion %s, el precio %d \n",
			unServicio.idServicio,
			unServicio.descripcion,
			unServicio.precio

		                            );
}
