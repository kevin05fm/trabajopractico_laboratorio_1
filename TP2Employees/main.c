#include <stdio.h>
#include <stdlib.h>
#include "FuncionesUtn.h"
#include "employees.h"
#define CANT 20


int main()
{
    char seguir='s';
    int opcion=0;
    eEmployees array[CANT];
    int auxId;
    int opciones;

    employees_init(array,CANT);


    while(seguir=='s')
    {
        printf("\n1- Agregar Empleado\n");
        printf("2- Modificar Empleado\n");
        printf("3- Borrar Empleado\n");
        printf("4- Informar\n\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:

                employees_alta(array,CANT);
                break;
            case 2:
                getValidInt("ingresar id\n","id no valido\n",&auxId,0,99999999,2);
                employees_modificacion(array,CANT,auxId);
                break;
            case 3:
                getValidInt("ingresar id\n","id no valido\n",&auxId,0,99999999,2);
                employees_baja(array,CANT,auxId);
                break;
            case 4:
                getValidInt("1- Ordenador por Apellido y Sector\n2- Suma y promedio de salarios\n","No es una opcion valida\n",&opciones,1,2,2);
                switch(opciones)
                {
                    case 1:

                    employees_ordenar(array,CANT,1);
                    employees_mostrar(array,CANT);
                        break;
                    case 2:

                        employees_totalSalario(array,CANT);
                        employees_PromedioSalary(array,CANT);
                        printf("Los cantidad de empleados que superan el promedio de salario son: ");
                        employees_SuperanPromedioDeSalario(array,CANT);
                        break;
                }

                break;
            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
