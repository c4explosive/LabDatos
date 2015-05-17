#include<string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stck.h>
//Cambiar a <stck.h> y copiar el archivo stck.h a C:\tc\include...
int operador(char d);
int operador1(char sim);
int operador2(char sim);
void postf(char infi[78],char exp[78]);



void main()
{

    char exp[78];
    char infi[78];

    clrscr();


    printf("Conversion de una expresion Infija \n");
    gets(infi);
    postf(infi,exp);
    printf("Conversion\n");
    printf("%s ",exp);
    getch();
}


int operador2(char sim)//evalua los operadores dentro de la pila
{
	if(sim=='(')
	return 0;
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

int operador1(char sim) //evalua los operadores en infija
{
	if(sim=='(')
	return 5;
	if(sim=='^')
	return 4;
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

int operador(char d)
{
  return( d=='(' || d=='^'|| d=='+'||d=='-'||d=='*'||d=='/');
}


void postf(char infi[78],char exp[78])
{
 struct stack st1;

 char d, mat[2];
 int i, apil=0;
 vaciar(&st1);
 st1.top=-1;
 mat[1]='\0';
 exp[0]='\0';


 for(i=0;i<strlen(infi);i++)
      if(operador(infi[i]))
	  {
	    while(!apil)
	     {
		if(vac(&st1))
		{
			ins(&st1,infi[i]);
			apil=1;
		}
		else
		 {
			d=tipoelem(&st1);
			if(operador2(d)>=operador1(infi[i]))
				{
					mat[0]=d;
					strcat(exp,mat);
					elim(&st1,infi[i]);
				}
			else
				{
					ins(&st1,infi[i]);
					apil=1;
				}
		 }
	   }   }
	     else
	     {
		if(infi[i]==')') //si encuentra este parentesis saca los operadores apilados en la pila
			{
				d=tipoelem(&st1);
				elim(&st1,infi[i]);
					while(d!='(')
					{
					 mat[0]=d;
					 strcat(exp,mat);
					 d=tipoelem(&st1);
					 elim(&st1,infi[i]);
			}
		  }
		 else
			{
			 mat[0]=infi[i];
			 strcat(exp,mat);
			}
	       }

	  while(!vac(&st1))
	  {
	  d=tipoelem(&st1);
	  elim(&st1,infi[i]);
	  mat[0]=d;
	  strcat(exp,mat);
	   }


 }


