#include <stdio.h>
#include <stdlib.h>
#include "Library/calculos.h"

int main()
{
    int menuOpciones;
    float operandoUno;
    float operandoDos;
    float suma;
    float resta;
    float division;
    float multiplicacion;
    int factorialUno;
    int factorialDos;
    int realizarCalculos;

    operandoUno=0;
    operandoDos=0;
    menuOpciones=0;
    realizarCalculos=0;

    while(menuOpciones!=5)
    {
        system("cls");
        printf("Menu de Opciones:\n1. Ingresar el primer operando (A= %0.2f)\n2. Ingresar el segundo operando (B= %0.2f)\n3. Calcular todas las operaciones\n4. Informar resultados\n5. Salir\n", operandoUno, operandoDos);
        printf("Seleccione la operacion que desea realizar: ");
        scanf("%d", &menuOpciones);
        fflush(stdin);

        switch(menuOpciones)
        {
            case 1:
                printf("Ingresar primer operando: ");
                scanf("%f", &operandoUno);
                break;

            case 2:
                printf("Ingresar segundo operando: ");
                scanf("%f", &operandoDos);
                break;

            case 3:
                suma= sumar(operandoUno, operandoDos);
                resta= restar(operandoUno, operandoDos);
                division= dividir(operandoUno, operandoDos);
                multiplicacion= multiplicar(operandoUno, operandoDos);
                factorialUno= factoriar(operandoUno);
                factorialDos= factoriar(operandoDos);
                printf("\nSe han realizado las operaciones correspondientes\n");
                realizarCalculos=1;
                break;

            case 4:

                if(realizarCalculos==1)
                {
                    printf("\nEl resultado de A+B es: %0.2f\n", suma);

                    printf("El resultado de A-B es: %0.2f\n", resta);

                    if(operandoDos!=0)
                    {
                        printf("El resultado de A/B es: %0.2f\n", division);
                    }else
                    {
                        printf("No es posible dividir por cero\n");
                    }

                    printf("El resultado de A*B es: %0.2f\n", multiplicacion);

                    if(operandoUno>=0)
                    {
                        printf("El factorial de A es: %d y ", factorialUno);
                    }else
                    {
                        printf("El factorial de A no es posible y ");
                    }
                    if(operandoDos>=0)
                    {
                        printf("el factorial de B es: %d\n", factorialDos);
                    }else
                    {
                        printf("el factorial de B no es posible\n");
                    }

                }else
                {
                    printf("\n//////Debes calcular todas las operaciones antes de mostrar//////\n");
                }

                break;

            case 5:
                break;

            default:
                printf("\nComando desconocido\n");
                break;
        }
        system("pause");
    }

    return 0;
}
