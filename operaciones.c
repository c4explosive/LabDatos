
#include <stdio.h>
#include <stdlib.h>
#include "stck.h" //Cambiar a <stck.h> y copiar el archivo stck.h a C:\tc\include...
void main()
{
    struct stack st1;
    clrscr();
    st1.top=0;
    mostrar(&st1);
}
