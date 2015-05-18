/*Lab de Pilas
Integrantes: Angel Espinosa
		    Heidys Miranda
Grupo: 1IL121
*/
#include<string.h>
#include <stdio.h>
#include <stdlib.h>
#include "stck.h"
#define cch 500
//Cambiar a <stck.h> y copiar el archivo stck.h a C:\tc\include...
int operador(char d);
int operador1(char sim);
int operador2(char sim);
void copytexp(struct stack * pil, char *exp);
void pore(char infi[78],char exp[78]);

char * scan(char * cad) 
{
    char * input=malloc(cch*sizeof(char)); 
    fflush(stdin); 
    fgets(input,cch*sizeof(char),stdin); 
    sscanf(input,"%[^\n]%*c",cad);
    return cad;

}
void dbgs(struct stack * st1)
{
    printf("PILA\n");
    mostrar(st1);
    printf("============\n");
}
/*
int spaces(char * exp)
{
    int nosp=0, sp=0,i;
    for(i=0;i<strlen(exp);i++)
    {
	if ( exp[i] == ' ')
	    sp++;
    }
    if ( sp != 0)
	return 1;
    else
    {
	printf("La expresión está mal escrita, corrija los espacios: \n");
	return 0;
    }
}*/

void main()
{

    char exp[78];
    char * pos=malloc(cch*sizeof(char));
    char conn[1];
    char cont;
    	clrscr();
    	printf("Conversion de una expresion Postfija \n");
	/*do
	{*/
    	    pos=scan(pos);
	    fflush(stdin);
	    pref(pos,exp);
	/*}while(!spaces(pos));*/
    	/*postf(infi,exp);
	clrscr();
    	printf("Notacion Infija:\n");
    	printf("%s\n",infi);*/
    	printf("Conversion:\n");
    	printf("%s\n",exp);
    	getch();
}

int operador(char d)
{
  return( d=='(' || d=='^'|| d=='+'||d=='-'||d=='*'||d=='/' );
}

int oper(char d)
{
  return( d=='^'|| d=='+'||d=='-'||d=='*'||d=='/' );
}




void pref(char prefi[78],char exp[78])
{
    struct stack st1;
    struct stack st2;
    struct stack st3;
    int cn=0;
    int i, apil=0;
    st1.top=0;
    st2.top=0;
    st3.top=0;
    lim(&st1);
    exp[0]='\0';
    for(i=strlen(prefi)-1;i>=0;i--)
    {
	if( oper(prefi[i]))
	    ins(&st2,prefi[i]);
	else
	{
	    ins(&st1,prefi[i]);
	    cn++;
	}
	if (cn==2)
	{
	    vaciar(&st1,&st3);
	    ins(&st3,elim(&st2,st2.pila[st2.top]));
	    cn=0;
	}
    }
    //mostrarmul(&st1,&st2,&st3);
    copytexp(&st2,exp);
    copytexp(&st1,exp);
    copytexp(&st3,exp);
    
}

void copytexp(struct stack * pil, char *exp)
{
    char d, mat[2];
    mat[1]='\0';
    do 
    {
	if(pil->top!=0)
	{
	   d=elim(pil,pil->pila[pil->top]);
	   mat[0]=d;
	   strcat(exp,mat);
	   strcat(exp," ");
	}
	else
	   break;
    }while(pil->top!=0);
}
