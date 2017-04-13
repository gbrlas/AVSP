#include<stdio.h>

int n,t,k,ligado,a=1;

unsigned int valor,teste;

int main (void) {
	scanf("%d",&t);
	for (;t>0;t--,a++) {
		ligado=0;
		scanf("%d %d",&n,&k);
		valor = 1 << n;
		teste = k % valor;
		if (teste == valor - 1) {
			printf("Case #%u: ON\n",a);
		}
		else{
			printf("Case #%u: OFF\n",a);
		}
	}
	return(0);
}