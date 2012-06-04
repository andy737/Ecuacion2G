/*Programa que resuelve ecuaciones de 2do grado, mediante el uso de la f�rmula general.
*Creado por: Andr�s de Jes�s Hern�ndez Mart�nez
             Idania Aquino Cruz
             Janet Zavala Rodr�guez
*Grupo: 7ITI1
*Fecha de creaci�n: 20 mayo de 2012
*Fecha de la �ltima modificaci�n: 03 junio de 2012
*/

//Declaracion de librerias
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>


//Declaraci�n de funciones
void solucionE(float a, float b, float c);
int error(int tmp);
int valida(char array[]);

//Validaci�n de error de entrada de datos
int error(int tmp)
{
    if(tmp>0)
    {
        system("cls");
        printf("\nEntrada de datos incorrecta.(Presiona cualquier tecla para continuar)");
        getch();
        tmp=0;
    }
    else
    {
        tmp=0;
    }
    return tmp;

}

//Validaci�n de n�meros flotantes y enteros (+,-)
int validaFE(char array[])
{
    //Declaraci�n de variables locales
    int i, val=0, cont=0,tam=0;
    while(array[tam]!='\0')//Calcula el tama�o del array
        tam++;
    if((array[0]!='.')&&(array[0]!=13)&&(array[tam]!='.')&&tam<=5)//Valida que al inicio y al final del array no contenga un punto y que el n�mero maximo de d�gitos sea 5
    {
        for(i=0; i<tam; i++)
        {

            if(array[0]=='-')//Valida signo negativo en los numeros
            {

                if(((array[i]<=57)&&(array[i]>=48)&&(cont<=1))||(array[i]=='.'))//Valida que el array sea un numero flotante o entero
                {
                    if(array[i]=='.')
                    {
                        cont++;
                    }

                    val=1;

                }
                else
                {
                    if(i!=0)
                    {
                        val=0;
                        break;
                    }

                }
            }
            else//Signo positivo en los numeros
            {
                if(((array[i]<=57)&&(array[i]>=48)&&(cont<=1))||(array[i]=='.'))//Valida que el array sea un numero flotante o entero
                {

                    if(array[i]=='.')
                    {
                        cont++;
                    }

                    val=1;

                }
                else
                {

                    val=0;
                    break;


                }
            }
        }
    }

    return val;

}

//Funci�n encargada de  mostrar en consola, la petici�n
//de variables para resolver la ecuaci�n de 2do grado
void ingresaV(void)
{
    //Declaraci�n de variables locales
    float a,b,c;
    char a1[5], b1[5], c1[5];
    int tmp=0,val;

    do
    {

        tmp=error(tmp);//Llamada a la funci�n validar entrada
        system("cls");//Limpia la pantalla de consola
        printf("\nIngresa el valor(m�ximo 5 d�gitos #.###,#####,-#.## o -####) de la variable a:\n");
        fflush (stdin);//Limpia el buffer de entrada
        gets(a1);//Recibe la entrada del teclado y al almacena en el array
        val=validaFE(a1);//Llama a la funcion validar numeros
        if(val==1)//Verificador de entero o flotante
        {
            a=atof(a1);//Convierte el array en un numero flotante
        }

        tmp++; //Verificador de error
    }
    while(val==0); //Valida si la entrada es un d�gito
    tmp=0;//Puesta a 0 para requerir la proxima variable

    //Verifica que la variable "a" sea diferente de 0
    while(a==0)
    {

        system("cls");
        printf("\nEl valor de la variable \"a\" debe ser distinto de 0.\n\n(Presiona cualquier tecla para continuar)");
        getch();//Espera hasta que se pulse una tecla

        //Valida que solo se ingresen numeros
        do
        {
            tmp=error(tmp);//Llamada a la funci�n validar entrada
            system("cls");
            printf("\nIngresa el valor(m�ximo 5 d�gitos #.###,#####,-#.## o -####) de la variable a:\n");
            fflush (stdin);//Limpia el buffer de entrada
            gets(a1);//Recibe la entrada del teclado y al almacena en el array
            val=validaFE(a1);//Llama a la funcion validar numeros
            if(val==1)
            {
                a=atof(a1);//Convierte el array en un numero flotante
            }
            tmp++;
        }
        while(val==0);
        tmp=0;
    }

    do
    {
        tmp=error(tmp);//Llamada a la funci�n validar entrada
        system("cls");
        printf("\nIngresa el valor(m�ximo 5 d�gitos #.###,#####,-#.## o -####) de la variable b:\n");
        fflush (stdin);//Limpia el buffer de entrada
        gets(b1);//Recibe la entrada del teclado y al almacena en el array
        val=validaFE(b1);//Llama a la funcion validar numeros
        if(val==1)
        {
            b=atof(b1);//Convierte el array en un numero flotante
        }
        tmp++;
    }
    while(val==0);
    tmp=0;

    do
    {
        tmp=error(tmp);//Llamada a la funci�n validar entrada
        system("cls");
        printf("\nIngresa el valor(m�ximo 5 d�gitos #.###,#####,-#.## o -####) de la variable c:\n");
        fflush (stdin);//Limpia el buffer de entrada
        gets(c1);//Recibe la entrada del teclado y al almacena en el array
        val=validaFE(c1);//Llama a la funcion validar numeros
        if(val==1)
        {
            c=atof(c1);//Convierte el array en un nuemro flotante
        }
        tmp++;
    }
    while(val==0);
    tmp=0;
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
        //Imprime resultados
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
        //Imprime resultados
        printf("\nLa ecuaci�n tiene raices imaginarias.\n");
        printf("\nLa soluci�n para x1 es: %.2f + %.2fi", b, x1);
        printf("\nLa soluci�n para x2 es: %.2f - %.2fi", b, x2);
        printf("\n\nPresiona cualquier tecla para continuar.");

    }

}

int main()
{
    //Declaraci�n de variables locales
    int op;
    //Despliega el men� de la aplicaci�n
    do
    {
        system("cls");//Limpia la pantalla de la consola
        printf("Programa para resolver ecuaciones de 2do grado mediante la f�rmula general.\n\n");
        printf("Selecciona una opci�n del men�:\n");
        printf("\t1 Resolver ecuaci�n de 2do grado.\n");
        printf("\t2 Salir.\n");
        printf("\nIngresa la opci�n: ");
        fflush (stdin);//Limpia el buffer de entrada
        scanf("%i",&op);//Recibe la entrada del teclado
        //Permite seleccionar alguna de las opciones del men�
        switch(op)
        {
            //Opci�n "Resolver ecuaci�n de 2do grado"
        case 1:
            system("cls");
            ingresaV();
            getch();//Espera hasta que se pulse una tecla
            break;
        case 2:
            system("cls");
            //Finaliza la ejecuci�n de la aplicaci�n
            return(0);
            break;
            //Evalua las opciones no validas
        default:
            printf("\nOpci�n incorrecta.(Presiona cualquier tecla para continuar)");
            getch();
            break;
        }
    }
    while(op!=2); //Mientras la opcion seleccionado sea diferente de 2 el men� se vuelve a desplegar en pantalla
    system("cls");
    //Finaliza la ejecuci�n de la aplicaci�n
    return(0);
}



