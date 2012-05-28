/*Programa que resuelve ecuaciones de 2do grado, mediante el uso de la fórmula general.
*Creado por: Andrés de Jesús Hernández Martínez
*Grupo: 7ITI1
*Fecha de creación: 20 mayo de 2012
*Fecha de la última modificación: 20 mayo de 2012
*/

//Declaracion de librerias
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

//Declaración de funciones
void solucionE(float a, float b, float c);

//Función encargada de  mostrar en consola, la petición
//de variables para resolver la ecuación de 2do grado
void ingresaV(void)
{
    //Declaración de variables locales
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

    //Llamada a la función solucionE()
    solucionE(a,b,c);

}

//Función encargada de resolver la ecuación de 2do grado
void solucionE(float a, float b, float c)
{
    //Declaración de variables locales
    float x1, x2, f;

    //Calculo del discriminate
    f=b*b-4*a*c;

    //Verifica que el discrimiante sea mayor o igual que 0 (raices reales)
    if(f>=0)
    {
        //Calculo de las soluciones para x1 y x2
        x1=(-b+sqrt(f))/(2*a);
        x2=(-b-sqrt(f))/(2*a);

        printf("\nLa ecuación tiene raices reales.\n");
        printf("\nLa solución para x1 es: %.2f", x1);
        printf("\nLa solución para x2 es: %.2f", x2);
        printf("\n\nPresiona cualquier tecla para continuar.");

    }
    else
    {
        //Calculo de la soluciones para x1 y x2 (raices imaginarias)
        b=-b/(2*a);
        x1=sqrt(f*-1)/(2*a);
        x2=x1;

        printf("\nLa ecuación tiene raices imaginarias.\n");
        printf("\nLa solución para x1 es: %.2f + %.2fi", b, x1);
        printf("\nLa solución para x2 es: %.2f - %.2fi", b, x2);
        printf("\n\nPresiona cualquier tecla para continuar.");

    }

}

int main()
{
    //Declaración de variables locales
    char op[1];
    //Despliega el menú de la aplicación
    do
    {
        //Limpia la pantalla de la consola
        system("cls");
        printf("Programa para resolver ecuaciones de 2do grado mediante la fórmula general.\n\n");
        printf("Selecciona una opción del menú:\n");
        printf("\t1 Resolver ecuación de 2do grado.\n");
        printf("\t2 Salir.\n");
        printf("\nIngresa la opción: ");
        scanf("%c",&op);
        //Permite seleccionar alguna de las opciones del menú
        switch(op[0])
        {
            //Opción "Resolver ecuación de 2do grado"
        case '1':
            system("cls");
            ingresaV();
            getch();
            break;

        }
    }
    while(op[0]!='2'); //Mientras la opcion seleccionado sea diferente de 2 el menú se vuelve a desplegar en pantalla
    //Finaliza la ejecución de la aplicación
    return(0);
}


