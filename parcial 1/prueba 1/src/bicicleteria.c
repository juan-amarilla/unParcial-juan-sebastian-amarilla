/*
 * bicicleteria.c
 *
 *
 *
 */

#include "bicicleteria.h"
#define VACIO 0
#define OCUPADO 1
#include <stdio.h>

int menu()
{
	int opcion;

	printf("1.ALTA trabajo\n");
	printf("2.MODIFICAR trabajo \n");
    printf("3.BAJA trabajo \n");
	printf("4.LISTAR trabajos \n");
	printf("5.LISTAR servicios \n");
	printf("6.MOSTRAR total en pesos por los servicios prestados \n");
	printf("7.SALIR \n");
	printf("Elija una opcion: ");
	scanf("%d", &opcion);

	return opcion;
}

int altaTrabajo(eTrabajo lista[], int tamTrabajo, eServicio listaServicio[])
{
	 int i;
	 i = buscarLibreTrabajo(lista, tamTrabajo);
	 if(i!=-1)
	 {
	        lista[i] = pedirDatosTrabajo(listaServicio);

	 }


     return i;
}

eTrabajo pedirDatosTrabajo(eServicio listaServicio[])
{

	eTrabajo miTrabajo;

	printf("Ingrese id de trabajo: ");
	scanf("%d", &miTrabajo.id);

	printf("Ingrese marca de bicicleta: ");
	fflush(stdin);
	scanf("%[^\n]", miTrabajo.marcaBicicleta);

	printf("Ingrese rodado de bicicleta en numero entero: ");
    scanf("%d", &miTrabajo.rodadoBicicleta);

    printf("Ingrese id de servicio: ");
    scanf("%d", &miTrabajo.idServicio);
    while(miTrabajo.idServicio<20000 || miTrabajo.idServicio>20003)
    {
    	printf("Error: Ingrese id de servicio entre 20000 y 20003 inclusive: ");
    	scanf("%d", &miTrabajo.idServicio);
    }

    printf("Ingrese dia en numero entero: ");
    scanf("%d", &miTrabajo.dia);
    while(miTrabajo.dia<1 || miTrabajo.dia>31)
    {
        	printf("Error: Ingrese dia entre 1 y 31 inclusive: ");
        	scanf("%d", &miTrabajo.dia);
    }

    printf("Ingrese mes en numero entero: ");
    scanf("%d", &miTrabajo.mes);
    while(miTrabajo.mes<1 || miTrabajo.mes>12)
    {
        	printf("Error: Ingrese mes entre 1 y 12 inclusive: ");
        	scanf("%d", &miTrabajo.mes);
    }

    printf("Ingrese a�o en numero entero: ");
    scanf("%d", &miTrabajo.anio);
    while(miTrabajo.anio<2000 || miTrabajo.anio>2021)
    {
        	printf("Error: Ingrese mes entre 2000 y 2021 inclusive: ");
        	scanf("%d", &miTrabajo.anio);
    }

	miTrabajo.isEmpty = OCUPADO;

	return miTrabajo;
}

void modificarTrabajo(eTrabajo lista[], int tamTrabajo, eServicio listaServicio[])
{
	    int i;
	    int id;
	    int flag;
	    int opcion;

	    flag=0;

	    printf("Ingrese el id del trabajo para la modificacion: \n");
	    scanf("%d", &id);

	    printf("Ingrese 1 para modificar la marca de bicicleta \n");
	    printf("Ingrese 0 para modificar la id del servicio \n");
	    scanf("%d", &opcion);

	    for (i=0;i<tamTrabajo;i++)
	    {

	       if (lista[i].id==id && opcion==1)
	       {
	            flag=1;

	            printf("Ingrese una marca nueva: ");
	            fflush(stdin);
	            scanf("%[^\n]", lista[i].marcaBicicleta);

	            printf("La modificacion fue exitosa\n");

	            break;
	       }

	       else if (lista[i].id==id && opcion==0)
	       {
	            flag=1;

	            printf("Ingrese una id de servicio nuevo: ");
	            scanf("%d", &lista[i].idServicio);

	            while(lista[i].idServicio<20000 || lista[i].idServicio>20003)
	            {
	                	printf("Error: Ingrese id de servicio entre 20000 y 20003 inclusive: ");
	                	scanf("%d", &lista[i].idServicio);
	            }


	            printf("La modificacion fue exitosa\n");

	            break;
	       }

	    }

	    if (flag==0)
	    {
	        printf("La modificacion no fue exitosa\n");
	    }
}

void mostrarListadoDeTrabajos(eTrabajo lista[], int tam)
{
	int i;

	for(i=0; i<tam; i++)
	{
	    if(lista[i].isEmpty == OCUPADO)
	    {
	        mostrarUnTrabajo(lista[i]);
	    }

	}
}

void mostrarUnTrabajo(eTrabajo unTrabajo)
{
	printf("la id %d, la marca %s, el rodado %d, la id servicio %d, el dia %d, el mes %d, el a�o %d \n",
			unTrabajo.id,
			unTrabajo.marcaBicicleta,
			unTrabajo.rodadoBicicleta,
			unTrabajo.idServicio,
			unTrabajo.dia,
			unTrabajo.mes,
			unTrabajo.anio
	                            );
}

void totalPesosDeServicio(eTrabajo listaTrabajo[], int tamTrabajo, eServicio listaServicio[], int tamServicio)
{
	    int i;
	    eAuxiliar auxiliar[tamServicio];

	    for (i=0;i<tamServicio;i++)
	    {
	        auxiliar[i].id=listaServicio[i].idServicio;
	        auxiliar[i].acumulador=0;
	    }

	    for (i=0;i<tamServicio;i++)
	    {

	         if (auxiliar[i].id==listaServicio[i].idServicio)
	         {
	              auxiliar[i].acumulador+=listaServicio[i].precio;
	         }


	    }

        printf("el precio total es: %d \n", listaServicio[i].precio);

}
