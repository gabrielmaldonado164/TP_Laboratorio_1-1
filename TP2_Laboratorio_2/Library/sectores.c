#include <stdio.h>

#ifndef empleados_H_INCLUDED
#define empleados_H_INCLUDED
#include "empleados.h"
#endif // empleados_H_INCLUDED

#ifndef sectores_H_INCLUDED
#define sectores_H_INCLUDED
#include "sectores.h"
#endif // sectores_H_INCLUDED
/////////////////////////////////////////////////////////////////////////////////////////////////
void inicializarSectores(eSector sec[])
{
    eSector sectores[] = {
    {1, "Sistemas"},
    {2, "RRHH"},
    {3, "Compras"},
    {4, "Ventas"},
    {5, "Legales"},
    };

    for (int i = 0; i < 5; i++)
    {
        sec[i] = sectores[i];
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////
void mostrarSectores(eSector sec[], int tamSec)
{
    printf("\nSECTOR del empleado\n");
    for (int i = 0; i < tamSec; i++)
    {
        printf("%d. %s\n", sec[i].idSector, sec[i].descripcion);
    }
}
