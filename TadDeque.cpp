#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>

struct TpPont{
	char Elem;
	TpPont *ant, *prox;
};

struct TpDEQUE{
	TpPont *Cab, *Cauda;
};

void Inicializar(TpDEQUE *Desc){
	Desc->Cab =NULL;
	Desc->Cauda = NULL;
}

int Vazio(TpDEQUE *Desc){
	
	return (Desc->Cab==NULL);
}

TpPont *InserirCabeca(TpDEQUE *Desc, char Elem){
	TpPont *novo = new TpPont;
	novo->Elem = Elem;
	novo->ant = NULL;
	novo->prox = Desc->Cab;
	return novo;
}

TpPont *InserirCauda(TpDEQUE *Desc, char Elem){
	TpPont *novo = new TpPont;
	novo->Elem=Elem;
	novo->ant = Desc->Cauda;
	novo->prox = NULL;
}

TpPont *RetirarCabeca(TpDEQUE *Desc){
	if(Desc->Cab==NULL){
		return NULL;
	}
	
	TpPont *remove = Desc->Cab;
	Desc->Cab = Desc->Cab->prox;

    if (Desc->Cab == NULL) {
        Desc->Cauda = NULL;
    } else {
        Desc->Cab->ant = NULL;
    }

    remove->prox = NULL;
    return remove;
}

TpPont *RetirarCauda(TpDEQUE *Desc) {
    if (Desc->Cauda == NULL) {
        return NULL;
    }

    TpPont *remove = Desc->Cauda;
    Desc->Cauda = Desc->Cauda->ant;

    if (Desc->Cauda == NULL) {
        Desc->Cab = NULL;
    } else
        Desc->Cauda->prox = NULL;
    

    remove->ant = NULL;
    return remove;
}



/*
void ImprimirDEQUE(TpDEQUE *Desc) {
    TpPont *atual = Desc->Cab;
    while (atual != NULL) {
        printf("%c ", atual->Elem);
        atual = atual->prox;
    }
    printf("\n");
}

int main() {
    TpDEQUE deque;
    Inicializar(&deque);
	
    InserirCabeca(&deque, 'A');
    InserirCabeca(&deque, 'B');
    InserirCauda(&deque, 'C');
    InserirCauda(&deque, 'D');

    ImprimirDEQUE(&deque);

    TpPont *remove = RetirarCabeca(&deque);
    if (remove != NULL) {
        printf("Removido da cabeca: %c\n", remove->Elem);
        delete remove;
    }

    remove = RetirarCauda(&deque);
    if (remove != NULL) {
        printf("Removido da cauda: %c\n", remove->Elem);
        delete remove;
    }
    ImprimirDEQUE(&deque);
    return 0;
}
*/
