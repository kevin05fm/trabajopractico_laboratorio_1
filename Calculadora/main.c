#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
#include "limits.h"




int main()
{
    float numeroUno;
    float numeroDos;
    float resultadoSuma;
    float resultadoResta;
    float resultadoMultiplicacion;
    float resultadoDivision;
    float resultadoFactorial;
    int opcion;
    char respuesta='s';


    while(respuesta!='n')
    {


        printf("\n 1 Ingrese numero X=%.2f \n 2 Ingrese numero Y=%.2f\n 3 Todas las operaciones\n 4 Resultados\n 5 Salir\n ",numeroUno,numeroDos);
        scanf(" %d",&opcion);



        switch(opcion)
        {
        case 1:
            printf(" Ingrese numero X\n");
            scanf(" %f",&numeroUno);
            break;
        case 2:
            printf(" Ingrese numero Y\n");
            scanf(" %f",&numeroDos);
            break;
        case 3:
            resultadoSuma=sumaEnteros(numeroUno,numeroDos,&resultadoSuma);
            resultadoResta=restaEnteros(numeroUno,numeroDos,&resultadoResta);
            resultadoMultiplicacion=multiplicacionEnteros(numeroUno,numeroDos,&resultadoMultiplicacion);
            resultadoDivision=divisionEnteros(numeroUno,numeroDos,&resultadoDivision);
            resultadoFactorial=factorial(numeroUno);

                printf("La suma de X=%.2f + Y=%.2f \n",numeroUno,numeroDos);
                printf("La resta de X=%.2f - Y=%.2f \n",numeroUno,numeroDos);
                printf("La multiplicacion de X=%.2f x Y=%.2f \n",numeroUno,numeroDos);
                printf("La division de X=%.2f / Y=%.2f \n",numeroUno,numeroDos);
                printf("El Factorial de %.2f \n",numeroUno);

            break;
        case 4:
            resultadoSuma=sumaEnteros(numeroUno,numeroDos,&resultadoSuma);
            resultadoResta=restaEnteros(numeroUno,numeroDos,&resultadoResta);
            resultadoMultiplicacion=multiplicacionEnteros(numeroUno,numeroDos,&resultadoMultiplicacion);
            resultadoDivision=divisionEnteros(numeroUno,numeroDos,&resultadoDivision);
            resultadoFactorial=factorial(numeroUno);

            if(sumaEnteros(numeroUno,numeroDos,&resultadoSuma)==0&&restaEnteros(numeroUno,numeroDos,&resultadoResta)==0&&multiplicacionEnteros(numeroUno,numeroDos,&resultadoMultiplicacion)==0)
            {


                printf("\nLa suma de X=%.2f + Y=%.2f es %.2f \n",numeroUno,numeroDos,resultadoSuma);
                printf("La resta de X=%.2f - Y=%.2f es %.2f \n",numeroUno,numeroDos,resultadoResta);
                printf("La multiplicacion de X=%.2f x Y=%.2f es %.2f \n",numeroUno,numeroDos,resultadoMultiplicacion);


                if(divisionEnteros(numeroUno,numeroDos,&resultadoDivision)==0)
                {
                    printf("La division de X=%.2f / Y=%.2f es %.2f \n",numeroUno,numeroDos,resultadoDivision);
                }
                else
                {
                    printf("Error ,no se puede dividir por cero\n");
                }


                if(numeroUno>=0&&numeroUno<14)
                {
                    printf("El Factorial de %.2f es %.2f \n",numeroUno,resultadoFactorial);

                }
                else
                {
                    printf("Error en el factorial,el numero elegido no corresponde entre [0-13] \n");
                }


            }
            else
            {
                printf("Error,no se pueden calcular todas las operaciones\n");
            }



            break;
        case 5:

            respuesta='n';

            break;
        default:
            printf("No es una opcion valida \n");
            break;



        }

    }


    return 0;

}
