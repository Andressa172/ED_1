#include<stdio.h>
#include<string.h>
#include<conio2.h>
#include<ctype.h>

void Inverter(int vet[], int i, int j){
    if (i < j) {
        int temp = vet[i];
        vet[i] = vet[j];
        vet[j] = temp;
        
        Inverter(vet, i +1, j -1);
    }
}

int main(void){
    int vetor[5];
    int TL = 5;
    
    printf("Digite os elementos do vetor: ");
    for(int i = 0; i < TL; i++){
        printf("Digite o elem %d: ", i+1);
        scanf("%d", &vetor[i]);
    }
    
    printf("Ordem inversa do vetor: ");
    Inverter(vetor, 0, TL - 1);
    
    for(int i = 0; i < TL; i++)
        printf("%d ", vetor[i]);
    
    getch();
    return 0;
}

