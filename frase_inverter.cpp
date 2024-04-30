#include<stdio.h>
#include<string.h>
#include<conio2.h>
#include<ctype.h>

void InverterFrase(char vet[], int TL){
	
	for(int i = TL - 1; i>=0; i--)
		printf("%c ", vet[i]);
} 

//arrumar

int main(void){
	char vetor[50];

	printf("Digite a frase: ");
	gets(vetor);
	
	int tamanho = strlen(vetor);
	InverterFrase(vetor, tamanho);
	printf("\nInvertida: %s", vetor);;
	
	getch();
	return 0;
}
