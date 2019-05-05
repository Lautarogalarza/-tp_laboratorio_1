#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED
#include "UTN_INPUT.h"
typedef struct
{
    int id;
    char name[51] ;
    char lastName[51] ;
    float salary;
    int sector;
    int isEmpty;

}Employee;

int initEmployees(Employee* lista, int len);

int findFreeSpace(Employee* lista, int len);

int generateLastId();

int addEmployee(Employee* lista,int len,int id ,char name[],char lastName[],float salary,int sector);

int findEmployeeById(Employee* lista, int len, int id);

int printOneEmployee(Employee* lista);

int printEmployees(Employee* lista, int len);

int removeEmployee(Employee* lista, int len);

int modifyEmployee(Employee* lista, int len);

void modfEmpleado(Employee* lista, int index);

void menu(Employee* lista,int len);

void findSalaryMax(Employee*lista,int len);

int sortEmployees(Employee* lista, int len, int order);

void initEmp(Employee lista[]);





#endif // ARRAYEMPLOYEES_H_INCLUDED
