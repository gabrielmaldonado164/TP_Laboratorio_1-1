typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

}eEmpleado;

/* Estado de los Empleados
 * isEmpty=0: Lugar disponible
 * isEmpty=1: Empleado Activo
 * isEmpty=-1: Empleado Inactivo (dado de baja)
*/

int menuEmpleados();

int initEmployees(eEmpleado* listEmployees, int lenght);

int findId(eEmpleado* listEmployee, int lenght, int* idEmployee);

int findEmployeeById(eEmpleado* listEmployee, int length,int id);

int findFree(eEmpleado* listEmployee, int length);

int altaEmpleado(eEmpleado* listEmployee, int length);

int addEmployee(eEmpleado* listEmployee, int length, int id, char name[],char lastName[],float salary,int sector, int indice);

int bajaEmpleado(eEmpleado* listEmployee, int length);

int removeEmployee(eEmpleado* listEmployee, int length, int id);


void printEmployee(eEmpleado* listEmployee, int index);

void printEmployees(eEmpleado* listEmployee, int length);
