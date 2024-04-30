#include<stdio.h>
#include<conio2.h>
#include<ctype.h>
#include<string.h>

//função que calcula o fibonacci de um elemento X
int fibonacci(int n)
{
    
    if(n < 2)
        return 1;
    else
        return fibonacci(n-1) + fibonacci(n-2);
}

int main(void)
{
    int n, resultado;
    
    printf("\nDigite qual elemento voce deseja obter o fibonacci: ");
    scanf("%d",&n);
    
    resultado = fibonacci(n);
    printf("\nPosicao = %d\tFibonacci = %d\n",n,resultado);
    
    return 0;
}
