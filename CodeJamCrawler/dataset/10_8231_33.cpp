#include<stdio.h>

int n,t,k,ligado,a=1;

int valor,teste;

int main (void) {
	scanf("%d",&t);
	for (;t>0;t--,a++) {
		ligado=0;
		scanf("%d %d",&n,&k);
		valor = 1 << n;
		teste = k % valor;
		//printf("teste = %d\n",teste);
		if (teste == valor - 1) {
			printf("Case #%d: ON\n",a);
		}
		else{
			printf("Case #%d: OFF\n",a);
		}
	}
	return(0);
}