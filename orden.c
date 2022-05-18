#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "definiciones.h"
#include "orden.h"
#include <wchar.h>
#include <locale.h>

int ordenxAnio_Asientos(const void *trenA, const void *trenB)
{
    trenes t1 = *(trenes *)trenA;
    trenes t2 = *(trenes *)trenB;
    if(t2->anio_fabricacion > t1->anio_fabricacion)
    {
        return 1;
    }
    else if(t2->anio_fabricacion < t1->anio_fabricacion)
    {
        return -1;
    }
    else
    {
        if(t2->anio_fabricacion == t1->anio_fabricacion)
        {
            if(t2->cant_asientos > t1->cant_asientos)
            {
                return 1;
            }
            else if(t2->cant_asientos < t1->cant_asientos)
            {
                return -1;
            }
        }
        else
        {
            return 0;
        }
    }
}

int ordenxMatricula(const void *trenC, const void *trenD)
{
    trenes t3 = *(trenes *)trenC;
    trenes t4 = *(trenes *)trenD;
    if(t3->matricula > t4->matricula)
    {
        return 1;
    }
    else if(t3->matricula < t4->matricula)
    {
        return -1;
    }
    else
    {
        return 0;
    }

}
int comparar(const void *tren1, const void *tren2)
{
    int *pi = (int *)tren1;
	int *pj = (int *)tren2;
    return *pi - *pj;
	if (*pi % 2 == 0 && *pj %2 != 0)
		{return -1;}
	if (*pj % 2 == 0 && *pi %2 != 0)
		{return 1;}
	if (*pj % 2 == 0 && *pi %2 == 0)
		{return *pi - *pj;}
	else if (*pj % 2 != 0 && *pi %2 != 0)
		{return *pj - *pi;}
}
