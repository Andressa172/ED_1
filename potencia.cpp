#include<stdio.h>
#include<string.h>
#include<ctype.h>

int potencia(int x, int y)
{
	if(y==0)
		return 1;
	else
		return x*potencia(x,y-1);
}

int main(void)
{
    int x, y;
    int result;
    printf("\nDigite base da potencia: ");
    scanf("%d", &x);
    printf("\nDigite expoente da potencia: ");
    scanf("%d", &y);
    result = potencia(x,y);
    printf("\n\n%d^%d = %d", x, y, result);
    
    return 0;
}
