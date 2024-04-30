#include<stdio.h>
#include<conio2.h>
#include<string.h>
#include<ctype.h>

int RestoDivisao(int x, int y) {
	if(x<y)
		return x;
	return RestoDivisao(x-y, y);
}

int main(void) {
    int a, b;
    printf("Resto da divisao de:\nA: ");
    scanf("%d", &a);
    printf("B: ");
    scanf("%d", &b);
    int x = RestoDivisao(a, b);
    printf("Resto da divisao: %d", x);
    return 0;
}
