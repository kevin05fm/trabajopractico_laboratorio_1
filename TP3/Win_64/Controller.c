#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "validaciones.h"
#include "string.h"
#include "Controller.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* archivo;
    int retorno=-1;

    archivo=fopen(path,"r");

    if(archivo!=NULL && pArrayListEmployee != NULL)
    {
        ll_clear(pArrayListEmployee);
        parser_EmployeeFromText(archivo,pArrayListEmployee);
        retorno=0 ;
        //fclose(archivo);
    }
    fclose(archivo);

    return retorno;

}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    FILE* archivo;
    archivo=fopen(path, "rb");

    if(archivo != NULL && pArrayListEmployee != NULL)
    {

        ll_clear(pArrayListEmployee);
        parser_EmployeeFromBinary(archivo,pArrayListEmployee);
        retorno=0;
    }

    fclose(archivo);

    return retorno;

}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee,int* id)
{
    Employee* empleado;
    int idAux=*id;
    char nombreAux[50];
    int horasTrabajadasAux;
    int sueldoAux;
    int retorno=-1;
    if(pArrayListEmployee != NULL)
    {
        if(!getValidString("\nIngrese Nombre:\n","\nNombre Incorrecto\n","\nExede Caracteres\n",nombreAux,50,3))
        {
            if(!getValidInt("\nIngrese Horas Trabajadas:\n","\nHoras Incorrectas\n",&horasTrabajadasAux,1,100,3))
            {
                if(!getValidInt("\nIngrese Sueldo:\n","\nSueldo Incorrecto\n",&sueldoAux,1,99999999,3))
                {
                    idAux++;
                    empleado=employee_newParametros(idAux,nombreAux,horasTrabajadasAux,sueldoAux);
                    ll_add(pArrayListEmployee,empleado);
                    id=&idAux;
                    retorno=0;
                }
            }
        }

    }

    return retorno;


}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    int idAux;
    int i;
    int indice=-1;
    int opcion;
    char nombreAux[50];
    int sueldoAux;
    int horasTrabajadasAux;
    Employee* empleado;

    if(pArrayListEmployee != NULL)
    {

        if(!getValidInt("\nIngrese Id de empleado a modificar:\n","\nEso no es un empleado\n",&idAux,0,99999999,3))
        {
            for(i=0; i<ll_len(pArrayListEmployee); i++)
            {
                empleado=(Employee*)ll_get(pArrayListEmployee,i);
                if( empleado->id == idAux )
                {
                    indice=i;
                    break;
                }
            }
            if(indice != -1)
            {
                do
                {
                    printf("\n\tID\t\t\tNombre \t\tHoras Trabajadas \tSueldo \n\n");
                    employee_mostrarUnEmpleado(empleado);
                    printf("\n1. Modificar nombre\n2. Modificar horas trabajadas\n3. Modificar sueldo\n4.Salir");
                    scanf("%d",&opcion);
                    retorno=0;
                    switch(opcion)
                    {
                    case 1:
                        if(!getValidString("\nIngrese Nuevo Nombre:\n","\nNombre no valido\n","\nExede caracteres\n",nombreAux,50,3))
                        {
                            employee_setNombre(empleado,nombreAux);
                            printf("\nNombre modificado!\n");
                            break;
                        }
                    case 2:
                        if(!getValidInt("\nIngrese Nuevas Horas Trabajadas:\n","\nHoras Incorrectas\n",&horasTrabajadasAux,1,100,3))
                        {
                            employee_setHorasTrabajadas(empleado, horasTrabajadasAux);
                            printf("\nNuevasHoras modificas!\n");
                            break;
                        }
                    case 3:
                        if(!getValidInt("\nIngrese Nuevo Sueldo:\n","\nSueldo Incorrecto\n",&sueldoAux,1,99999999,3))
                        {
                            employee_setSueldo(empleado, sueldoAux);
                            printf("\nNuevo Sueldo modificado!\n");
                            break;
                        }

                    }
                }
                while(opcion != 4);
            }
        }

    }

    return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    int idAux;
    int i;
    int indice=-1;
    int opcion;
    Employee* empleado;
    if (pArrayListEmployee != NULL)
    {

        if(!getValidInt("\nIngrese Id de empleado a Eliminar:\n","\nEso no es un empleado\n",&idAux,0,99999999,3))
        {
            for(i=0; i<ll_len(pArrayListEmployee); i++)
            {
                empleado=(Employee*)ll_get(pArrayListEmployee,i);
                if( empleado->id == idAux )
                {
                    indice=i;
                    break;
                }
            }
            if(indice != -1)
            {
                printf("\n\tID\t\t\tNombre \t\tHoras Trabajadas \tSueldo \n\n");
                employee_mostrarUnEmpleado(empleado);
                printf("\n1.Desea dar de baja al empleado\n2.Salir");
                scanf("%d",&opcion);
                if(opcion==1)
                {
                    ll_remove(pArrayListEmployee,indice);
                    retorno=0;
                }
                else
                {
                    retorno=1;
                }
            }
        }
    }
    return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    Employee* empleado;
    int i;
    if(pArrayListEmployee != NULL)
    {
        printf("\n\tID\t\t\tNombre \t\tHoras Trabajadas \tSueldo \n\n");
        for(i=0; i<ll_len(pArrayListEmployee); i++)
        {
            empleado=(Employee*)ll_get(pArrayListEmployee,i);
            employee_mostrarUnEmpleado(empleado);
        }
        retorno=0;
    }

    return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno= -1;
    int opcion;
    int orden;
    if(pArrayListEmployee != NULL)
    {
        printf("\n1.Ordenar empleado por id\n2.Ordenar empleado por nombre\n3.Ordenar empleado por horas trabajadas\n4.Ordenar empleado por sueldo\n5.Cancelar\n");
        scanf("%d",&opcion);
        if(opcion>0 && opcion<5)
        {
            printf("\n1.Ascendente\n2.Descendente\n");
            scanf("%d",&orden);
            switch(opcion)
            {
            case 1:
                controller_ordenPorId(pArrayListEmployee,orden);
                break;
            case 2:
                controller_ordenPorNombre(pArrayListEmployee,orden);
                break;
            case 3:
                controller_ordenPorHorasTrabajadas(pArrayListEmployee,orden);
                break;
            case 4:
                controller_ordenPorSueldo(pArrayListEmployee,orden);
                break;
            }
            retorno= 0;
        }
        else
        {
            printf("\nOpcion incorrecta\n");
        }


    }

    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int retorno= -1;
    int i;
    FILE* archivo= fopen(path,"w");
    if(archivo!= NULL && pArrayListEmployee != NULL)
    {
        Employee* empleado;
        fprintf(archivo,"id,nombre,horasTrabajadas,sueldo\n");
        for(i=0; i<ll_len(pArrayListEmployee); i++)
        {
            empleado=ll_get(pArrayListEmployee,i);
            fprintf(archivo,"%d,%s,%d,%d\n",empleado->id,empleado->nombre,empleado->horasTrabajadas,empleado->sueldo);
        }
        fclose(archivo);
        retorno=0;
    }

    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    int retorno= -1;
    int i;
    FILE* archivo=fopen(path,"wb");
    if(archivo!= NULL && pArrayListEmployee!= NULL)
    {
        Employee* empleado;
        for(i=0; i<ll_len(pArrayListEmployee); i++)
        {
            empleado=ll_get(pArrayListEmployee,i);
            fwrite(empleado, sizeof(Employee),1,archivo);
        }
        fclose(archivo);
        retorno=0;
    }

    return retorno;
}
int controller_UltimoID(LinkedList* pArrayListEmployee)
{
    int i;
    int mayor;
    int flag=0;;
    Employee* empleado;

    if(!ll_isEmpty(pArrayListEmployee))
    {

        for( i=0; i<ll_len(pArrayListEmployee); i++)
        {
            empleado=ll_get(pArrayListEmployee, i);
            if(empleado->id > mayor || flag == 0  )
            {
                mayor = empleado->id;
                flag=1;
            }
        }
    }
    else
    {
        mayor = -1;
    }

    return mayor;
}

void controller_ordenPorId(LinkedList* pArrayListEmployee, int orden)
{
    int i;
    int j;

    Employee* empleado = employee_new();
    Employee* empleado2 = employee_new();
    Employee* empleadoAux = employee_new();

    switch(orden)
    {
    case 1:
        for(i=0; i<ll_len(pArrayListEmployee); i++)
        {
            empleado = ll_get(pArrayListEmployee, i);

            for(j=0; j<ll_len(pArrayListEmployee); j++)
            {
                empleado2 = ll_get(pArrayListEmployee, j);

                if(empleado->id > empleado2->id)
                {
                    *empleadoAux = *empleado2;
                    *empleado2 = *empleado;
                    *empleado = *empleadoAux;
                }
            }
        }
        break;
    case 2:
        for(i=0; i<ll_len(pArrayListEmployee); i++)
        {
            empleado = ll_get(pArrayListEmployee, i);

            for(j=0; j<ll_len(pArrayListEmployee); j++)
            {
                empleado2 = ll_get(pArrayListEmployee, j);

                if(empleado->id < empleado2->id)
                {
                    *empleadoAux = *empleado2;
                    *empleado2 = *empleado;
                    *empleado = *empleadoAux;
                }
            }
        }
    }
}

void controller_ordenPorNombre(LinkedList* pArrayListEmployee, int orden)
{
    int i;
    int j;

    Employee* empleado = employee_new();
    Employee* empleado2 = employee_new();
    Employee* empleadoAux = employee_new();

    switch(orden)
    {
    case 1:
        for(i=0; i<ll_len(pArrayListEmployee); i++)
        {
            empleado = ll_get(pArrayListEmployee, i);

            for(j=0; j<ll_len(pArrayListEmployee); j++)
            {
                empleado2 = ll_get(pArrayListEmployee, j);

                if(strcmp(empleado->nombre, empleado2->nombre)>0)
                {
                    *empleadoAux = *empleado2;
                    *empleado2 = *empleado;
                    *empleado = *empleadoAux;
                }
            }
        }
        break;
    case 2:
        for(i=0; i<ll_len(pArrayListEmployee); i++)
        {
            empleado = ll_get(pArrayListEmployee, i);

            for(j=0; j<ll_len(pArrayListEmployee); j++)
            {
                empleado2 = ll_get(pArrayListEmployee, j);

                if(strcmp(empleado->nombre, empleado2->nombre)<0)
                {
                    *empleadoAux = *empleado2;
                    *empleado2 = *empleado;
                    *empleado = *empleadoAux;
                }
            }
        }
    }
}

void controller_ordenPorHorasTrabajadas(LinkedList* pArrayListEmployee, int orden)
{
    int i;
    int j;

    Employee* empleado = employee_new();
    Employee* empleado2 = employee_new();
    Employee* empleadoAux = employee_new();

    switch(orden)
    {
    case 1:
        for(i=0; i<ll_len(pArrayListEmployee); i++)
        {
            empleado = ll_get(pArrayListEmployee, i);

            for(j=0; j<ll_len(pArrayListEmployee); j++)
            {
                empleado2 = ll_get(pArrayListEmployee, j);

                if(empleado->horasTrabajadas > empleado2->horasTrabajadas)
                {
                    *empleadoAux = *empleado2;
                    *empleado2 = *empleado;
                    *empleado = *empleadoAux;
                }
            }
        }
        break;
    case 2:
        for(i=0; i<ll_len(pArrayListEmployee); i++)
        {
            empleado = ll_get(pArrayListEmployee, i);

            for(j=0; j<ll_len(pArrayListEmployee); j++)
            {
                empleado2 = ll_get(pArrayListEmployee, j);

                if(empleado->horasTrabajadas < empleado2->horasTrabajadas)
                {
                    *empleadoAux = *empleado2;
                    *empleado2 = *empleado;
                    *empleado = *empleadoAux;
                }
            }
        }
    }
}

void controller_ordenPorSueldo(LinkedList* pArrayListEmployee, int orden)
{
    int i;
    int j;

    Employee* empleado = employee_new();
    Employee* empleado2 = employee_new();
    Employee* empleadoAux = employee_new();

    switch(orden)
    {
    case 1:
        for(i=0; i<ll_len(pArrayListEmployee); i++)
        {
            empleado = ll_get(pArrayListEmployee, i);

            for(j=0; j<ll_len(pArrayListEmployee); j++)
            {
                empleado2 = ll_get(pArrayListEmployee, j);

                if(empleado->sueldo > empleado2->sueldo)
                {
                    *empleadoAux = *empleado2;
                    *empleado2 = *empleado;
                    *empleado = *empleadoAux;
                }
            }
        }
        break;
    case 2:
        for(i=0; i<ll_len(pArrayListEmployee); i++)
        {
            empleado = ll_get(pArrayListEmployee, i);

            for(j=0; j<ll_len(pArrayListEmployee); j++)
            {
                empleado2 = ll_get(pArrayListEmployee, j);

                if(empleado->sueldo < empleado2->sueldo)
                {
                    *empleadoAux = *empleado2;
                    *empleado2 = *empleado;
                    *empleado = *empleadoAux;
                }
            }
        }
    }
}
