 #include <stdio.h>
 #include <stdlib.h>
 #include <conio.h>
 #include <conio2.h>
 
 struct TpPont
 {
 	char info;
 	TpPont *prox;
 };
 
 struct TpDescritor
 {
 	TpPont *Ini, *Fim;
 	int qntd;
 };
 void inicializar(TpDescritor &Desc)
 {
 	Desc.qntd = 0;
 	Desc.Ini= Desc.Fim = NULL;
 }
 void InsORdenado(TpDescritor &Desc, char elem)
 {
 	TpPont *Nv = new TpPont; // criando um novo ponteiro
 	TpPont *Atu, *Ant;
 	// atribuindo os valores
 	Nv -> info = elem;
 	Nv -> prox = NULL;
 	
 	if(Desc.qntd == 0)
 		Desc.Ini = Desc.Fim = Nv; // sem elem então o inicio fim apontam para o mesmo lugar
	else
	{
		if(Nv -> info <= Desc.Ini -> info) // verificando se o elem vem antes do elemento que ja está ali
		{
			Nv -> prox = Desc.Ini;
			Desc.Ini = Nv;
		}
		else
			if(Nv -> info >= Desc.Fim -> info) // verifica se o elem vem depois do ultimo que ja esta ali
			{
				Desc.Fim -> prox = Nv;
				Desc.Fim = Nv;
			}
			else
			{
				Ant = Desc.Ini -> prox;
				Atu = Desc.Ini;
				while(Nv->info > Atu -> info)
				{
					Ant = Atu;
					Atu = Atu -> prox; // andando com o ponnteiro
				} // se sai do laço é pq achou a posição o elem entra entre ANTERIOR e ATUAL
				Nv->prox = Atu;
				Ant->prox = Nv;
			}
			Desc.qntd++;
	}
 }
