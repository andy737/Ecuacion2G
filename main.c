/*Programa que resuelve ecuaciones de 2do grado, mediante el uso de la f�rmula general.
*Creado por: Andr�s de Jes�s Hern�ndez Mart�nez
*Grupo: 7ITI1
*Fecha de creaci�n: 20 mayo de 2012
*Fecha de la �ltima modificaci�n: 20 mayo de 2012
*/

//Declaracion de librerias
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

//Declaraci�n de funciones
void solucionE(float a, float b, float c);

//Funci�n encargada de  mostrar en consola, la petici�n
//de variables para resolver la ecuaci�n de 2do grado
void ingresaV(void)
{
    //Declaraci�n de variables locales
    float a,b,c;

    do
    {
        system("cls");
        printf("\nIngresa el valor de la variable a:\n");
        fflush (stdin);
    }
    while(scanf("%f",  &a)!=1);


    //Verifica que la variable "a" sea diferente de 0
    while(a==0)
    {
        system("cls");
        printf("\nEl valor de la variable \"a\" debe ser distinto de 0.\n\n(Presiona cualquier tecla para continuar)");
        getch();
        system("cls");
        printf("\nIngresa el valor de la variable a:\n");

        //Valida que solo se ingresen numeros
        do
        {
            system("cls");
            printf("\nIngresa el valor de la variable a:\n");
            fflush (stdin);
        }
        while(scanf("%f",  &a)!=1);
    }

    do
    {
        system("cls");
        printf("\nIngresa el valor de la variable b:\n");
        fflush (stdin);
    }
    while(scanf("%f",  &b)!=1);

    do
    {
        system("cls");
        printf("\nIngresa el valor de la variable c:\n");
        fflush (stdin);
    }
    while(scanf("%f",  &c)!=1);

    //Llamada a la funci�n solucionE()
    solucionE(a,b,c);

}

//Funci�n encargada de resolver la ecuaci�n de 2do grado
void solucionE(float a, float b, float c)
{
    //Declaraci�n de variables locales
    float x1, x2, f;

    //Calculo del discriminate
    f=b*b-4*a*c;

    //Verifica que el discrimiante sea mayor o igual que 0 (raices reales)
    if(f>=0)
    {
        //Calculo de las soluciones para x1 y x2
        x1=(-b+sqrt(f))/(2*a);
        x2=(-b-sqrt(f))/(2*a);

        printf("\nLa ecuaci�n tiene raices reales.\n");
        printf("\nLa soluci�n para x1 es: %.2f", x1);
        printf("\nLa soluci�n para x2 es: %.2f", x2);
        printf("\n\nPresiona cualquier tecla para continuar.");

    }
    else
    {
        //Calculo de la soluciones para x1 y x2 (raices imaginarias)
        b=-b/(2*a);
        x1=sqrt(f*-1)/(2*a);
        x2=x1;

        printf("\nLa ecuaci�n tiene raices imaginarias.\n");
        printf("\nLa soluci�n para x1 es: %.2f + %.2fi", b, x1);
        printf("\nLa soluci�n para x2 es: %.2f - %.2fi", b, x2);
        printf("\n\nPresiona cualquier tecla para continuar.");

    }

}

int main()
{
    //Declaraci�n de variables locales
    char op[1];
    //Despliega el men� de la aplicaci�n
    do
    {
        //Limpia la pantalla de la consola
        system("cls");
        printf("Programa para resolver ecuaciones de 2do grado mediante la f�rmula general.\n\n");
        printf("Selecciona una opci�n del men�:\n");
        printf("\t1 Resolver ecuaci�n de 2do grado.\n");
        printf("\t2 Salir.\n");
        printf("\nIngresa la opci�n: ");
        scanf("%c",&op);
        //Permite seleccionar alguna de las opciones del men�
        switch(op[0])
        {
            //Opci�n "Resolver ecuaci�n de 2do grado"
        case '1':
            system("cls");
            ingresaV();
            getch();
            break;

        }
    }
    while(op[0]!='2'); //Mientras la opcion seleccionado sea diferente de 2 el men� se vuelve a desplegar en pantalla
    //Finaliza la ejecuci�n de la aplicaci�n
    return(0);
}


