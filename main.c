#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "menu.h"
#include "definiciones.h"
#include "orden.h"
#define TAM 5
FILE *archivo;
int main()
{
    bool validar = false;
    bool seguir = true;
    int opc;
    trenes vTrenes[TAM];
    do{
    menu();
    scanf("%d",&opc);
    printf("\n");
    switch(opc)
    {
    case INGRESAR:
        printf("Intentando abrir el archivo...\n");
            archivo = fopen("datos_coches.bin","rb");
            if (archivo)
            {
                printf("Archivo abierto \n");
                for (int i=0; i<TAM; i++)
                {
                    vTrenes[i] = malloc(sizeof(*vTrenes[i]));
                    printf("Cargando el registro numero: %d \n",i+1);
                    fread(vTrenes[i],sizeof(*vTrenes[i]),1,archivo);
                }
                fclose(archivo);
                printf("Archivo cerrado \n");
                validar=true;
                printf("Registros cargados \n\n");
            }
        break;
    case LISTAR:
        if(validar!=false)
        {
            printf("Registro de Ferrocariles:");
            printf("--------------------------------------");
            for(int i=0;i<TAM;i++){
                printf("%d)---------------------\n",i+1);
                listarCoches(vTrenes[i]);
                printf("-------------------------\n");
            }
        }
        else
        {   printf("\t \n---------------------------------------------------------------------------\n");
            printf("Error..Para ingresar a esta opcion, primero debe ingresar los datos.\n");
            printf("\t \n---------------------------------------------------------------------------\n");
        }
        break;
    case ORDENAR_X_ANIO:
        if(validar!=false)
        {

        }
        else
        {
             printf("\t \n---------------------------------------------------------------------------\n");
            printf("Error..Para ingresar a esta opcion, primero debe ingresar los datos.\n");
            printf("\t \n---------------------------------------------------------------------------\n");
        }
        break;
    case ORDENAR_X_MATRICULA:
        if(validar!=false)
        {

        }
        else
        {
             printf("\t \n---------------------------------------------------------------------------\n");
            printf("Error..Para ingresar a esta opcion, primero debe ingresar los datos.\n");
            printf("\t \n---------------------------------------------------------------------------\n");
        }
        break;
    case BUSCAR:
        if(validar!=false)
        {

        }
        else
        {
            printf("\t \n---------------------------------------------------------------------------\n");
            printf("Error..Para ingresar a esta opcion, primero debe ingresar los datos.\n");
            printf("\t \n---------------------------------------------------------------------------\n");
        }
        break;
    case CALCULAR_PASAJERO:
        if(validar!=false)
        {

        }
        else
        {
             printf("\t \n---------------------------------------------------------------------------\n");
            printf("Error..Para ingresar a esta opcion, primero debe ingresar los datos.\n");
            printf("\t \n---------------------------------------------------------------------------\n");
        }
        break;
    case CALCULAR_ASIENTOS:
        if(validar!=false)
        {

        }
        else
        {
            printf("\t \n---------------------------------------------------------------------------\n");
            printf("Error..Para ingresar a esta opcion, primero debe ingresar los datos.\n");
            printf("\t \n---------------------------------------------------------------------------\n");
        }
        break;
    case BAJAR_ARCHIVO:
        if(validar!=false)
        {

        }
        else
        {
             printf("\t \n---------------------------------------------------------------------------\n");
            printf("Error..Para ingresar a esta opcion, primero debe ingresar los datos.\n");
            printf("\t \n---------------------------------------------------------------------------\n");
        }
        break;
    case SALIR:
            seguir = false;
            printf("\nSaliendo...");
        break;
    default:
         printf("\t \n---------------------------------------------------------------------------\n");
            printf("Error..numero de opcion no encontrado.\n");
            printf("\t \n---------------------------------------------------------------------------\n");
        break;
    }} while(seguir!=false);

    return 0;

}
