#include <stdio.h>

float sumar(float x, float y)
{
    float suma;
    suma= x+y;
    return suma;
}

float restar(float x, float y)
{
    float resta;
    resta= x-y;
    return resta;
}

float dividir(float x, float y)
{
    float division;
    division= x/y;
    return division;
}

float multiplicar(float x, float y)
{
    float multiplicacion;
    multiplicacion= x*y;
    return multiplicacion;
}

int factoriar(int x)
{
    int contador;
    int factorial;
    factorial=1;

    for(contador=1; contador<=x; contador++)
    {
        factorial= factorial*contador;
    }

    return factorial;
}
