#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef empleados_H_INCLUDED
#define empleados_H_INCLUDED
#include "Empleados.h"
#endif // empleados_H_INCLUDED

#ifndef input_H_INCLUDED
#define input_H_INCLUDED
#include "../Input/input.h"
#endif // input_H_INCLUDED


int menuEmpleados()
{
    int option=0;

    system("cls");
    printf("1. Alta Empleado\n");
    printf("2. Modificar Empleado\n");
    printf("3. Baja Empleado\n");
    printf("4. Informar\n");
    printf("5. Salir\n\n");

    printf("Ingresar opcion: ");
    scanf("%d",&option);

    if(option<1 || option>5)
    {
        printf("\n///Opcion Ingresada Incorrecta///\n");
        system("pause");
    }

    return option;
}

int initEmployees(eEmpleado* listEmployees, int lenght)
{
    int ok=-1;

    if(listEmployees!=NULL && lenght>=1)
    {
        for(int i=0; i<lenght; i++)
        {
            (listEmployees+i)->isEmpty=0;

            ok=0;
        }
    }

    return ok;
}

int findId(eEmpleado* listEmployee, int lenght, int* idEmployee)
{
    int ok=-1;
    int auxId=1;

    if(listEmployee!=NULL)
    {
        for(int i=0; i<lenght; i++)
        {
            if((listEmployee+i)->isEmpty == 0)
            {
                *idEmployee=auxId;
                ok=0;
                break;

            }else
            {
                auxId++;
            }
        }
    }
    return ok;
}

int findEmployeeById(eEmpleado* listEmployee, int length,int id)
{
    int indice=-1;

    if(listEmployee!=NULL)
    {
        for(int i=0; i<length; i++)
        {
            if( ((listEmployee+i)->id == id) && ((listEmployee+i)->isEmpty == 1))
            {
                indice=i;
            }
        }
    }

    return indice;
}

int findFree(eEmpleado* listEmployee, int length)
{
    int indice=-1;

    if(listEmployee!=NULL)
    {
        for(int i=0; i<length; i++)
        {
            if((listEmployee+i)->isEmpty == 0)
            {
                indice=i;
                break;
            }
        }
    }
    return indice;
}

int altaEmpleado(eEmpleado* listEmployee, int length)
{
    eEmpleado* empleado = (eEmpleado*)malloc(sizeof(eEmpleado));
    int ok=-1;

    if(empleado!=NULL && listEmployee!=NULL)
    {
        int indice = findFree(listEmployee,length);

        if(indice!=-1)
        {
            findId(listEmployee,length,&empleado->id);

            getString(empleado->lastName,"Ingresar Apellido:","ERROR al cargar [min: 2 caracteres - max: 50 caracteres]",2,50);

            getString(empleado->name,"Ingresar Nombre:","ERROR al cargar [min: 2 caracteres - max: 50 caracteres]",2,50);

            getFloat(&empleado->salary,"Ingresar sueldo:","ERROR al cargar [sueldo min: 12000 - sueldo max: 120000]",12000,120000);

            getInt(&empleado->sector,"Ingresar id de Sector [1-5]:","ERROR al cargar [min: 1 - max: 5]",1,5);

            empleado->isEmpty=0;
        }else
        {
            printf("No se encontro un lugar disponible\n\n");
        }

        ok= addEmployee(listEmployee,length,empleado->id,empleado->name,empleado->lastName,empleado->salary,empleado->sector,indice);

        free(empleado);

    }

    return ok;
}


int addEmployee(eEmpleado* listEmployee, int length, int id, char name[],char lastName[],float salary,int sector, int indice)
{
    int ok=-1;

    if(listEmployee!=NULL)
    {
        if(indice!=-1)
        {
            system("cls");
            (listEmployee+indice)->id = id;
            strcpy((listEmployee+indice)->lastName,lastName);
            strcpy((listEmployee+indice)->name,name);
            (listEmployee+indice)->salary= salary;
            (listEmployee+indice)->sector= sector;
            (listEmployee+indice)->isEmpty=1;
            printf("Alta de Empleado Exitosa\n\n");
            ok=0;

        }
    }
    return ok;
}

int bajaEmpleado(eEmpleado* listEmployee, int length)
{
    int ok=-1;

    if(listEmployee!= NULL)
    {
        int id;

        getInt(&id,"Ingresar ID de Empleado:","ID de Empleado ingresado no es valido",0,length);

        ok = removeEmployee(listEmployee,length,id);

    }

    return ok;
}

int removeEmployee(eEmpleado* listEmployee, int length, int id)
{
    int ok=-1;

    if(listEmployee!=NULL)
    {
        int indiceID;
        char confirma;

        indiceID= findEmployeeById(listEmployee,length,id);

        if(indiceID!=-1)
        {
            printEmployee(listEmployee,indiceID);
            getOptionChar(&confirma,"\nConfirmar Baja de Empleado [s/n]:","Para confirmar ingrese [s/n]",'S','N');
            if(confirma=='S')
            {
                system("cls");
                (listEmployee+indiceID)->isEmpty=-1;
                printf("Baja de Empleado Exitosa\n\n");
                ok=0;
            }else
            {
                system("cls");
                printf("Baja de Empleado Cancelada\n\n");
            }

        }else
        {
            printf("\nID de Empleado no Encontrado\n\n");
        }
    }

    return ok;
}

void printEmployee(eEmpleado* listEmployee, int index)
{
    if((listEmployee+index)->isEmpty==1)
    {
        printf("ID: %d   Apellido: %s   Nombre: %s   Sueldo: %.2f   ID Sector: %d   isEmpty: %d\n",(listEmployee+index)->id,(listEmployee+index)->lastName,(listEmployee+index)->name,(listEmployee+index)->salary,(listEmployee+index)->sector,(listEmployee+index)->isEmpty);
    }
}

void printEmployees(eEmpleado* listEmployee, int length)
{
    for(int i=0; i<length; i++)
    {
        printEmployee(listEmployee,i);
    }
}







