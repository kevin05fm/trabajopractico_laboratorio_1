#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "string.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{

    char idAux[50],horasAux[50],sueldoAux[50],nombreAux[50];
    int r;
    int i;
    int retorno=-1;

    if(pFile != NULL)
    {
        r=fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",idAux,nombreAux,horasAux,sueldoAux);
        do
        {
            r=fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",idAux,nombreAux,horasAux,sueldoAux);
            if(r==4)
            {
                Employee* empleado =(Employee*)malloc(sizeof(Employee));
                empleado->id=atoi(idAux);
                strcpy(empleado->nombre,nombreAux);
                empleado->horasTrabajadas=atoi(horasAux);
                empleado->sueldo=atoi(sueldoAux);
                i++;
                ll_add(pArrayListEmployee,empleado);
                retorno=0;

            }
            else
            {
                break;
            }
        }
        while(!feof(pFile));
    }
    else
    {
        printf("el archivo no existe");
    }

    fclose(pFile);

    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int retorno= -1;
    Employee* empleado;

    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        while(!feof(pFile))
        {

            empleado = (Employee*)malloc(sizeof(Employee));
            if ( fread(empleado, sizeof(Employee),1,pFile) == 1 )
            {
                ll_add(pArrayListEmployee, empleado);

            }
            else
            {
                break;
            }
        }
        retorno= 0;
    }
    return retorno;

}
