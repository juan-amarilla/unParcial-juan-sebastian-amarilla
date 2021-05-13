/*
 * servicio.h
 *
 *
 *
 */

typedef struct
{
   int idServicio;
   char descripcion[25];
   int precio;
   int isEmpty;

}eServicio;

//empieza a mostrar servicios
void mostrarListadoDeServicios(eServicio lista[], int tam);

// mostrara un servicio
void mostrarUnServicio(eServicio unServicio);

#ifndef SERVICIO_H_
#define SERVICIO_H_



#endif /* SERVICIO_H_ */
