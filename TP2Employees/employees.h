#ifndef employees_H_INCLUDED
#define employees_H_INCLUDED
typedef struct
{
    char name[50];
    char lastName[50];
    int sector;
    float salary;

    int idEmployees;
    int isEmpty;
}eEmployees;
#endif // employees_H_INCLUDED


int employees_init(eEmployees* array,int limite);
int employees_mostrar(eEmployees* array,int limite);
int employees_alta(eEmployees* array,int limite);
int employees_baja(eEmployees* array,int limite, int id);
int employees_ordenar(eEmployees* array,int limite, int orden);
int employees_buscarPorId(eEmployees* array,int limite, int id);
int employees_mostrarGraficoEdades(eEmployees* array,int limite);
int employees_modificacion(eEmployees* array,int limite, int id);
int employees_totalSalario(eEmployees* array,int limite);
int employees_PromedioSalary(eEmployees* array,int limite);
int employees_SuperanPromedioDeSalario(eEmployees* array,int limite);



