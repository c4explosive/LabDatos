#include<string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stck.h>
//Cambiar a <stck.h> y copiar el archivo stck.h a C:\tc\include...

int operador1(char simb);
int operador2(char sim);
void prefi(char infi[78]);



void main()
{

    //char exp[78];
    char infi[78];

    clrscr();


    printf("Conversion de una expresion postfija \n");
    gets(infi);
    prefi(infi);
    //printf("Conversion\n");
    //printf("%s ",exp);
    getch();
}


int operador2(char sim)//evalua los operadores dentro de la pila
{

	if(sim=='^')
	return 3;
	if(sim=='/')
	return 2;
	if(sim=='*')
	return 2;
	if(sim=='+')
	return 1;
	if(sim=='-')
	return 1;
	else
	return 0;
}

int operador1(char simb) //evalua los operadores en prefija
{

	if(simb=='^')
	return 3;
	if(simb=='/')
	return 2;
	if(simb=='*')
	return 2;
	if(simb=='+')
	return 1;
	if(simb=='-')
	return 1;
	else
	return 0;
}



void prefi(char infi[78])
{
 struct stack st1;
 struct stack st2;
 int tam,i;
 char d;
 st1.top=-1;
 st2.top=-1;

 tam=strlen(infi);
 printf("size %d\n", tam);
 //vaciar(&st1);
 //vaciar(&st2);

 for(i=tam;i>=0;i--) //este for recorre del ultimo elemento al primero
 //no logro poder introducir los operadores a la pila 1
 //en la pila 2 si se introducen los elementos pero no de la manera en que debe salir como prefija
   {

     if(infi[i]=='^'|| infi[i]=='+'||infi[i]=='-'||infi[i]=='*'||infi[i]=='/');//si hay operandos lo agrega a la pila
     {
		if(&st1==NULL)//verifica si esta vacia y agrega el operador
		{
		ins(&st1,infi[i]);

		}


	      else//si no esta vacia
	      {
		//se compara con el operador2 los elementos que hay dentro de la pila
		if(operador1(infi[i])>operador2(infi[i]))//revisar lo que tiene la pila
		 {

		  ins(&st1,operador1(infi[i]));

		 }
		  else
		  {
			if(operador2(infi[i])==operador1(infi[i]))//revisar si lo que hay adentro es igual a la pila lo saca
			{

			 d=elim(&st1,infi[i]);

			 ins(&st2,d);

			// elim(&st1,infi[i]);
			 }
			 else
			 {

			 d=elim(&st1,infi[i]);//sacar el operador
			 ins(&st2,d); //agregar a la segunda estructura
			 }
		  }
      }



	  }
       }




   /*while(&st1!=NULL)
   {
    d=tipoelem(&st1);
    ins(&st2,d);
    } */

}


