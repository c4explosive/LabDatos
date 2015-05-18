/*Lab de Pilas
Integrantes: Angel Espinosa
		    Heidys Miranda
Grupo: 1IL121
*/
#include<string.h>
#include <stdio.h>
#include <stdlib.h>
#include "stck.h"
//Cambiar a <stck.h> y copiar el archivo stck.h a C:\tc\include...
int operador(char d);
int operador1(char sim);
int operador2(char sim);
void postf(char infi[78],char exp[78]);
char tipoelem(struct stack *pil);

void dbgs(struct stack * st1)
{
    printf("PILA\n");
    mostrar(st1);
    printf("============\n");
}


void main()
{

    char exp[78];
    char infi[78];
    char conn[1];
    char cont;
    do
    {
    	clrscr();
    	printf("Conversion de una expresion Infija \n");
    	scanf("%s",infi);
	fflush(stdin);
    	postf(infi,exp);
	clrscr();
    	printf("Notacion Infija:\n");
    	printf("%s\n",infi);
    	printf("Conversion:\n");
    	printf("%s\n",exp);
    	getch();
	printf("¿Desea continuar?: ");
	scanf("%s",conn);
	fflush(stdin);
	cont=conn[0];
    }while (cont == 'S' || cont== 's');
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
  return( d=='(' || d=='^'|| d=='+'||d=='-'||d=='*'||d=='/' );
}

int oper(char d)
{
  return( d=='^'|| d=='+'||d=='-'||d=='*'||d=='/' );
}




void postf(char infi[78],char exp[78])
{
    struct stack st1;
    char d, mat[2];
    int i, apil=0;
    st1.top=0;
    lim(&st1);
    mat[1]='\0';
    exp[0]='\0';
    for(i=0;i<strlen(infi);i++)
    {
	if(operador(infi[i]))
    	{
	    if(infi[i] == '(' || vac(&st1) || operador2(st1.pila[st1.top])<operador1(infi[i]) )
	    {
		ins(&st1,infi[i]);
		if(infi[i]!='(' && exp[strlen(exp)-1] != ' ')
	    	    strcat(exp," ");
	    }
	    else
	    {
		do
		{
		    mat[0]=elim(&st1,st1.pila[st1.top]);
		    if (oper(mat[0]))
		    	strcat(exp,mat);
		    if(exp[strlen(exp)-1] != ' ')
	    	    	strcat(exp," ");
		}while (!(operador2(st1.pila[st1.top])<operador1(infi[i])) );
		ins(&st1,infi[i]);
	    }
      	}
	else if(infi[i]==')') //si encuentra este parentesis saca los operadores apilados en la pila
	{
	    do
	    {
		d=elim(&st1,st1.pila[st1.top]);
		mat[0]=d;
		if(exp[strlen(exp)-1] != ' ')
	    	    strcat(exp," ");
		if( d != '(')
		{
		    if (oper(d))
		    	strcat(exp,mat);
		}
	    } while(d != '(');

	}
	else
	{
	    mat[0]=infi[i];
	    strcat(exp,mat);
	}
    }
    do
    {
	d=elim(&st1,st1.pila[st1.top]);
	mat[0]=d;
	if( exp[strlen(exp)-1] != ' ')
	    strcat(exp," ");
	if (oper(mat[0]))
	    strcat(exp,mat);
    } while(st1.top!=0);

}
