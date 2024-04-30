#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int MDC(int x, int y)
{

    if(y==0)
    {
        return x;
    }
    else
    {
        
        MDC(y,x%y);
    }
    
}
int main(void)
{    
    int x = MDC(20,16);
    printf("%d", x);
}
