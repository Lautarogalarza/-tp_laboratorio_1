#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

/** \brief
 *
 * \return Employee*
 *
 */
Employee* employee_new();
/** \brief
 *
 * \param idStr char*
 * \param nombreStr char*
 * \param horasTrabajadasStr char*
 * \param sueldoStr char*
 * \return Employee*
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);
//void employee_delete();

/** \brief
 *
 * \param this Employee*
 * \param id int
 * \return int
 *
 */
int employee_setId(Employee* this,int id);
/** \brief
 *
 * \param this Employee*
 * \param id int*
 * \return int
 *
 */
int employee_getId(Employee* this,int* id);

/** \brief
 *
 * \param this Employee*
 * \param nombre char*
 * \return int
 *
 */
int employee_setNombre(Employee* this,char* nombre);
/** \brief
 *
 * \param this Employee*
 * \param nombre char*
 * \return int
 *
 */
int employee_getNombre(Employee* this,char* nombre);

/** \brief
 *
 * \param this Employee*
 * \param horasTrabajadas int
 * \return int
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
/** \brief
 *
 * \param this Employee*
 * \param horasTrabajadas int*
 * \return int
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

/** \brief
 *
 * \param this Employee*
 * \param sueldo int
 * \return int
 *
 */
int employee_setSueldo(Employee* this,int sueldo);
/** \brief
 *
 * \param this Employee*
 * \param sueldo int*
 * \return int
 *
 */
int employee_getSueldo(Employee* this,int* sueldo);

/** \brief
 *
 * \param this Employee*
 * \return void
 *
 */
void employee_setEmployee(Employee* this);
/** \brief
 *
 * \param personaA void*
 * \param personaB void*
 * \return int
 *
 */
int employee_compararPorSueldo(void* personaA, void* personaB);
/** \brief
 *
 * \param personaA void*
 * \param personaB void*
 * \return int
 *
 */
int employee_compararPorHoras(void* personaA, void* personaB);
/** \brief
 *
 * \param personaA void*
 * \param personaB void*
 * \return int
 *
 */
int employee_compararPorNombre(void* personaA, void* personaB);


#endif // employee_H_INCLUDED
