#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "definiciones.h"

void listarCoches(trenes tren){
    printf("Matrícula: %d \n",tren->matricula);
    printf("Año de Fabricación: %d \n",tren->anio_fabricacion);
    printf("Cantidad de Asientos: %d\n",tren->cant_asientos);
    printf("Operativo: %s \n",tren->operativo);
}


