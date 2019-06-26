#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Controller.h"
#include "parser.h"

int menu()
{
    int opcion;
    system("cls");
    printf("\n*** Menu de Opciones ***\n\n");
    printf(" 1- Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    printf(" 2- Cargar los datos de los empleados desde el archivo data.csv (modo binario)\n");
    printf(" 3- Alta de empleado\n");
    printf(" 4- Modificar datos de empleado\n");
    printf(" 5- Baja de empleado\n");
    printf(" 6- Listar empleados\n");
    printf(" 7- Ordenar empleados\n");
    printf(" 8- Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    printf(" 9- Guardar los datos de los empleados en el archivo data.csv (modo binario)\n");
    printf(" 10- Salir\n");
    printf(" Ingrese opcion: ");
    scanf("%d",&opcion);

    return opcion;
}

void initialize(Employee* this,char* idAux, char *nombreAux,char* horasTrabajadasAux,char* sueldoAux)
{

    employee_setId(this,atoi(idAux));
    employee_getNombre(this,nombreAux);
    employee_setHorasTrabajadas(this,atoi(horasTrabajadasAux));
    employee_setSueldo(this,atoi(sueldoAux));

}

Employee* employee_new()
{
    Employee* Emp;

    Emp=(Employee*)malloc(sizeof(Employee));

    if(Emp == NULL)
    {
        printf("No hay lugar en Memoria");
        exit(0);
    }

    return Emp;
}

Employee* employee_newParametros(int idStr,char* nombreStr,int horasTrabajadasStr,int sueldo)
{
    Employee* this=employee_new();
    if(this != NULL)
    {
        employee_setId(this,idStr);
        employee_setNombre(this,nombreStr);
        employee_setHorasTrabajadas(this,horasTrabajadasStr);
        employee_setSueldo(this,sueldo);
    }

    return this;
}
//Carga el dato
int employee_setId(Employee* this,int idAux)
{
    if(idAux > 0)
        this->id=idAux;

    return 0;
}
//Busca el dato
int employee_getId(Employee* this,int* id)
{
    int retorno= -1;
    if(this != NULL){
        *id= this->id;
        retorno= 0;
    }
    return retorno;
}

int employee_setNombre(Employee* this,char* nombreAux)
{

    int retorno = -1;
    if(this != NULL && nombreAux != NULL)
    {
        strcpy(this->nombre,nombreAux);
        retorno=0;
    }

    return retorno;
}

int employee_getNombre(Employee* this,char* nombre)
{

    int retorno = -1;
    if(this != NULL && nombre != NULL)
    {
        strcpy(nombre,this->nombre);
        retorno=0;
    }

    return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadasAux)
{

    int retorno = -1;
    if(this != NULL )
    {
        this->horasTrabajadas=horasTrabajadasAux;
        retorno=0;
    }

    return retorno;

}

/// if(!Employee_getHorasTrabajadas(Employee, &horas))
///     printf(Horas);
/// else
///     printf(Error al intentar obtener el dato);

//get le paso una variable vacioa que cargo con el dato que tiene en Employee

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int retorno = -1;
    if(this != NULL && horasTrabajadas != NULL)
    {
        (*horasTrabajadas)=this->horasTrabajadas;
        retorno = 0;
    }

    return retorno;
}

int employee_setSueldo(Employee* this,int sueldoAux)
{
    int retorno = -1;
    if(this != NULL )
    {
        this->sueldo=sueldoAux;
        retorno = 0;
    }

    return retorno;

}

int employee_getSueldo(Employee* this,int* sueldo)
{
    int retorno = -1;
    if(this != NULL && sueldo != NULL)
    {
        (*sueldo)=this->sueldo;
        retorno = 0;
    }

    return retorno;
}

void employee_mostrarUnEmpleado(Employee* this)
{
    if(this != NULL)
    {
        printf("\t%2d \t%22s \t\t%d \t\t\t%d\n",this->id, this->nombre,this->horasTrabajadas,this->sueldo);
    }
}


