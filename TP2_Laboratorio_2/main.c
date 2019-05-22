#include <stdio.h>
#include <stdlib.h>

#ifndef empleados_H_INCLUDED
#define empleados_H_INCLUDED
#include "Library/empleados.h"
#endif // empleados_H_INCLUDED

#ifndef sectores_H_INCLUDED
#define sectores_H_INCLUDED
#include "Library/sectores.h"
#endif // sectores_H_INCLUDED

#include "Input/input.h"

#define TAM_EMP 100
#define TAM_SEC 5

int main()
{

    eEmpleado empleado[TAM_EMP];
    eSector sector[TAM_SEC];

    char continuar= 's';
    char confirma;

    inicializarEmpleados(empleado,TAM_EMP);
    hardCordeoEmpleados(empleado);
    inicializarSectores(sector);

    do
    {
        switch(menuEmpleados())
        {
            case 1://ALTA EMPLEADO
                system("cls");

                altaEmpleado(empleado,TAM_EMP,sector,TAM_SEC);

                system("pause");
                break;

            case 2://MODIFICAR EMPLEADO
                system("cls");

                modificarEmpleado(empleado,TAM_EMP,sector,TAM_SEC);

                system("pause");
                break;

            case 3://BAJA EMPLEADO
                system("cls");

                bajaEmpleado(empleado,TAM_EMP,sector);

                system("pause");
                break;

            case 4://INFORMES
                system("cls");

                listarEmpleados(empleado,TAM_EMP,sector,TAM_SEC);

                promediosEmpleados(empleado,TAM_EMP,sector);

                system("pause");
                break;

            case 5:
                system("cls");

                getOptionChar(&confirma, "Confirmar salir [S/N]:","Para salir solo se puede ingresar [S/N]",'s','n');

                if(confirma=='S')
                {
                    continuar='n';
                }
                break;

            default:
                printf("Opcion Invalida\n\n");
                system("pause");
                break;
        }

        fflush(stdin);

    }while(continuar=='s');


    return 0;
}
