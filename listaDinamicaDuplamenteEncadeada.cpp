 #include <stdio.h>
 #include <stdlib.h>
 #include <conio.h>
 #include <conio2.h>
 
 struct TpPont{
 	char Info;
 	TpPont *ant, *prox;
 };
 
 TpPont *NovaCaixa(char Elem)
 {
 	TpPont *Caixa;
 	Caixa = new TpPont;
 	Caixa -> Info = Elem;
 	Caixa -> ant = NULL;
	Caixa -> prox = NULL;
 	return Caixa;
 }
