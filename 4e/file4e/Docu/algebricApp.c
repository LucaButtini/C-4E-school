#include <stdio.h>

int add(int a, int b)
{
    return a+b;
}

int mul(int a, int b)
{
    return a*b;
}

int sub (int a, int b)
{
    return a-b;
}

double division(int a, int b)
{
    return a/b;
}

void main(){
    printf("%d\n",add(6,3));
    printf("%d\n",mul(6,3));
    printf("%d\n",sub(6,3));
    printf("%f\n",division(6,3));
}
