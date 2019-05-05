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

int initEmployees(Employee* list, int len);

int findFreeSpace(Employee* list, int len);

int generateLastId();

int addEmployee(Employee* list,int len,int id ,char name[],char lastName[],float salary,int sector);

int findEmployeeById(Employee* list, int len, int id);

int printOneEmployee(Employee* list);

int printEmployees(Employee* list, int len);

int removeEmployee(Employee* list, int len);

int modifyEmployee(Employee* list, int len);

void modfEmpleado(Employee* list, int index);

void menu(Employee* list,int len);

void findSalaryMax(Employee*list,int len);

int sortEmployees(Employee* list, int len, int order);

void initEmp(Employee lista[]);





#endif // ARRAYEMPLOYEES_H_INCLUDED
