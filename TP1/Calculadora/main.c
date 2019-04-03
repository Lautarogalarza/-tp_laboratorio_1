#include <stdio.h>
#include <stdlib.h>
#include "Function.h"

int main()
{
    int option;
    float numeroUno;
    float numeroDos;
    float resultadoSuma;
    float resultadoResta;
    float resultadoMultiplicacion;
    float resultadoDivision;
    int resultadoFactorialA;
    int resultadoFactorialB;
    int flag1=0;
    int flag2=0;
    int flag3=0;

    do
    {
        printf("==========================================\n");
        printf("POR FAVOR INGRESE 2 NUMEROS PARA COMENZAR\n");
        printf("==========================================\n");


        if(flag1==1)
        {
            printf("\n(1) Ingrese el 1er operando (A)= %.2f",numeroUno);
        }
        else
        {
            printf("\n(1) Ingrese el 1er operando (A)");
        }


        if(flag2==1)
        {
            printf("\n(2) Ingrese el 2do operando (B)= %.2f",numeroDos);
        }
        else
        {
            printf("\n(2) Ingrese el 2do operando (B)");
        }

        printf("\n(3) Calcular");
        printf("\n(4) Mostrar Resultados");
        printf("\n(5) Salir");

        printf("\n\nElija una opcion:");
        scanf("%d",&option);

        switch(option)
        {
        case 1:
            pedirNumero(&numeroUno);
            flag1=1;
            break;
        case 2:
            pedirNumero(&numeroDos);
            flag2=1;
            break;
        case 3:
            if(flag1==1 && flag2==1)
            {
                resultadoSuma=suma(numeroUno, numeroDos);
                resultadoResta=resta(numeroUno, numeroDos);
                resultadoMultiplicacion=multiplicacion(numeroUno, numeroDos);
                resultadoDivision=division(numeroUno, numeroDos);
                resultadoFactorialA=factorial(numeroUno);
                resultadoFactorialB=factorial(numeroDos);

                printf("\nSE REALIZARON TODAS LAS OPERACIONES POSIBLES\n\n");

                flag3=1;
            }
            else
            {
                printf("\nERROR...Ingrese dos operandos para calcular\n\n");
            }
            break;
        case 4:

            if(flag1==1 && flag2==1 && flag3==1)
            {
                printf("\nAl realizar el factorial solo se tomo en cuenta la parte entera del numero\n\n");

                printf("EL resultado de %.1f + %.1f es: %.1f\n", numeroUno, numeroDos, resultadoSuma);
                printf("EL resultado de %.1f - %.1f es: %.1f\n", numeroUno, numeroDos, resultadoResta);
                printf("EL resultado de %.1f * %.1f es: %.1f\n", numeroUno, numeroDos, resultadoMultiplicacion);

                if(numeroDos!=0)
                {

                    printf("EL resultado de %.1f / %.1f es: %.1f\n", numeroUno, numeroDos, resultadoDivision);

                }
                else
                {

                    printf("ERROR...No se puede dividir un numero por 0");
                }

                printf("EL factorial de %.1f es: %d\n", numeroUno, resultadoFactorialA);

                printf("EL factorial de %.1f es: %d\n", numeroDos, resultadoFactorialB);

            }
            else if(flag1==1 && flag2==1 && flag3==0)
            {

                printf("\nERROR...No se pueden ver los resultados si no fueron calculados\n\n");
            }
            else
            {

                printf("\nERROR...Ingrese dos operandos para calcular\n\n");
            }
            break;
        case 5:
            break;
        default:
            printf("ERROR...Por favor ingrese una opcion valida <1-5>\n");
            break;
        }

        fflush(stdin);
        system("pause");
        system("cls");

    }
    while(option!=5);

    printf("=================================\n");
    printf("Gracias por usar la calculadora!!\n");
    printf("=================================\n");

    return 0;
}
