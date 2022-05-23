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
    presentacion();
    bool validar = false;
    bool seguir = true;
    int opc;
    trenes vTrenes[TAM];

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
                Error();
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
                Error();
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
                Error();
            }
            break;
        case BUSCAR:
            if(validar!=false)
            {
                char matri[TAM];
                printf("Ingrese la matrícula que desea buscar: ");
                scanf("%s",&matri);
                for(int i=0; i<TAM; i++)
                {
                    if(strcmp(matri,vTrenes[i]->matricula)==0)
                    {
                        listarCoches(vTrenes[i]);
                        printf("\n");
                    }
                }

            }


            else
            {
                Error();
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
                printf("El tren mas antiguo es : \n");
                listarCoches(vTrenes[masAntiguo]);
                printf("------------------------------------------\n");

            }
            else
            {
                Error();
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
                Error();
            }
            break;
        case BAJAR_ARCHIVO:
            if(validar!=false)
            {
                trenes tren;
                bajada= fopen("bajada_datos.txt","w");

                if (bajada==NULL)  exit(1);
                for (int i=0; i<TAM; i++)
                {
                    if (tren[i].operativo != 'si' || tren[i].operativo!='SI'|| tren[i].operativo!='Si')
                    {
                        fprintf(bajada,"Coche N°: \n",i+1);
                        fprintf(bajada,"Matricula: %s\n",tren[i].matricula);
                        fprintf(bajada,"Modelo de fabricacion: %d\n",tren[i].anio_fabricacion);
                        fprintf(bajada,"Cantidad de asientos: %d\n",tren[i].cant_asientos);
                        fprintf(bajada,"Operativo: %s\n",tren[i].operativo);
                        fprintf(bajada,"\n");
                        fprintf(bajada,"\n");
                    }
                }

                fclose(bajada);
                printf("\t*****   DATOS GUARDADOS EN .txt    *****\n\n");
            }
            else
            {
                Error();
            }
            break;
        case SALIR:
            seguir = false;
            printf("\nSaliendo...");
            break;
        default:
            Error1();
            break;
        }
    }
    while(seguir!=false);
    return 0;

}
