#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "definiciones.h"

void listarCoches(trenes tren){
    printf("Matr�cula: %d \n",tren->matricula);
    printf("A�o de Fabricaci�n: %d \n",tren->anio_fabricacion);
    printf("Cantidad de Asientos: %d\n",tren->cant_asientos);
    printf("Operativo: %s \n",tren->operativo);
}


