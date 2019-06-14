#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "Input.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* file= fopen(path,"r");
    int allOK=-1;

    if(file!=NULL && pArrayListEmployee!=NULL)
    {
<<<<<<< HEAD
        allOK= parser_EmployeeFromText(file,pArrayListEmployee);
=======

>>>>>>> 0c1a78d4375fb59966483d6bc3714f33f7a60238

        if(allOK==0)
        {
            printf("Se han cargado los archivos correctamente\n\n");
        }else
        {
            printf("No se han cargado los archivos correctamente\n\n");
        }

    }else
    {
        printf("El archivo \"%s\" no ha sido encontrado\n\n",path);
    }

    fclose(file);

    return allOK;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int allOK=-1;

    FILE* file= fopen(path,"rb");

    if(file!=NULL && pArrayListEmployee!=NULL)
    {
        allOK= parser_EmployeeFromBinary(file,pArrayListEmployee);

        if(allOK==0)
        {
            printf("Se han cargado los archivos correctamente\n\n");
        }else
        {
            printf("No se han cargado los archivos correctamente\n\n");
        }
    }else
    {
        printf("El archivo \"%s\" no ha sido encontrado\n\n",path);
    }

    fclose(file);

    return allOK;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int allOK=-1;

    if(pArrayListEmployee!=NULL)
    {
        Employee* newEmployee= employee_new();
        Employee* auxEmployee= employee_new();

        if(newEmployee!=NULL && auxEmployee!=NULL)
        {
            int id=0;
            for(int i = 0; i < ll_len(pArrayListEmployee); i++ )
            {
                auxEmployee = ll_get(pArrayListEmployee, i);
                if(auxEmployee->id > id)
                {
                    id = auxEmployee->id;
                }
            }
            auxEmployee= employee_new();

            if(employee_getId(newEmployee,&id))
            {
                if(employee_getNombre(newEmployee,auxEmployee->nombre))
                {
                    if(employee_getHorasTrabajadas(newEmployee,&auxEmployee->horasTrabajadas))
                    {
                        if(employee_getSueldo(newEmployee,&auxEmployee->sueldo))
                        {
                            if((ll_add(pArrayListEmployee,newEmployee))==0)
                            {
                                system("cls");
                                printf("Se ha cargado el empleado exitosamente\n\n");
                                allOK=0;
                            }
                        }
                    }
                }
            }
        }
        free(auxEmployee);
    }

    return allOK;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int allOK=-1;
    int findEmployee=-1;
    int id=0;

    if(pArrayListEmployee!=NULL)
    {
        if(ll_len(pArrayListEmployee)>0)
        {
            printf("Ingrese ID de Empleado: ");
            fflush(stdin);
            scanf("%d",&id);

            Employee* employee= employee_new();

            if(employee!=NULL)
            {
                for(int i=0; i<ll_len(pArrayListEmployee); i++)
                {
                    employee= ll_get(pArrayListEmployee,i);
                    if(employee->id == id)
                    {
                        findEmployee=1;
                        break;
                    }
                }

                if(findEmployee==1)
                {
                    char confirma='N';
                    printf("\n ID |NOMBRE                    |HORAS TRABAJADAS|SUELDO\n");
                    printf("%04d| %-25s| %-15d|%-6d\n",employee->id,employee->nombre,employee->horasTrabajadas,employee->sueldo);

                    input_getOptionChar(&confirma,"\nConfirmar Modificar el Empleado Mostrado [S/N]:","Caracter ingresado invalido",'S','N');

                    if(confirma=='S')
                    {
                        int option=0;
                        allOK=0;
                        do
                        {
                            option=0;
                            confirma='N';
                            system("cls");
                            printf("MENU DE MODIFICAR EMPLEADO\n\n");
                            printf("1. Modificar Nombre\n");
                            printf("2. Modificar Horas Trabajadas\n");
                            printf("3. Modificar Sueldo\n");
                            printf("4. Salir\n");

                            printf("\nIngresar opcion: ");
                            fflush(stdin);
                            scanf("%d", &option);

                            switch(option)
                            {
                                case 1:
                                    system("cls");
                                    employee_getNombre(employee,employee->nombre);
                                    break;

                                case 2:
                                    system("cls");
                                    employee_getHorasTrabajadas(employee,&employee->horasTrabajadas);
                                    break;

                                case 3:
                                    system("cls");
                                    employee_getSueldo(employee,&employee->sueldo);
                                    break;

                                case 4:
                                    system("cls");
                                    input_getOptionChar(&confirma,"Confirmar salir [S/N]:","Caracter ingresado invalido",'S','N');
                                    break;

                                default:
                                    printf("///Opcion Incorrecta///\n\n");
                                    system("pause");
                                    break;
                            }
                        }while(confirma!='S');
                    }else
                    {
                        system("cls");
                        printf("Volviendo al Menu de Empleados\n\n");
                    }
                }else
                {
                    system("cls");
                    printf("No se ha encontrado el empleado\n\n");
                }
            }
        }else
        {
            printf("No hay empleados para modificar\n\n");
        }
    }
    return allOK;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int allOK=-1;
    int findEmployee=-1;
    int indice;
    int id=0;

    if(pArrayListEmployee!=NULL)
    {
        if(ll_len(pArrayListEmployee)>0)
        {
            printf("Ingrese ID de Empleado: ");
            fflush(stdin);
            scanf("%d",&id);

            Employee* employee= employee_new();

            if(employee!=NULL)
            {
                for(int i=0; i<ll_len(pArrayListEmployee); i++)
                {
                    employee= ll_get(pArrayListEmployee,i);
                    if(employee->id == id)
                    {
                        findEmployee=1;
                        indice= i;
                        break;
                    }
                }

                if(findEmployee==1)
                {
                    char confirma='N';
                    printf("\n ID |NOMBRE                    |HORAS TRABAJADAS|SUELDO\n");
                    printf("%04d| %-25s| %-15d|%-6d\n",employee->id,employee->nombre,employee->horasTrabajadas,employee->sueldo);

                    input_getOptionChar(&confirma,"\nConfirmar Eliminar el Empleado Mostrado [S/N]:","Caracter ingresado invalido",'S','N');

                    if(confirma=='S')
                    {
                        allOK=ll_remove(pArrayListEmployee,indice);
                        printf("\nEmpleado Eliminado Correctamente\n\n");
                    }else
                    {
                        system("cls");
                        printf("Volviendo al Menu de Empleados\n\n");
                    }
                }else
                {
                    system("cls");
                    printf("No se ha encontrado el empleado\n\n");
                }
            }
        }else
        {
            printf("No Hay Empleados para Eliminar\n\n");
        }
    }
    return allOK;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int allOK=-1;
    int length= ll_len(pArrayListEmployee);

    if(pArrayListEmployee!=NULL)
    {
        if(length>0)
        {
            Employee* employee= employee_new();

            if(employee!=NULL)
            {
                printf(" ID |NOMBRE                    |HORAS TRABAJADAS|SUELDO\n");
                for(int i=0; i<length; i++)
                {
                    employee= ll_get(pArrayListEmployee,i);
                    printf("%04d| %-25s| %-15d|%-6d\n",employee->id,employee->nombre,employee->horasTrabajadas,employee->sueldo);
                }
                printf("\n");
                allOK=0;
            }
        }else
        {
            printf("No hay empleados para listar\n\n");
        }
    }

    return allOK;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int allOK=-1;

    if(pArrayListEmployee!=NULL)
    {
        int length= ll_len(pArrayListEmployee);
        if(length>0)
        {
            Employee* employee= employee_new();
            Employee* auxEmployee= employee_new();

            if(employee!=NULL && auxEmployee!=NULL)
            {
                printf("Ordenando Empleados...");
                for(int i=0; i<length-1;i++)
                {
                    for(int j=i+1;j<length;j++)
                    {
                        employee= ll_get(pArrayListEmployee,i);
                        auxEmployee= ll_get(pArrayListEmployee,j);
                        if(stricmp(employee->nombre,auxEmployee->nombre)>0)
                        {
                            ll_set(pArrayListEmployee,j,employee);
                            ll_set(pArrayListEmployee,i,auxEmployee);
                        }
                    }
                }
                system("cls");
                printf("Empleados Ordenados Alfabeticamente\n\n");
                allOK=0;
            }

        }else
        {
            printf("No Hay Empleados para Ordenar\n\n");
        }
    }


    return allOK;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    int allOK=-1;

    FILE* file= fopen(path,"w");

    if(file!=NULL && pArrayListEmployee!=NULL)
    {
        Employee* employee= employee_new();

        if(employee!=NULL)
        {
            fprintf(file,"id,nombre,horasTrabajadas,sueldo\n");

            for(int i=0; i<ll_len(pArrayListEmployee);i++)
            {
                employee= ll_get(pArrayListEmployee,i);
                fprintf(file,"%d,%s,%d,%d\n",employee->id,employee->nombre,employee->horasTrabajadas,employee->sueldo);
            }
            printf("Se han guardado los datos en el archivo correctamente\n\n");
            allOK=0;
        }

    }else
    {
        printf("El archivo \"%s\" no ha sido encontrado\n\n",path);
    }

    fclose(file);

    return allOK;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int allOK=-1;

    FILE* file= fopen(path,"wb");

    if(file!=NULL && pArrayListEmployee!=NULL)
    {
        Employee* employee= employee_new();

        if(employee!=NULL)
        {

            for(int i=0; i<ll_len(pArrayListEmployee);i++)
            {
                employee= ll_get(pArrayListEmployee,i);
                fwrite(employee, sizeof(Employee), 1, file);
            }
            printf("Se han guardado los datos en el archivo correctamente\n\n");
            allOK=0;
        }

    }else
    {
        printf("El archivo \"%s\" no ha sido encontrado\n\n",path);
    }

    fclose(file);

    return allOK;
}

