#include <stdio.h>
#include <stdlib.h>
struct mystruct {
    int val;
    char sex;
    char word[10];
};
void ass(struct mystruct * n3, char n)
{
    n3->word[1]=n;
}
void print(struct mystruct * n3)
{
    printf("%c\n",n3->word[1]);
}
void main()
{
    struct mystruct n1;
    struct mystruct n2;
    printf("%d\n",n1.val);
    /*ass(&n1,'c');
    ass(&n2,'a');
    print(&n1);
    print(&n2);*/
}
