#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

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
    int option = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();

    do{
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

        printf("\nque desea hacer?: ");
        scanf("%d", &option);

        switch(option)
        {
            case 1:
                system("cls");



                system("pause");
                break;

            case 2:
                system("cls");



                system("pause");
                break;

            case 3:


                system("pause");
                break;

            case 4:
                break;

            case 5:


                break;

            case 6:

                system("pause");
                break;

            case 7:
                system("cls");



                system("pause");
                break;

            case 8:

                system("pause");
                break;

            case 9:

                system("pause");
                break;

            case 10:
                printf("Saliendo del programa... \n\n");
                system("pause");
                break;
        }
    }while(option != 10);

    return 0;
}
