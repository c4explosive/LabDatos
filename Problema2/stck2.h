#include <stdio.h>
#include <stdlib.h>
#define clrscr() system("clear")
#define getch() system("read")
#define TAM 24
//#ifndef _STCK_H
#define _STCK_H
//int valor;
struct stack
{
	int pila[TAM];
	int top;
};

//Insercción (Push)
void ins(struct stack * pil,int val)
{
     if (pil->top == TAM)
	printf("Desbordamineto\n");
     else
     {
	pil->top++;
	pil->pila[pil->top]=val;
	//printf("TOP: %d\n",pil->top);
	//pil->pila[0]=val;
     }
}

//Eliminación (Pop)
int elim(struct stack * pil, int val)
{
    int i, pres=0;
    for (i=pil->top;i>0;i--)
    {
	if (pil->pila[i] == val)
	{
	    pres=1;
	    break;
	}
	else
	    pres=0;
    }
    if(pil->top==0)
	printf("Vacío\n");
    if ( pil->pila[pil->top] == val && pres)
    {
	val=pil->pila[pil->top];
	pil->top--;
	return val;
    }
    else if (pil->pila[pil->top] != val && pres)
    {
	for(i=pil->top;i>=0;i--)
	{
	    if ( pil->pila[i] != val)
		pil->top--;
	    else
	    {
		pil->top--;
		return val;
		break;
	    }
	}
    }
    else if (pres == 0)
	printf("El elemento no existe\n");
}

//Pila Vacía (Empty)
int vac(struct stack * pil)
{
    if(pil->top == 0)
	return 1;
    else
	return 0;
}

//Pila Llena (Full)
int lle(struct stack *pil)
{
    if(pil->top == TAM)
	return 1;
    else
	return 0;
}

//Vaciar en otra pila
void vaciar(struct stack *pil, struct stack *pil2)
{
    int i,j;
    if ( vac(pil) && lle(pil2) )
	printf("La primera pila esta vacía y la segunda está llena");
    else if (vac(pil))
	printf("La primera pila esta vacía\n");
    else if (lle(pil2))
	printf("La Segunda pila esta llena\n");
    else
    //else if (vac(pil2))
    {
	for (i=pil->top;i>=1;i--)
	{
	    ins(pil2,elim(pil,pil->pila[pil->top]));
	    
	}
    }
}

//Copiar en otra pila
void copiar(struct stack *pil, struct stack *pil2)
{
    int i,j,topb;
    topb=pil->top;
    if ( vac(pil) && lle(pil2) )
	printf("La primera pila esta vacía y la segunda está llena");
    else if (vac(pil))
	printf("La primera pila esta vacía\n");
    else if (lle(pil2))
	printf("La Segunda pila esta llena\n");
    else
    //else if (vac(pil2))
    {
	for (i=pil->top;i>=1;i--)
	{
	    ins(pil2,pil->pila[pil->top]);
	    pil->top--;
	}
	pil->top=topb;
    }
}

//Mostrar la pila
void mostrar(struct stack *pil)
{
    int i;
    if(vac(pil))
	printf("La pila está vacía.\n");
    else
    {
	for(i= pil->top;i>=1;i--)
	//if ( i == 1)
	    printf("%d\n",pil->pila[i]);
	/*else
	    printf("%c\n",pil->pila[i]);*/
    }
}



//Mostrar varias pilas (3)
void mostrarmul(struct stack *pil,struct stack * pil2,struct stack * pil3)
{
    int i=pil->top, j=pil2->top, k=pil3->top;
    printf("PILA 1\t PILA 2\t PILA 3\n");
    do
    {
	//printf(" i=%d, j=%d, k=%d\n",i,j,k);
	if (i>=1)
	    printf("%d\t",pil->pila[i]);
	else
	    printf("\t");
	if (j>=1)
	    printf(" %d\t",pil2->pila[j]);
	else
	    printf("\t");
	if (k>=1)
	    printf(" %d\n",pil3->pila[k]);
	else
	    printf("\t\n");
	i--;
	j--;
	k--;
    } while(i>=1 || j>=1 || k>=1 );
}

