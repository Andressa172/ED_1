 #include <stdio.h>
 #include <stdlib.h>
 #include <conio.h>
 #include <conio2.h>
 
 struct TpPont{
 	char info;
 	TpPont *prox;
 };
 
 TpPont *NovaCaixa(char Elem)
 {
 	TpPont *Caixa;
 	Caixa = new TpPont;
 	Caixa -> info = Elem;
 	Caixa -> prox = NULL;
 	return Caixa;
 }
 
 TpPont *Inserir_Inicio(TpPont *Lista)
 {
 	TpPont *Nv_caixa;
 	char elemento;
	printf("** Inserir no incio **\n");
	
	printf("Elemento: ");
	elemento = getche();
	while(elemento != 27)
	{
		Nv_caixa = NovaCaixa(elemento);
		Nv_caixa -> prox = Lista;  //pular para o proximo elemento
		Lista = Nv_caixa;

		printf("Elemento: ");
		elemento = getche();
	}
	 	
 	return Lista;
 }
 TpPont *Inserir_Final(TpPont *Lista)
 {
 	TpPont *Nv_caixa;
 	char elemento;
	printf("** Inserir no incio **\n");
	
	printf("Elemento: ");
	elemento = getche();
	while(elemento != 27)
	{
		Nv_caixa = NovaCaixa(elemento);
		if(Lista == NULL)
		{
			Lista = Nv_caixa;
		}
		else
		{
			Nv_caixa -> prox = Lista;
			Lista = Nv_caixa;
		}
		printf("Elemento: ");
		elemento = getche();
	}
	 	
 	return Lista;
 }
 
 TpPont *Exclusao(TpPont *Lista)
 {
 	TpPont *aux, *ant;
 	char Elem;
 	clrscr(); printf("\n** Exclusao **\n");
 	printf("\nElemeno a excluir": );
 	Elem = getche();
 	while(Lista != NULL && Elem != 27){
 		if (Elemento == Lista -> info){
 			aux = Lista;
 			Lista = Lista -> prox;
 			delete(aux);
 			printf("\nElemento [%c] deletado\n", Elem);
 		}
 		else{
		 	 aux = Lista -> prox;
 			 ant = Lista; //***
			 while(aux != NULL && aux -> info != Elem){
 				ant = aux;
				aux = aux -> prox;
 			}
 			
 			if(aux -> info == Elem){
 				ant -> prox = aux -> prox;
				delete(aux);
				printf("\nElemento [%c] deletado\n", Elem);
 			}
 			else
 				printf("\nElemento NAO encontrado\n\n");
 				
 		}
 		printf("\nElemeno a excluir": );
 		Elem = getche();
 	}
 	return Lista;
 }
 //insercao ordenada
 void Exibir_Lista(TpPont *Lista)
{
		clrscr();
		printf("** Elementos da Lista **\n");
		if(Lista==NULL)
		{
			printf("** Lista Vazia **\n");
		}
		else
		{
			while(Lista -> prox != NULL )// com essa condição ele não exibe o ultimo elem
			{
				printf("%c\n",Lista->info);
				Lista = Lista -> prox; // faz a lista andar pra frente
				//[elem1[prox]] prox é a possição do proximo elemento
			}
				printf("%c\n",Lista->info);
				getch();
		}
}

 int main (void)
 {
 	TpPont *L = NULL;
 	
 	L=Inserir_Inicio(L);
 	L=Exclusao(L);
 	Exibir_Lista(L);
	getch(); 	
 	return 0;
 }
 

