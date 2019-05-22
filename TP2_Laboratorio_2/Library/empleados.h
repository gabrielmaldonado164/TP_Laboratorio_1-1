#ifndef sectores_H_INCLUDED
#define sectores_H_INCLUDED
#include "sectores.h"
#endif // sectores_H_INCLUDED

typedef struct
{
    char apellido[51];
    char nombre[51];
    char sexo;

}eDatosPersonales;

typedef struct
{
    int dia;
    int mes;
    int anno;

}eFecha;

typedef struct
{
    int legajo;
    eDatosPersonales datosEmpleado;
    float salario;
    eFecha fechaIngreso;
    int idSector;
    int isEmpty;

}eEmpleado;
/////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Muestra el menu de Empleados
 *
 * \return int Opcion mostrada en el Menu
 */
int menuEmpleados();

/** \brief Muestra el menu de Modificacion de Empleados
 *
 * \return int Opcion mostrada en el Menu
 */
int menuModificarEmpleados();
/////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Inicializa todos los empleados en 0
 *
 * \param emp[] eEmpleado Es el vector de empleados
 * \param tam int Es el tamaño del vector de empleados
 * \return void
 *
 */
void inicializarEmpleados(eEmpleado emp[], int tam);
/////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Hardcodea Empleados para prueba
 *
 * \param emp[] eEmpleado Es el vector de empleados
 * \return void
 *
 */
void hardCordeoEmpleados(eEmpleado emp[]);
/////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Asigna el valor automatico del Legajo
 *
 * \param emp[] eEmpleado Es el vector de empleados
 * \param tam int Es el tamaño del vector de empleados
 * \return int El legajo correspondiente a un lugar vacio
 *
 */
int autoLegajo(eEmpleado emp[], int tam);

/** \brief Busca un lugar libre en un vector de Empleados
 *
 * \param emp[] eEmpleado Es el vector de empleados
 * \param tam int Es el tamaño del vector de empleados
 * \return int [-1] si el no hay lugar libre sino el indice libre en el vector
 */
int buscarLibre(eEmpleado emp[], int tam);

/** \brief Solicita un legajo y busca si este existe
 *
 * \param emp[] eEmpleado Es el vector de empleados
 * \param tam int Es el tamaño del vector de empleados
 * \return int int [-1] si el no encontro el legajo ingresado y sino retorna el indice del legajo en el vector
 */
int buscarEmpleado(eEmpleado emp[], int tam);

/** \brief Cuenta los empleados
 *
 * \param emp[] eEmpleado Es el vector de empleados
 * \param tam int Es el tamaño del vector de empleados
 * \return int La cantidad de empleados en el vector
 */
int contadorEmpleados(eEmpleado emp[], int tam);
/////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Muestra los datos del empleado
 *
 * \param emp[] eEmpleado Es el vector de empleados
 * \param sec[] eSector Es el tamaño del vector de empleados
 * \param i int Es el indice del vector de empleados
 * \return void

 */
void mostrarEmpleado(eEmpleado emp[], eSector sec[], int i);
/////////////////////////////////////////////////////////////////////////////////////////////////
//ALTA EMPLEADO
/** \brief Pide datos de un empleado nuevo y lo registra
 *
 * \param emp[] eEmpleado Es el vector de empleados
 * \param tam int Es el tamaño del vector de empleados
 * \param sec[] eSector Es el vector de Sectores
 * \param tamSec int Es el tamaño del vector de empleados
 * \return int [1] si el empleado se registro con exito y [-1] si no se registro
 */
int altaEmpleado(eEmpleado emp[], int tam, eSector sec[], int tamSec);
/////////////////////////////////////////////////////////////////////////////////////////////////
//BAJA EMPLEADO
/** \brief Solicita un legajo, verifica el empleado y lo da de baja
 *
 * \param emp[] eEmpleado Es el vector de empleados
 * \param tamEmp int Es el tamaño del vector de empleados
 * \param sec[] eSector
 * \return int [1] si el empleado se dio de baja con exito y [-1] si no se logro dar la baja
 */
int bajaEmpleado(eEmpleado emp[], int tamEmp, eSector sec[]);
/////////////////////////////////////////////////////////////////////////////////////////////////
//MODIFICAR EMPLEADO
/** \brief Solicita un legajo, verifica el empleado y da acceso al menu de Modificacion
 *
 * \param emp[] eEmpleado Es el vector de empleados
 * \param tamEmp int Es el tamaño del vector de empleados
 * \param sec[] eSector
 * \param tamSec int Es el tamaño del vector de sectores
 * \return void
 */
void modificarEmpleado(eEmpleado emp[], int tamEmp, eSector sec[], int tamSec);
/////////////////////////////////////////////////////////////////////////////////////////////////
//INFORMES
/** \brief Muestra todos los empleados en alta
 *
 * \param emp[] eEmpleado Es el vector de empleados
 * \param tamEmp int Es el tamaño del vector de empleados
 * \param sec[] eSector Es el vector de sectores
 * \param tamSec int Es el tamaño del vector de sectores
 * \return void
 *
 */
void listarEmpleados(eEmpleado emp[],int tamEmp, eSector sec[],int tamSec);

/** \brief Ordena un vector de empleados alfabeticamente por Apellido y Sector
 *
 * \param emp[] eEmpleado Es el vector de empleados
 * \param tamEmp int Es el tamaño del vector de empleados
 * \return void
 */
void ordenarEmpleados(eEmpleado emp[], int tamEmp);

/** \brief Muestra el total y promedio de los salarios, y cuantos empleados superan el salario promedio
 *
 * \param emp[] eEmpleado Es el vector de empleados
 * \param tamEmp int Es el tamaño del vector de empleados
 * \param sec[] eSector Es el vector de sectores
 * \return void
 */
void promediosEmpleados(eEmpleado emp[], int tamEmp, eSector sec[]);
/////////////////////////////////////////////////////////////////////////////////////////////////
