#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "menu.h"
#include <wchar.h>
#include <locale.h>
void menu()
{
    printf(" 1)Ingresar coches de pasajeros: ");
    printf("\n 2)Listar coches de pasajeros: ");
    printf("\n 3)Ordenar coches por a?o descendente y/o cantidad de asientos: ");
    printf("\n 4)Ordenar coches por matr?cula: ");
    printf("\n 5)Buscar coches por matr?cula: ");
    printf("\n 6)Calcular el coche de pasajeros m?s antiguo: ");
    printf("\n 7)Calcular el total de asientos: ");
    printf("\n 8)Bajar a archivo: ");
    printf("\n 9)Salir.\n ");
}

void Error()
{
    printf("\t \n---------------------------------------------------------------------------\n");
    printf("Error..Para ingresar a esta opci?n, primero debe ingresar los datos.\n");
    printf("\t \n---------------------------------------------------------------------------\n");
}
void Error1()
{
    printf("\t \n---------------------------------------------------------------------------\n");
    printf("Error..se ingres? mal el dato.\n");
    printf("\t \n---------------------------------------------------------------------------\n");
}
void presentacion(){
printf("======================== TRABAJO PR?CTICO N?2 UNLZ ================================\n");
printf("==> MATERIA: FUNDAMENTOS DE LOS COMPUTADORES DIGITALES\n");
printf("==> ALUMNO: MAGRINI DAVID\n");
printf("***********************************************************************************\n");
printf("\n");

}

