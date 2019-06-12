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
    /*int cant;
    char buffer[4][50];

    fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]); // LECTURA FANTASMA
    ll_clear(pArrayListEmployee); // CON ESTO BORRO LA LISTA EN CASO DE QUE CONTENGA DATOS PREVIOS

    while(!feof(pFile))
    {
        cant= fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);

        if ( cant < 4 )
        {
            if(feof(pFile))
            {
                break;
            }
            else
            {
                printf("No se llego al final");
                break;
            }
        }
    }*/

    return 1;
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

    return 1;
}
