/*Lab de Pilas
Integrantes: Angel Espinosa
		    Heidys Miranda
Grupo: 1IL121
*/
#include <stdio.h>
#include <stdlib.h>
#include "stck.h" //Cambiar a <stck.h> y copiar el archivo stck.h a C:\tc\include...
void main()
{
    struct stack st1;
    int cont=1,op;
    st1.top=0;
    char* elem=malloc(sizeof(char));
    do
    {
    	clrscr();
	printf("\t\t\tOperaciones con Pilas\n");
	printf("1. Insertar Elementos\n");
	printf("2. Eliminar Elementos\n");
	printf("3. Salir\n");
	printf("Ingrese una opcion: ");
	scanf("%d",&op);
	fflush(stdin);
	switch(op)
	{
	    case 1: printf("Ingrese el elemento a insertar: ");
		    scanf("%s",elem);
		    fflush(stdin);
		    ins(&st1,elem[0]);
		    printf("PILA\n");
    		    mostrar(&st1);
		    getch();
		    break;
	    case 2: printf("Ingrese el elemento hasta donde eliminar: ");
		    scanf("%s",elem);
		    fflush(stdin);
		    elim(&st1,elem[0]);
		    printf("PILA\n");
    		    mostrar(&st1);
		    getch();
		    break;
	    case 3: cont=0; break; 
	    default: printf("No existe esa operacion\n");
	}
    } while(cont);
}
