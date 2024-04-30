#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>

struct TpPonteiro{
	int num;
	TpPonteiro *prox;
};

TpPonteiro *NovaCaixa(int VALOR){
	TpPonteiro *Caixa;
	Caixa = new TpPonteiro;
	Caixa -> num = VALOR;
	Caixa -> prox = NULL; 
	return Caixa;
}
