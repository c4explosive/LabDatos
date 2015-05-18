#include <stdio.h>
#include <stdlib.h>
#include "stck2.h"

void main()
{
    struct stack st1;
    struct stack st2;
    struct stack st3;
    struct stack aux;
    int i;
    clrscr();
    st1.top=0; st2.top=0; st3.top=0; aux.top=0;
    for(i=12;i>=1;i--)
	ins(&st1,i);
    for(i=13;i<=24;i++)
	ins(&st2,i);
    mostrarmul(&st1,&st2,&st3);
    copiar(&st1,&st3);
    mostrarmul(&st1,&st2,&st3);
    copiar(&st2,&aux);
    copiar(&aux,&st3);
    mostrarmul(&st1,&st2,&st3);
}
