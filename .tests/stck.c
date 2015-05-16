#include <stdio.h>
#include <stdlib.h>
#define clrscr() system("clear")
#define getch() system("read")
#define TAM 10
int valor;
struct stack 
{
        int pila[TAM];
    	int top;
};

//Insercción (Push)
void ins(struct stack * pil,int val)
{
     if (pil->top == TAM)
     	printf("Desbordamineto");
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
	valor=pil->pila[pil->top];
	pil->top--;
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
		break;
		return valor;
	    }
	}
    }
    else if (pres == 0)
	printf("El elemento no existe\n");
    return valor;
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

//Mostrar la pila
void mostrar(struct stack *pil)
{
    int i;
    if(vac(pil))
	printf("La pila está vacía.\n");
    else
    {
	for(i= pil->top;i>=1;i--)
	    printf("%d\n",pil->pila[i]);
    }
}

int main()
{
    /*struct stack pila1;
    struct stack pila2;
    struct stack pila3;
    pila1.top=0;
    pila2.top=0;
    pila3.top=0;
    ins(&pila1,2);
    ins(&pila1,7);
    ins(&pila2,5);
    ins(&pila2,8);
    ins(&pila2,9);
    ins(&pila2,8);
    ins(&pila2,2);
    elim(&pila2,5);
    ins(&pila2,3);
    ins(&pila2,8);
    ins(&pila3,4);
    ins(&pila3,4);
    printf("Pila 1: \n");
    mostrar(&pila1);   
    printf("Pila 2: \n");
    mostrar(&pila2);   
    printf("Pila 3: \n");
    mostrar(&pila3);   
    return 0; */
}


