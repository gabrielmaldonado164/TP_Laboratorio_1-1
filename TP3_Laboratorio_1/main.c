#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "Input.h"

#define PATH_TXT "./data.csv"
#define PATH_BIN "./data.bin"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int option;
    char confirma='N';
    char confirmaSave;
    LinkedList* listaEmpleados = ll_newLinkedList();

    do{
        option=0;
        system("cls");
        printf("MENU DE EMPLEADOS\n\n");
        printf("1. Cargar los datos de los empleados (data.csv)\n");
        printf("2. Cargar los datos de los empleados (data.bin)\n");
        printf("3. Alta empleado\n");
        printf("4. Modificar empleado\n");
        printf("5. Baja empleado\n");
        printf("6. Listar empleados\n");
        printf("7. Ordenar empleados\n");
        printf("8. Guardar los datos de los empleados (data.csv)\n");
        printf("9. Guardar los datos de los empleados (data.bin)\n");
        printf("10. Salir\n");

        printf("\nIngresar opcion: ");
        fflush(stdin);
        scanf("%d", &option);

        switch(option)
        {
            case 1:
                system("cls");

                controller_loadFromText(PATH_TXT,listaEmpleados);

                system("pause");
                break;

            case 2:
                system("cls");

                controller_loadFromBinary(PATH_BIN,listaEmpleados);

                system("pause");
                break;

            case 3:
                system("cls");

                controller_addEmployee(listaEmpleados);

                system("pause");
                break;

            case 4:
                system("cls");

                controller_editEmployee(listaEmpleados);

                system("pause");
                break;

            case 5:
                system("cls");

                controller_removeEmployee(listaEmpleados);

                system("pause");
                break;

            case 6:
                system("cls");

                controller_ListEmployee(listaEmpleados);

                system("pause");
                break;

            case 7:
                system("cls");

                controller_sortEmployee(listaEmpleados);

                system("pause");
                break;

            case 8:
                system("cls");

                printf("Hay cargado %d empleados en el sistema.\n\n",ll_len(listaEmpleados));
                input_getOptionChar(&confirmaSave,"Confirmar Guardar [S/N]:","Caracter ingresado invalido",'S','N');
                if(confirmaSave=='S')
                {
                    system("cls");
                    controller_saveAsText(PATH_TXT,listaEmpleados);

                }else
                {
                    system("cls");
                    printf("Volviendo al Menu\n\n");
                }

                system("pause");
                break;

            case 9:
                system("cls");

                printf("Hay cargado %d empleados en el sistema.\n\n",ll_len(listaEmpleados));
                input_getOptionChar(&confirmaSave,"Confirmar Guardar [S/N]:","Caracter ingresado invalido",'S','N');
                if(confirmaSave=='S')
                {
                    system("cls");
                    controller_saveAsBinary(PATH_BIN,listaEmpleados);
                }else
                {
                    system("cls");
                    printf("Volviendo al Menu\n\n");
                }

                system("pause");
                break;

            case 10:
                system("cls");

                input_getOptionChar(&confirma,"Confirmar salir [S/N]:","Caracter ingresado invalido",'S','N');

                break;

            default:
                printf("///Opcion Incorrecta///\n\n");
                system("pause");
                break;
        }
    }while(confirma != 'S');

    return 0;
}
