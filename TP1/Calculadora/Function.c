#include <stdio.h>
#include <stdlib.h>
#include "Function.h"
#include <ctype.h>

void pedirNumero( float* Pnum )
{
    printf("\nIngrese un numero: ");
    fflush(stdin);
    scanf("%f",Pnum);
}


float suma( float numA, float numB )
{
    float resultadoSuma;

    resultadoSuma= numA + numB;

    return resultadoSuma;
}

float resta( float numA, float numB)
{
    float resultadoResta;

    resultadoResta= numA - numB;

    return resultadoResta;
}

float multiplicacion( float numA, float numB)
{
    float resultadoMultiplicacion;

    resultadoMultiplicacion= numA * numB;

    return resultadoMultiplicacion;
}

float division( float numA, float numB)
{
    float resultadoDivision;

    resultadoDivision= numA / numB;

    return resultadoDivision;
}
int factorial(float num)
{
    int resultadoFactorial=1;
    int i;

    for (i=(int)num;i>=1;i--)
    {
        resultadoFactorial = resultadoFactorial * i;
    }

    return resultadoFactorial;
}
