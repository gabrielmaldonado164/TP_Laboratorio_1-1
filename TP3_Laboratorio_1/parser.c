#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int allOK=-1;
    int cant;
    char buffer[4][50];

    if(pFile!=NULL)
    {
        ll_clear(pArrayListEmployee);//BORRO LA LECTURA ANTERIOR
        fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]); // LECTURA FANTASMA

        do
        {
            cant= fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);

            if ( cant == 4 )
            {
                Employee* newEmployee= employee_new();

                if(newEmployee!=NULL)
                {
                    newEmployee= employee_newParametros(buffer[0], buffer[1], buffer[2], buffer[3]);
                    ll_add(pArrayListEmployee,newEmployee);

                }else
                {
                    printf("ERROR! La carga no se completo\n\n");
                    break;
                }
            }

        }while(!feof(pFile));

        allOK=(!feof(pFile));
    }

    return allOK;
}

/** \brief Parsea los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int allOK=-1;
    int cant;

    if(pFile!= NULL)
    {
        ll_clear(pArrayListEmployee);//BORRO LA LECTURA ANTERIOR

        do
        {
            Employee* newEmployee= employee_new();
            cant= fread(newEmployee,sizeof(Employee),1,pFile);

            if ( cant == 1 )
            {
                if(newEmployee!=NULL)
                {
                    ll_add(pArrayListEmployee,newEmployee);

                }else
                {
                    printf("ERROR! La carga no se completo\n\n");
                    break;
                }
            }

        }while(!feof(pFile));

        allOK=(!feof(pFile));

    }

    return allOK;
}
