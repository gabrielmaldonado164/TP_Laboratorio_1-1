#include <stdio.h>
#include <stdlib.h>
#include "Library/Empleados.h"

#define TAM_EMP 1000

int main()
{
    eEmpleado* lista = (eEmpleado*)malloc(sizeof(eEmpleado)*TAM_EMP);
    int contadorEmpleados=0;

    if(lista==NULL)
    {
        system("cls");
        printf("No se consigio espacio en memoria para operar\n\n");
        system("pause");
        exit(EXIT_FAILURE);
    }

    initEmployees(lista,TAM_EMP);

    int salir=0;

    do
    {
        switch(menuEmpleados())
        {
            case 1:
                system("cls");

                altaEmpleado(lista,TAM_EMP);
                contadorEmpleados++;

                system("pause");
                break;
            case 2:

                break;
            case 3:
                system("cls");

                bajaEmpleado(lista,TAM_EMP);
                contadorEmpleados--;

                system("pause");
                break;
            case 4:
                system("cls");

                printEmployees(lista,TAM_EMP);

                system("pause");
                break;
            case 5:
                salir=1;
                break;

            default:
                system("cls");
                system("pause");
                break;
        }

    }while(salir!=1);

    free(lista);

    return 0;
}
