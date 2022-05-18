#ifndef DEFINICIONES_H_INCLUDED
#define DEFINICIONES_H_INCLUDED
#define t 10
/*todo lo relacionado a estructuras, punteros y funciones*/
typedef struct estructura_ferrocarril *trenes;

struct estructura_ferrocarril {
    char matricula[10];
    int anio_fabricacion;
    int cant_asientos;
    char operativo[3];
};
void listarCoches (trenes tren);


#endif // DEFINICIONES_H_INCLUDED
