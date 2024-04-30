#include<stdio.h>
#include<conio2.h>
#include<string.h>
#include<ctype.h>

int Mult1(int x, int y)
{
	int anterior , result;
	if(x>0 && y>0)
	{
		if(y==1)
			return x;
		else{
			return x + Mult1(x, y - 1);
		}
	}
}	

int Mult(int x, int x1, int y)
{
	int anterior , result;
	if(x>0 && y>0)
	{
		if(y==1)
			return x;
		else{
			result = x1 + x;
			return Mult(result,x1, y - 1);
		}
	}
}	

//int Mult (int x, int y) {
//	if (y == 0) {
//		return x;
//	} 
//	else {
//		return x + Mult(x, y - 1);
//	}
//}

int main(void){
	int x, y, z;
	printf("Digite valor x: ");
	scanf("%d", &x);
	printf("Digite valor y: ");
	scanf("%d", &y);
	z = Mult1(x,y);
	printf("Resultado: %d", z);
	return 0;	
}
