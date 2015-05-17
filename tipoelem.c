char tipoelem(struct stack *pil)
{
    char aux;
    if(vac(pil))
    {
 	printf("Se esta intentado sacar un elemento en una pila vacia");
    }
    aux=pil->pila[pil->top];
    return aux;
}
