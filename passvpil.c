#include <stdio.h>
#include <stdlib.h>
#include "stck.h"

void main()
{
    struct stack st1;
    struct stack st2;
    struct stack st3;
    st1.top=0; st2.top=0; st3.top=0;
    ins(&st1,'1'); ins(&st1,'2'); ins(&st1,'3'); ins(&st1,'4');
    ins(&st2,'r'); ins(&st2,'t'); ins(&st2,'s'); ins(&st2,'u');
    ins(&st3,'a'); ins(&st3,'b'); ins(&st3,'c'); ins(&st3,'h');
    ins(&st1,'w');
    mostrarmul(&st1,&st2,&st3);
    vaciar(&st1,&st2);
    mostrarmul(&st1,&st2,&st3);
    vaciar(&st2,&st3);
    mostrarmul(&st1,&st2,&st3);
    vaciar(&st3,&st1);
    mostrarmul(&st1,&st2,&st3);
}
