#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#ifndef empleados_H_INCLUDED
#define empleados_H_INCLUDED
#include "empleados.h"
#endif // empleados_H_INCLUDED

#ifndef sectores_H_INCLUDED
#define sectores_H_INCLUDED
#include "sectores.h"
#endif // sectores_H_INCLUDED

#include "../Input/input.h"
/////////////////////////////////////////////////////////////////////////////////////////////////
int menuEmpleados()
{
    int opcion;

    system("cls");
    printf("1. Alta Empleado\n");
    printf("2. Modificar Empleado\n");
    printf("3. Baja Empleado\n");
    printf("4. INFORMES\n");
    printf("5. Salir\n\n");

    printf("Ingresar opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

int menuModificarEmpleados()
{
    int opcion;

    system("cls");
    printf("1. Apellido\n");
    printf("2. Nombre\n");
    printf("3. Sexo\n");
    printf("4. Salario\n");
    printf("5. Fecha de Ingreso\n");
    printf("6. Sector\n");
    printf("\n7. Salir\n");

    printf("Ingresar opcion: ");
    scanf("%d", &opcion);

    return opcion;
}
/////////////////////////////////////////////////////////////////////////////////////////////////
void inicializarEmpleados(eEmpleado emp[], int tam)
{
    for(int i=0; i<tam; i++)
    {
        emp[i].isEmpty=0;
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////
void hardCordeoEmpleados(eEmpleado emp[])
{
    eEmpleado empleados[] = {
    {1,{"Aranda","Lucho",'M'},70000,{6,11,2018},1,1},
    {2,{"Ahumada","Brian",'M'},13000,{10,5,2015},5,1},
    {3,{"Frias","Brenda",'F'},45000,{18,7,2017},3,1},
    {4,{"Alvarez","Tomas",'M'},55000,{12,9,2018},4,1},
    {5,{"Elena","Alvaro",'M'},20000,{14,5,2018},4,1},
    {6,{"Melana","Barbara",'F'},15000,{20,4,2019},2,1},
    {7,{"Ahumada","Kevin",'M'},25000,{9,12,2018},1,1},
    {8,{"Corteze","Lucho",'M'},35000,{27,10,2018},4,1}
    };

    for (int i = 0; i < 8; i++)
    {
        emp[i]= empleados[i];
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////
int autoLegajo(eEmpleado emp[], int tam)
{
    int legajo=1;

    for(int i=0; i<tam; i++)
    {
        if(emp[i].isEmpty==0)
        {
            emp[i].legajo=legajo;
            break;
        }else
        {
            legajo++;
        }
    }
    return legajo;
}

int buscarLibre(eEmpleado emp[], int tam)
{
    int indice= -1;
    int legajo= autoLegajo(emp, tam);

    for(int i=0; i<tam; i++)
    {
        if((emp[i].isEmpty==0 || emp[i].isEmpty==-1) && emp[i].legajo==legajo)
        {
           indice=i;
           break;
        }
    }

    return indice;
}

int buscarEmpleado(eEmpleado emp[], int tam)
{
    int indice = -1;
    int legajo;

    printf("Ingresa Legajo de Empleado: ");
    scanf("%d",&legajo);
    fflush(stdin);

    for ( int i = 0; i < tam; i++)
    {
        if ( emp[i].legajo == legajo && emp[i].isEmpty == 1 )
        {
            indice = i;
            break;
        }

    }
    return indice;
}

int contadorEmpleados(eEmpleado emp[], int tam)
{
    int contadorEmpleados=0;

    for(int i=0; i<tam; i++)
    {
        if(emp[i].isEmpty==1)
        {
            contadorEmpleados++;
        }
    }

    return contadorEmpleados;
}
/////////////////////////////////////////////////////////////////////////////////////////////////
void mostrarEmpleado(eEmpleado emp[], eSector sec[], int i)
{
    printf(" %04d | %-15s %-15s    %6.2f| %-7c %.2d/%.2d/%.4d        |%-30s\n",emp[i].legajo,emp[i].datosEmpleado.apellido,emp[i].datosEmpleado.nombre,emp[i].salario,emp[i].datosEmpleado.sexo,emp[i].fechaIngreso.dia,emp[i].fechaIngreso.mes,emp[i].fechaIngreso.anno,sec[(emp[i].idSector)-1].descripcion);
}
/////////////////////////////////////////////////////////////////////////////////////////////////
//ALTA EMPLEADO
int altaEmpleado(eEmpleado emp[], int tamEmp, eSector sec[], int tamSec)
{
    int altaExitosa= -1;
    int indice= buscarLibre(emp,tamEmp);

    if(indice==-1)
    {
        printf("No hay espacio en el sistema");
    }
    else
    {
        //APELLIDO
        getString(emp[indice].datosEmpleado.apellido ,"Ingresar Apellido: ","Cantidad de caracteres invalida",2,50);

        //NOMBRE
        getString(emp[indice].datosEmpleado.nombre,"Ingresar Nombre: ","Cantidad de caracteres invalida",2,50);

        //SEXO
        getOptionChar(&emp[indice].datosEmpleado.sexo,"Ingresar sexo [f/m]: ","El sexo solo puede ser F o M",'f','m');
        fflush(stdin);

        //SALARIO
        getFloat(&emp[indice].salario,"Ingrese salario del Empleado: ","Salario ingresado invalido. El salario valido es [12000-90000]",12000,90000);

        //FECHA DE INGRESO
        printf("\nFecha de INGRESO\n");
        getInt(&emp[indice].fechaIngreso.dia,"Ingrese el dia de ingreso:","Dia invalido",1,31);

        getInt(&emp[indice].fechaIngreso.mes,"Ingrese el mes de ingreso:","Mes invalido",1,12);

        getInt(&emp[indice].fechaIngreso.anno,"Ingrese el anno de ingreso:","Anno invalido",1900,2019);

        //SECTOR
        mostrarSectores(sec,tamSec);

        getInt(&emp[indice].idSector,"\nIngrese el numero de sector: ","Error, sector invalido",1,5);

        //FIN DEL REGISTRO DE EMPLEADO
        emp[indice].isEmpty=1;

        system("cls");
        printf("Alta de Empleado Exitosa\n\n");

        altaExitosa=1;

    }
    return altaExitosa;
}
/////////////////////////////////////////////////////////////////////////////////////////////////
//BAJA EMPLEADO
int bajaEmpleado(eEmpleado emp[], int tamEmp, eSector sec[])
{
    int bajaExitosa=-1;
    int indice=-1;
    char respuesta;
    int hayEmpleados= contadorEmpleados(emp,tamEmp);

    if(hayEmpleados>=1)
    {
        indice = buscarEmpleado(emp, tamEmp);

        if ( emp[indice].isEmpty == 1)
        {
            printf("\nEl siguiente empleado se eliminara del Sistema\n");
            printf("\nLegajo| Apellido        Nombre               Sueldo| Sexo    DD/MM/AAAA        |Sector\n\n");
            mostrarEmpleado(emp,sec,indice);

            getOptionChar(&respuesta,"\nConfirmar Baja de Empleado [S/N]","Solo puede ingresar [S/N]",'s','n');

            if (respuesta == 'S')
            {
                emp[indice].isEmpty = -1;
                printf("\n\nEl empleado se ha eliminado correctamente\n\n");
                bajaExitosa=1;

            }else
            {
                printf("\n\nVolviendo al Menu Principal\n\n");
            }

        }else
        {
            printf("\nNo se ha encontrado un empleado en el sistema con el legajo ingresado.\n\n");
        }

    }else
    {
        printf("No hay Empleados en el Sistema\n\n");
    }

    return bajaExitosa;
}
/////////////////////////////////////////////////////////////////////////////////////////////////
//MODIFICAR EMPLEADO
void modificarEmpleado(eEmpleado emp[], int tamEmp, eSector sec[], int tamSec)
{
    char continuar='s';
    char confirma;
    char respuesta;
    int indice=-1;
    int hayEmpleados= contadorEmpleados(emp,tamEmp);

    if(hayEmpleados>=1)
    {
        indice= buscarEmpleado(emp,tamEmp);

        if ( emp[indice].isEmpty == 1)
        {
            printf("\nEl siguiente empleado sera modificado\n");
            printf("\nLegajo| Apellido        Nombre               Sueldo| Sexo    DD/MM/AAAA        |Sector\n\n");
            mostrarEmpleado(emp,sec,indice);

            getOptionChar(&respuesta,"\nConfirmar Modificacion del Empleado [S/N]","Solo puede ingresar [S/N]",'s','n');

            if (respuesta == 'S')
            {
                do
                {
                    switch(menuModificarEmpleados())
                    {
                        case 1:
                            system("cls");

                            //APELLIDO
                            getString(emp[indice].datosEmpleado.apellido ,"Ingresar Apellido: ","Cantidad de caracteres invalida",2,50);

                            system("pause");
                            break;

                        case 2:
                            system("cls");

                            //NOMBRE
                            getString(emp[indice].datosEmpleado.nombre,"Ingresar Nombre: ","Cantidad de caracteres invalida",2,50);

                            system("pause");
                            break;

                        case 3:
                            system("cls");

                            //SEXO
                            getOptionChar(&emp[indice].datosEmpleado.sexo,"Ingresar sexo [f/m]: ","El sexo solo puede ser F o M",'f','m');
                            fflush(stdin);

                            system("pause");
                            break;

                        case 4:
                            system("cls");

                            //SALARIO
                            getFloat(&emp[indice].salario,"Ingrese salario del Empleado: ","Salario ingresado invalido. El salario valido es [12000-70000]",12000,70000);

                            system("pause");
                            break;
                        case 5:
                            system("cls");

                            //FECHA DE INGRESO
                            printf("\nFecha de INGRESO\n");
                                getInt(&emp[indice].fechaIngreso.dia,"Ingrese el dia de ingreso:","Dia invalido",1,31);

                                getInt(&emp[indice].fechaIngreso.mes,"Ingrese el mes de ingreso:","Mes invalido",1,12);

                                getInt(&emp[indice].fechaIngreso.anno,"Ingrese el anno de ingreso:","Anno invalido",1900,2000);

                            system("pause");
                            break;
                        case 6:
                            system("cls");

                            //SECTOR
                            printf("SECTOR del empleado\n");
                            for (int i = 0; i < tamSec; i++)
                            {
                                printf("%d. %s\n", i+1, sec[i].descripcion);
                            }

                            getInt(&emp[indice].idSector,"\nIngrese el numero de sector: ","Error, sector invalido",1,5);

                            system("pause");
                            break;

                        case 7:
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


            }else
            {
                printf("\n\nVolviendo al Menu Principal\n\n");
            }

        }else
        {
            printf("\nNo se ha encontrado un empleado en el sistema con el legajo ingresado.\n\n");
        }

    }else
    {
        printf("No hay Empleados en el Sistema\n\n");
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////
//INFORMES
void listarEmpleados(eEmpleado emp[],int tamEmp, eSector sec[],int tamSec)
{
    int hayEmpleados=contadorEmpleados(emp,tamEmp);

    if(hayEmpleados>=1)
    {
        ordenarEmpleados(emp,tamEmp);

        printf("Legajo| Apellido        Nombre               Sueldo| Sexo    DD/MM/AAAA        |Sector\n\n");

        for(int i=0; i<tamEmp; i++)
        {
            for(int j=0; j<tamSec; j++)
            {
                if(emp[i].isEmpty==1 && emp[i].idSector==sec[j].idSector)
                {
                    printf(" %04d | %-15s %-15s    %6.2f| %-7c %.2d/%.2d/%.4d        |%-30s\n",emp[i].legajo,emp[i].datosEmpleado.apellido,emp[i].datosEmpleado.nombre,emp[i].salario,emp[i].datosEmpleado.sexo,emp[i].fechaIngreso.dia,emp[i].fechaIngreso.mes,emp[i].fechaIngreso.anno,sec[j].descripcion);
                }
            }
        }
        printf("\n");
    }else
    {
        printf("No hay Empleados en el Sistema\n\n");
    }
}

void ordenarEmpleados(eEmpleado emp[], int tamEmp)
{
    eEmpleado empAux;

    for(int i=0; i< tamEmp; i++)
    {
        for(int j=i+1; j< tamEmp; j++)
        {
            if((emp[i].isEmpty==1 && emp[j].isEmpty==1) && (emp[i].idSector > emp[j].idSector))
            {
               empAux= emp[i];
               emp[i]=emp[j];
               emp[j]=empAux;
            }
        }
    }

    for(int i=0; i< tamEmp; i++)
    {
        for(int j=i+1; j< tamEmp; j++)
        {
            if((emp[i].isEmpty==1 && emp[j].isEmpty==1) && (stricmp(emp[i].datosEmpleado.apellido, emp[j].datosEmpleado.apellido)>0))
            {
               empAux= emp[i];
               emp[i]=emp[j];
               emp[j]=empAux;
            }
        }
    }
}

void promediosEmpleados(eEmpleado emp[], int tamEmp, eSector sec[])
{
    int totalEmpleados= contadorEmpleados(emp,tamEmp);
    float totalSalario=0;
    float promedioSalarios=0;

    if(totalEmpleados>=1)
    {
        for(int i=0; i<tamEmp; i++)
        {
            if(emp[i].isEmpty==1)
            {
                totalSalario= totalSalario+ emp[i].salario;
            }
        }

        promedioSalarios=totalSalario/totalEmpleados;

        printf("|| Total de Empleados: %d\n", totalEmpleados);
        printf("|| Total de los Salarios: %.2f\n", totalSalario);
        printf("|| Promedio de los Salarios: %.2f\n",promedioSalarios);

        printf("\n\nEMPLEADOS QUE SUPERAN EL PROMEDIO DEL SALARIO\n");
        printf("\nLegajo| Apellido        Nombre               Sueldo| Sexo    DD/MM/AAAA        |Sector\n\n");
        for(int i=0; i<tamEmp; i++)
        {
            if(emp[i].isEmpty==1 && (emp[i].salario >= promedioSalarios))
            {
                mostrarEmpleado(emp,sec,i);
            }
        }
        printf("\n");

    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////
