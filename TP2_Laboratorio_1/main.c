#include <stdio.h>
#include <stdlib.h>
#include "Library/Empleados.h"
#include "Input/input.h"

#define TAM_EMP 1000

int main()
{
    eEmpleado* lista = (eEmpleado*)malloc(sizeof(eEmpleado)*TAM_EMP);
    int contadorEmpleados=0;
    char confirma;
    int salir=0;

    if(lista==NULL)
    {
        system("cls");
        printf("No se consigio espacio en memoria para operar\n\n");
        system("pause");
        exit(EXIT_FAILURE);
    }

    initEmployees(lista,TAM_EMP);

    do
    {
        switch(menuEmpleados())
        {
            case 1:
                system("cls");

                if(altaEmpleado(lista,TAM_EMP)==0)
                {
                    contadorEmpleados++;
                }

                system("pause");
                break;
            case 2:
                system("cls");


                system("pause");
                break;
            case 3:
                system("cls");
                if(contadorEmpleados>=1)
                {
                    if(bajaEmpleado(lista,TAM_EMP)==0)
                    {
                        contadorEmpleados--;
                    }

                }else
                {
                    printf("No hay empleados en el sistema\n\n");
                }
                system("pause");
                break;
            case 4:
                system("cls");
                if(contadorEmpleados>=1)
                {
                    printEmployees(lista,TAM_EMP);

                }else
                {
                    printf("No hay empleados en el sistema\n\n");
                }
                system("pause");
                break;
            case 5:
                system("cls");
                getOptionChar(&confirma,"Confirmar salir [S/N]:","Solo puede ingresar [S/N]",'S','N');
                if(confirma=='S')
                {
                    salir=1;
                }
                break;

            default:

                break;
        }

    }while(salir!=1);

    free(lista);

    return 0;
}
