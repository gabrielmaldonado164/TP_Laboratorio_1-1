#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Employee.h"
#include "LinkedList.h"

Employee* employee_new()
{
    Employee* newEmployee= (Employee*) malloc(sizeof(Employee));
    if(newEmployee!=NULL)
    {
        newEmployee->id=0;
        strcpy(newEmployee->nombre," ");
        newEmployee->horasTrabajadas=0;
        newEmployee->sueldo=0;
    }

    return newEmployee;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
    Employee* newEmployee= employee_new();

    if(newEmployee!=NULL)
    {
        newEmployee->id= atoi(idStr);
        strcpy(newEmployee->nombre,nombreStr);
        newEmployee->horasTrabajadas= atoi(horasTrabajadasStr);
        newEmployee->sueldo= atoi(sueldoStr);
    }

    return newEmployee;
}

void employee_delete();

int employee_getId(Employee* this, int* id)
{
    int allOK=0;

    if(this!= NULL)
    {
        *id=*id+1;
        allOK=employee_setId(this,*id);
    }

    return allOK;
}

int employee_setId(Employee* this,int id)
{
    int allOK=0;

    if(this!=NULL)
    {
        if(id>0)
        {
            this->id=id;
            allOK=1;
        }
    }
    return allOK;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int allOK=0;

    if(this!=NULL)
    {
        do
        {
            printf("Ingresar Nombre: ");
            fflush(stdin);
            gets(nombre);

        }while(employee_setNombre(this,nombre)==0);

        strcpy(this->nombre, nombre);
        allOK=1;
    }
    return allOK;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int allOK=0;

    if(this!=NULL)
    {
        if(strlen(nombre)>1 && strlen(nombre)<128)
        {
            for(int i=0;nombre[i]!='\0';i++)
            {
                if((nombre[i]>='A' && nombre[i]<='Z') || (nombre[i]>='a' && nombre[i]<='z'))
                {
                    allOK=1;
                }else
                {
                    printf("/// ERROR! El nombre ingresado debe contener unicamente letras y contener [1-127] caracteres ///\n\n");
                    allOK=0;
                    break;
                }
            }
        }
    }

    return allOK;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int allOK=0;

    if(this!=NULL)
    {
        do
        {
            printf("Ingresar Horas Trabajadas: ");
            fflush(stdin);
            scanf("%d",horasTrabajadas);

        }while(employee_setHorasTrabajadas(this,*horasTrabajadas)==0);

        this->horasTrabajadas= *horasTrabajadas;
        allOK=1;
    }
    return allOK;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int allOK=0;

    if(this!=NULL)
    {
        if(horasTrabajadas>0 && horasTrabajadas<=480)
        {
            allOK=1;
        }else
        {
            printf("/// ERROR! La horas trabajadas ingresadas no son validas, ingrese dentro de los parametros [1-480] ///\n\n");
        }
    }

    return allOK;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
    int allOK=0;

    if(this!=NULL)
    {
        do
        {
            printf("Ingresar Sueldo: ");
            fflush(stdin);
            scanf("%d",sueldo);

        }while(employee_setSueldo(this,*sueldo)==0);

        this->sueldo= *sueldo;
        allOK=1;
    }
    return allOK;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int allOK=0;

    if(this!=NULL)
    {
        if(sueldo>=8000 && sueldo<=90000)
        {
            allOK=1;
        }else
        {
            printf("/// ERROR! El sueldo ingresado no es valido, ingrese dentro de los parametros [8000-90000] ///\n\n");
        }
    }

    return allOK;
}
