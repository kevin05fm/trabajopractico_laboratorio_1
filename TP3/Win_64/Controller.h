int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
int controller_addEmployee(LinkedList* pArrayListEmployee,int* id);
int controller_editEmployee(LinkedList* pArrayListEmployee);
int controller_removeEmployee(LinkedList* pArrayListEmployee);
int controller_ListEmployee(LinkedList* pArrayListEmployee);
int controller_sortEmployee(LinkedList* pArrayListEmployee);
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);

int controller_UltimoID(LinkedList* pArrayListEmployee);
void controller_ordenPorId(LinkedList* pArrayListEmployee, int orden);
void controller_ordenPorNombre(LinkedList* pArrayListEmployee, int orden);
void controller_ordenPorHorasTrabajadas(LinkedList* pArrayListEmployee, int orden);
void controller_ordenPorSueldo(LinkedList* pArrayListEmployee, int orden);
