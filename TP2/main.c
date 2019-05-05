#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#define ELEMENTS 13

int main()
{

    Employee arrayEmployees[ELEMENTS];

    int option;
    char auxName[51] ;
    char auxLastName[51] ;
    int auxSector;
    float auxSalary;
    int auxId;
    int flag=0;



    initEmployees(arrayEmployees,ELEMENTS);
    initEmp(arrayEmployees);

    do
    {
        printf("INGRESE UNA OPCION PARA COMENZAR\n");
        printf("\n1.Alta\n");
        printf("2.Modificar\n");
        printf("3.Baja\n");
        printf("4.Informes\n");
        printf("5.Mostrar\n");
        printf("6.Ordenar\n");
        printf("7.Salir\n");
        printf("\nElija una opcion:" );
        scanf("%d", &option);
        //fflush(stdin);

        switch(option)
        {


        case 1:

           getValidString("Ingrese nombre :","ERROR,ingrese el nombre nuevamente (solo letras)","ERROR, se exedio del limite de la cadena",auxName,1,51);
           fflush(stdin);
           stringToUpper(auxName);

           getValidString("Ingrese apellido :","ERROR, ingrese apellido nuevamente (solo letras)","ERROR, se exedio del limite de la cadena",auxLastName,1,51);
           fflush(stdin);
           stringToUpper(auxLastName);

           getValidFloat("Ingrese salario :","ERROR ingrese salario nuevamente (solo numeros)",0,1000000,&auxSalary);

           getValidInt("Ingrese sector :","ERROR ingrese sector nuevamente <1-10>",1,10,&auxSector);

           auxId=generateLastId();

           addEmployee(arrayEmployees,ELEMENTS,auxId,auxName,auxLastName,auxSalary,auxSector);

           flag=1;



            break;
        case 2:

            modifyEmployee(arrayEmployees,ELEMENTS);

            break;
        case 3:

            removeEmployee(arrayEmployees,ELEMENTS);

            break;
        case 4:

            menu(arrayEmployees,ELEMENTS);

            break;
        case 5:

            printEmployees(arrayEmployees,ELEMENTS);
            printf("\nBIEN\n");

            break;
        case 6:

            printf("\nAMIGO\n");

            break;
        case 7:

            printf("\nADIOS\n");

            break;
        default:
            printf("\nERROR! Por favor ingrese una opcion valida <1-7>\n");
            break;

            }





        fflush(stdin);
        system("pause");
        system("cls");


    }while(option!=7);


    return 0;
}
