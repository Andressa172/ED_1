#include<stdio.h>
#include<conio2.h>
#include<string.h>
#include<ctype.h>


int impar(int x);
int par(int x);
int impar(int x)
{
    if(x == 0)
        return 1;
    else
        return par(x-1);
}

int par(int x)
{
    if(x == 0)
        return 0;
    else
        return impar(x-1);
}

int main(void)
{
    int x, resultado;
    
    printf("\nDigite o numero para descobrir se e impar ou par: ");
    scanf("%d",&x);
    
    resultado = par(x);
    
    if(resultado == 0)
        printf("\nO numero %d = par",x);
    else
        printf("\nOnumero %d = impar",x);
        
    getch();
    
    return 0;
}
