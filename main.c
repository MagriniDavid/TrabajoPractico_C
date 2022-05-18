#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <wchar.h>
#include <locale.h>
#include "menu.h"
#include "definiciones.h"
#include "orden.h"
#define TAM 5
FILE *archivo;
FILE *bajada;
int main()
{
    setlocale(LC_CTYPE, "Spanish");
    bool validar = false;
    bool seguir = true;
    int opc,verificar;
    int busc;
    int *buscador;
    trenes vTrenes[TAM],vTrenes_n_op[TAM];
    do
    {
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
                    printf("Cargando el registro número: %d \n",i+1);
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
                printf("Registro de Ferrocariles:\n");
                printf("--------------------------------------\n");
                for(int i=0; i<TAM; i++)
                {
                    printf("%d)---------------------\n",i+1);
                    listarCoches(vTrenes[i]);
                    printf("-------------------------\n");
                }
            }
            else
            {
                printf("\t \n---------------------------------------------------------------------------\n");
                printf("Error..Para ingresar a esta opción, primero debe ingresar los datos.\n");
                printf("\t \n---------------------------------------------------------------------------\n");
            }
            break;
        case ORDENAR_X_ANIO:
            if(validar!=false)
            {
                printf("Registro de Ferrocariles ordenados por año:\n");
                printf("--------------------------------------\n");
                qsort(vTrenes,TAM,sizeof vTrenes[0],ordenxAnio_Asientos);
                for(int i=0; i<TAM; i++)
                {
                    printf("%d)---------------------\n",i+1);
                    listarCoches(vTrenes[i]);
                    printf("-------------------------\n");
                }
            }
            else
            {
                printf("\t \n---------------------------------------------------------------------------\n");
                printf("Error..Para ingresar a esta opción, primero debe ingresar los datos.\n");
                printf("\t \n---------------------------------------------------------------------------\n");
            }
            break;
        case ORDENAR_X_MATRICULA:
            if(validar!=false)
            {
                printf("Registro de Ferrocariles ordenados por matrícula:\n");
                printf("--------------------------------------\n");
                qsort(vTrenes,TAM,sizeof vTrenes[0],ordenxMatricula);
                for(int i=0; i<TAM; i++)
                {
                    printf("%d)---------------------\n",i+1);
                    listarCoches(vTrenes[i]);
                    printf("-------------------------\n");
                }
            }
            else
            {
                printf("\t \n---------------------------------------------------------------------------\n");
                printf("Error..Para ingresar a esta opción, primero debe ingresar los datos.\n");
                printf("\t \n---------------------------------------------------------------------------\n");
            }
            break;
        case BUSCAR:
            if(validar!=false)
            {
//                puts( "Indique la matrícula a encontrar:" );
//                scanf("%d",&busc);
//                buscador = bsearch(&busc,vTrenes,TAM, sizeof(vTrenes[0]),comparar);
//                if(buscador)
//                {
//                int i = buscador - vTrenes;
//                printf("%d se encuentra en la posición %d\n", busc, i);
//                }
//                else
//                {
//                    printf("%d no se encuentra entre los datos\n", busc);
//                }
//

            }

        else
        {
            printf("\t \n---------------------------------------------------------------------------\n");
            printf("Error..Para ingresar a esta opción, primero debe ingresar los datos.\n");
            printf("\t \n---------------------------------------------------------------------------\n");
        }
        break;
    case CALCULAR_PASAJERO:
        if(validar!=false)
        {
            int masAntiguo =0;
            int antiguedad = vTrenes[0]->anio_fabricacion;
            for(int i=0; i<TAM; i++)
            {
                if(antiguedad>vTrenes[i]->anio_fabricacion)
                {
                    antiguedad = vTrenes[i]->anio_fabricacion;
                    masAntiguo = i;

                }
            }
            printf("------------------------------------------\n");
            printf("El tren mas antiguo es : %d\n");
            listarCoches(vTrenes[masAntiguo]);
            printf("------------------------------------------\n");

        }
        else
        {
            printf("\t \n---------------------------------------------------------------------------\n");
            printf("Error..Para ingresar a esta opción, primero debe ingresar los datos.\n");
            printf("\t \n---------------------------------------------------------------------------\n");
        }
        break;
    case CALCULAR_ASIENTOS:
        if(validar!=false)
        {
            int total=0;
            for(int i =0; i<TAM; i++)
            {
                total=total+vTrenes[i]->cant_asientos;
            }
            printf("------------------------------------------\n");
            printf("El total de asientos es de: %d\n",total);
            printf("------------------------------------------\n");
        }
        else
        {
            printf("\t \n---------------------------------------------------------------------------\n");
            printf("Error..Para ingresar a esta opción, primero debe ingresar los datos.\n");
            printf("\t \n---------------------------------------------------------------------------\n");
        }
        break;
    case BAJAR_ARCHIVO:
        if(validar!=false)
        {
            printf("Bajando listado de trenes que no estan operando.....\n");
            bajada = fopen("choches_sin_operar.bin","w+b");
            if(bajada)
            {
                printf("\nArhivo datos_coches.bin abierto\n");
                for(int i=0; i<TAM; i++)
                {
                    if(vTrenes[i]->operativo =='NO')
                    {
                        fputs(vTrenes[i]->matricula,bajada);
                        fprintf(bajada,"\n");
                        fputs(vTrenes[i]->anio_fabricacion,bajada);
                        fprintf(bajada,"\n");
                        fputs(vTrenes[i]->cant_asientos,bajada);
                        fprintf(bajada,"\n");
                        fputs(vTrenes[i]->operativo,bajada);
                        fprintf(bajada,"\n");
                        fprintf(bajada,"\n");
                    }

                }
                puts("Registros Guardados Exitosamente...");
                fclose(bajada);
                printf("\tArchivo cerrado\n");
            }
//                printf("\nDesea verificar la informacion subida?\n");
//                printf("PRESIONE 1 PARA VERIFICAR O 2 PARA VOLVER AL MENU:\n");
//                scanf("%d",verificar);
//                if(verificar==1)
//                {
//                    printf("Intentando abrir el archivo...\n");
//                    bajada = fopen("choches_sin_operar","rb");
//                    if (archivo)
//                    {
//                        printf("Archivo abierto \n");
//                        for (int i=0; i<TAM; i++)
//                        {
//                            vTrenes_n_op[i] = malloc(sizeof(*vTrenes_n_op[i]));
//                            printf("Cargando el registro número: %d \n",i+1);
//                            fread(vTrenes_n_op[i],sizeof(*vTrenes_n_op[i]),1,bajada);
//                        }
//                        fclose(bajada);
//                        printf("Archivo cerrado \n");
//                    }
//                }
//                else
//                {
//                    return opc;
//                }
        }
        else
        {
            printf("\t \n---------------------------------------------------------------------------\n");
            printf("Error..Para ingresar a esta opción, primero debe ingresar los datos.\n");
            printf("\t \n---------------------------------------------------------------------------\n");
        }
        break;
    case SALIR:
        seguir = false;
        printf("\nSaliendo...");
        break;
    default:
        printf("\t \n---------------------------------------------------------------------------\n");
        printf("Error..número de opción no encontrado.\n");
        printf("\t \n---------------------------------------------------------------------------\n");
        break;
    }
}
while(seguir!=false);

return 0;

}
