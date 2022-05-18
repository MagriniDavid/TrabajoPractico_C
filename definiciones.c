#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "definiciones.h"

void listarCoches(trenes tren){
    printf("Matricula: %d \n",tren->matricula);
    printf("Anio de Fabricacion: %d \n",tren->anio_fabricacion);
    printf("Cantidad de Asientos: %d\n",tren->cant_asientos);
    printf("Operativo: %s \n",tren->operativo);
}


