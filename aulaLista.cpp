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
	//	if(Lista == NULL)
//		{
//			Lista = Nv_caixa;
//		}
//		else
//		{
			Nv_caixa -> prox = Lista;
			Lista = Nv_caixa;
			// o primeiro elemento colocado vai pra frente e o proximo entra a tras 
			//[cabe] -> [elem2[pos]] -> [elem1[pos]]
			// o novo elemento aponta pro primeiro da caixa, assim substituindo a primeira posi��o
//		}
		printf("Elemento: ");
		elemento = getche();
	}
	 	
 	return Lista;
 }
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
			while(Lista -> prox != NULL )// com essa condi��o ele n�o exibe o ultimo elem
			{
				printf("%c\n",Lista->info);
				Lista = Lista -> prox; // faz a lista andar pra frente
				//[elem1[prox]] prox � a possi��o do proximo elemento
			}
				printf("%c\n",Lista->info);
				getch();
		}
}

 int main (void)
 {
 	TpPont *L = NULL;
 	
 	L=Inserir_Inicio(L);
 	Exibir_Lista(L);
	getch(); 	
 	return 0;
 }
 

