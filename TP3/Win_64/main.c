#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    char seguir = 's';
    LinkedList* listaEmpleados = ll_newLinkedList();
    int ultimoID;
    int bajaEmpleado;

    do
    {
        switch(menu())
        {
        case 1:
            if(controller_loadFromText("data.csv",listaEmpleados) == -1)
            {
                printf("\nNo se cargaron datos\n");
            }
            else
            {
                printf("\nCarga exitosa\n");
            }
            system("pause");
            break;
        case 2:
            if(controller_loadFromBinary("data.csv",listaEmpleados)==-1)
            {
                printf("\nNo se cargaron datos\n");
            }
            else
            {
                printf("\nCarga exitosa\n");
            }
            system("pause");
            break;
        case 3:
            if(controller_UltimoID(listaEmpleados)!= -1)
            {
                ultimoID=controller_UltimoID(listaEmpleados);
                controller_addEmployee(listaEmpleados,&ultimoID);
            }
            else
            {
                printf("\nPrimero debe cargar la lista\n");
            }
            system("pause");
            break;
        case 4:
            if(!ll_isEmpty(listaEmpleados))
            {
                if(controller_editEmployee(listaEmpleados) != -1)
                {
                    printf("\n Se modifico correctamente");
                }
                else
                {
                    printf("\nNo existe ese empleado\n");
                }
            }
            else
            {
                printf("\nPrimero debe cargar la lista\n");
            }
            system("pause");
            break;
        case 5:
            if(!ll_isEmpty(listaEmpleados))
            {
                bajaEmpleado=controller_removeEmployee(listaEmpleados);
                if(bajaEmpleado==0)
                {
                    printf("\nEmpleado eliminado\n");

                }else if(bajaEmpleado == 1){

                    printf("\nBaja cancelada\n");
                }
                else
                {
                    printf("\nNo existe el empleado\n");
                }
            }else
            {
                printf("\nPrimero debe cargar la lista\n");
            }
            system("pause");
            break;
        case 6:
            if(!ll_isEmpty(listaEmpleados))
            {
                controller_ListEmployee(listaEmpleados);
            }else{
                printf("\nPrimero debe cargar la lista\n");
            }
            system("pause");
            break;
        case 7:
            if(!ll_isEmpty(listaEmpleados))
            {
                if(controller_sortEmployee(listaEmpleados)!= -1)
                {
                    printf("\nSe ordeno correctamente\n");
                }else
                {
                    printf("\nNo se ordeno correctamente\n");
                }
            }else
            {
                printf("\nPrimero debe cargar la lista\n");
            }
            system("pause");
            break;
        case 8:
            if(!ll_isEmpty(listaEmpleados))
            {
                if(controller_saveAsText("data.csv",listaEmpleados) == -1)
                {
                    printf("\nPrimero debe cargar la lista\n");
                }
                else
                {
                    printf("\nSe guardaron los datos exitosamente\n");
                }
            }else
            {
                printf("Primero debe cargar la lista");
            }
            system("pause");
            break;
        case 9:
            if(!ll_isEmpty(listaEmpleados))
            {
                if(controller_saveAsBinary("data.csv",listaEmpleados) == -1)
                {
                    printf("\nPrimero debe cargar la lista\n");
                }
                else
                {
                    printf("\nSe guardaron los datos exitosamente\n");
                }
            }else
            {
                printf("Primero debe cargar la lista");
            }
            system("pause");
            break;
        case 10:
            printf("\nSalir\n");
            system("pause");
            seguir = 'n';
            break;
        }
    }
    while(seguir == 's');

    ll_deleteLinkedList(listaEmpleados);

    return 0;
}
