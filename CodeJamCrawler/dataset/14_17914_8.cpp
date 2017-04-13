#include<stdio.h>

int main(void){

	int t, m;
	unsigned int a, b, k, i, j, l, count;
	scanf("%d",&t);
	unsigned int op[t];
//	printf("\n%d",2 & 3);
	for(i = 0; i < t; i++){
		count = 0;
		scanf("%d",&a);
		scanf("%d",&b);
		scanf("%d",&k);

//		printf("\nhello %d %d %d",a,b,k);
		
		for(j = 0; j < a; j++){
			for(l = 0; l < b; l++){
				if((j & l) >= 0 && (j & l) < k)
					count += 1;
			}
		}
		op[i] = count;
	}
	
	for(i = 0; i < t; i++)
		printf("Case #%d: %d\n",i+1,op[i]);
	
	return 0;
}
