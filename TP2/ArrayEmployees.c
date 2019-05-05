#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "ArrayEmployees.h"

int initEmployees(Employee* list, int len)
{

    int myReturn=-1;
    for(int i=0; i < len; i++)
    {
        list[i].isEmpty = 0;

        myReturn=0;
    }

    return myReturn;
}


int findFreeSpace(Employee* list, int len)
{
    int index = -1;

    for(int i=0; i < len; i++)
    {
        if(list[i].isEmpty == 0)
        {
            index = i;
            break;
        }
    }

    return index;
}

int generateLastId()

{

    static int id=0;

    id ++;

    return id;
}



int addEmployee(Employee* list, int len,int id,char name[],char lastName[],float salary,int sector)
{
    int index;
    int myReturn=-1;


    index = findFreeSpace(list, len);

    if( index == -1)
    {

        printf("\nNo hay lugar en el sistema\n");
    }
    else
    {

        list[index].id=id;

        strcpy(list[index].name,name);

        strcpy(list[index].lastName,lastName);

        list[index].salary=salary;

        list[index].sector=sector;

        list[index].isEmpty = 1; //isEmpty en 1 esta  vacio y en 0 esta cargado



    }

    return myReturn;
}



void  printEmployee(Employee list)
{
    printf("%3d %10s %10s %10.3f %9d\n",list.id,list.name,list.lastName,list.salary,list.sector);
}




int printEmployees(Employee* list, int len)
{
    int myReturn = -1;

    printf(" ID      Nombre    Apellido   Salario   Sector  \n\n");
    for(int i=0; i < len; i++)
    {
        if(list[i].isEmpty == 1)
        {
            printEmployee(list[i]);

            myReturn=0;
        }
    }

    if( myReturn == -1)
    {
        printf("\nNo hay empleados que mostrar\n");
    }

    return myReturn;
}



int findEmployeeById(Employee* list, int len, int id)

{
    int index = -1;

    for(int i=0; i < len; i++)
    {
        if(list[i].isEmpty == 1 && list[i].id == id)
        {
            index = i;
            break;
        }
    }

    return index;
}




int removeEmployee(Employee* list, int len)
{
    int auxId;
    int answer;
    int i;
    int myReturn=-1;

    for(i=0; i<len; i++)
    {
        if(list[i].isEmpty==1)
        {
            printf("\nID empleado %d",list[i].id);
        }
    }

    printf("\nQue empleado queres dar de baja? (Ingresar ID empleado) ");

    scanf("%d",&auxId);



    for(i=0; i<len; i++)
    {
        if(auxId==list[i].id)
        {
            getValidInt("Esta seguro que quiere darle de baja a este empleado? <1.Si-2.No>","ERROR, ingrese una opcion valida <1-2>",1,2,&answer);



            switch(answer)
            {
            case 1:

                if(auxId==list[i].id && list[i].isEmpty==1)
                {
                    list[i].isEmpty=0;
                    myReturn=0;
                    break;
                }

                break;
            case 2:
                printf("Baja Cancelada");
                break;
            default:
                printf("Ingrese una opcion valida");
                break;

            }

            break;
        }
        else
        {
            printf("Error ingrese un ID que exista en el sistema\n");
            break;

        }

    }

    return myReturn;

}

int modifyEmployee(Employee* list, int len)
{
    int answer;
    int auxId;
    int i;
    int index;
    int myReturn=-1;


    for(i=0; i<len; i++)
    {
        if(list[i].isEmpty==1)
        {
            printf("\nID empleado %d",list[i].id);
        }
    }

    printf("\nQue empleado quiere modificar? (Ingresar ID empleado) ");
    scanf("%d",&auxId);


    index=findEmployeeById(list,len,auxId);

    if(auxId==list[index].id )
    {

        getValidInt("Esta seguro que quiere modificar a este empleado? <1.Si-2.No>","ERROR, ingrese una opcion valida <1-2>",1,2,&answer);

        switch(answer)
        {
        case 1:

            for (i=0; i<len; i++)
            {
                if(list[i].id==auxId && list[i].isEmpty==1)
                {
                    modfEmpleado(list,i);
                    myReturn=0;

                    break;
                }
            }
            break;
        case 2:
            printf("Modificacion cancelada");
            break;
        default:
            break;


        }
    }

    else
    {
        printf("Error ingrese un ID que exista en el sistema\n");
    }


    return myReturn;
}



void modfEmpleado(Employee* list, int index)
{
    int option;
    char auxNewName[51];
    char auxNewLastName[51];
    float auxNewSalary;
    int auxNewSector;


    do
    {
        system("cls");
        printf("\n1.Modificar Nombre\n");
        printf("2.Modificar Apellido\n");
        printf("3.Modificar Salario\n");
        printf("4.Modificar Sector\n");
        printf("5.Salir\n");
        scanf("%d",&option);


        switch(option)
        {
        case 1:

            getValidString("Ingrese nuevo nombre :","ERROR,ingrese el nombre nuevamente (solo letras)","ERROR, se exedio del limite de la cadena",auxNewName,1,51);
            fflush(stdin);
            stringToUpper(auxNewName);

            strcpy(list[index].name,auxNewName);
            break;

        case 2:

            getValidString("Ingrese nuevo apellid :","ERROR,ingrese el apellido nuevamente (solo letras)","ERROR, se exedio del limite de la cadena",auxNewName,1,51);
            fflush(stdin);
            stringToUpper(auxNewLastName);

            strcpy(list[index].lastName, auxNewLastName);
            break;

        case 3:

            getValidFloat("Ingrese nuevo salario :","ERROR ingrese el salario nuevamente (solo numeros)",0,1000000,&auxNewSalary);

            list[index].salary=auxNewSalary;
            break;
        case 4:
            getValidInt("Ingrese nuevo sector :","ERROR ingrese el sector nuevamente <1-10>",1,10,&auxNewSector);
            list[index].sector=auxNewSector;
            break;
        case 5:

            break;
        default:
            printf("ERROR!! por favor ingrese una de las opciones validaas <1-5>\n");
            break;


        }


    }
    while(option!=5);

}


void menu(Employee* list,int len)
{



    int option;
    int order;


    do
    {



        system("cls");
        printf("  *** INFORMES ***\n\n");
        printf("1- Ordenar por apellido y sector\n");
        printf("2- Total y promedio de los salarios\n");
        printf("3- Salir\n\n");
        printf("Ingrese opcion: ");
        scanf("%d", &option);

        switch(option)

        {
        case 1:

            findSalaryMax(list,len);
            break;
        case 2:

            printf("\ningrese orden <1-2>\n");
            scanf("%d",&order);

            sortEmployees(list,len,order);

            break;
        case 3:
            printf("\nADIOS\n");
            break;
        default:
            printf("\nERROR! Por favor ingrese una opcion valida <1-7>\n");
            break;

        }

        fflush(stdin);
        system("pause");
        system("cls");

    }
    while(option!=3);




}


void findSalaryMax(Employee*list,int len)
{
    float averageSalary=0;//promedio
    int counter=0;//contador
    float totalSalary=0;
    int employeeQuantity=0;//cantidad
    int i;
    int flag=0;

    for(i=0; i<len; i++)
    {
        if(list[i].isEmpty==1)
        {

            totalSalary = list[i].salary + totalSalary;

            employeeQuantity++;

            flag=1;
        }
    }

    if(flag==1)
    {
        averageSalary=totalSalary/employeeQuantity;

        for(i=0; i<len; i++)
        {
            if(list[i].salary>averageSalary&&list[i].isEmpty==1)
            {
                counter++;
            }
        }
    }


    printf("El promedio de los salarios es: %.3f\n",averageSalary);


    printf("La cantidad de empleados que superan el promedio es: %d\n", counter);

}




int sortEmployees(Employee* list, int len, int order)
{


    Employee auxEmp;
    int myReturn=-1;


    switch(order)

    {

    case 1://ascendente

        for(int i =0 ; i<len-1 ; i ++)
        {
            for(int j= i+1 ; j<len; j++)
            {
                if(strcmp(list[j].lastName,list[i].lastName)<0)
                {
                    auxEmp = list[i];
                    list[i] = list[j];
                    list[j] = auxEmp;
                }
                else if(strcmp(list[j].lastName,list[i].lastName) ==0 && list[i].sector>list[j].sector)
                {
                    auxEmp = list[i];
                    list[i] = list[j];
                    list[j] = auxEmp;
                }

            }
        }

        break;
    case 2://descendente

        for(int i =0 ; i<len-1 ; i ++)
        {
            for(int j= i+1 ; j<len; j++)
            {
                if(strcmp(list[j].lastName,list[i].lastName)>0)
                {
                    auxEmp = list[i];
                    list[i] = list[j];
                    list[j] = auxEmp;
                }
                else if(strcmp(list[j].lastName,list[i].lastName) ==0 && list[i].sector<list[j].sector)
                {
                    auxEmp = list[i];
                    list[i] = list[j];
                    list[j] = auxEmp;
                }

            }
        }



        break;
    }

    return myReturn;
}




void initEmp(Employee lista[])
{
    int auxLegajo[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    char auxNombre[10][51]= {"Lautaro","Jose","Martin","Pepe","Claudia","Florencia","Miguel","Yanina","Mateo","Miriam"};
    char auxApellido[10][51]= {"Galarza","Perez","Caridades","Ruiz","Silva","Sanchez","Garcia","Diaz","Liso","Pinno"};
    float auxSalario[10] = { 234.500, 341.000, 456.000, 242.000, 162.000, 218.000, 326.000, 166.000, 218.500, 548.000};
    int auxSector[10] = {1, 2, 9, 4, 5, 3, 4, 8, 5, 10};


    for(int i=0; i<10; i++)
    {
        lista[i].id=auxLegajo[i];

        strcpy(lista[i].name, auxNombre[i]);
        strcpy(lista[i].lastName, auxApellido[i]);


        lista[i].salary=auxSalario[i];
        lista[i].sector=auxSector[i];


        generateLastId();

        lista[i].isEmpty=1;



    }
}












