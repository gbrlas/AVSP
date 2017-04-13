#include<stdio.h>

int main(void){

	int t, fir, sec, a[4][4] = {0}, b[4][4] = {0}, i, j, k, l, m, count=0, temp,s;
	scanf("%d",&t);
	char *op[t];
	int oup[t];
	for(i = 0; i < t; i++)
		oup[i] = 0;
	for(m = 1; m <= t; m++){
		count = 0;
/*		for(i = 0; i < 4; i++){
			for(j = 0; j < 4; j++)
				a[i][j] = b[i][j] = 0;
		}
*/		scanf("%d",&fir);
		for(i = 0; i < 4; i++){
			for(j = 0; j < 4; j++)
				scanf("%d", &a[i][j]);
		}
		scanf("%d",&sec);
		for(i = 0; i < 4; i++){
			for(j = 0; j < 4; j++)
				scanf("%d", &b[i][j]);
		}
		
		for(i = fir-1,k = 0; k < 4; k++){
			for(j = sec-1,l = 0; l < 4; l++)
				if(a[i][k] == b[j][l]){
					count++;
					temp = a[i][k];
				}
				else continue;
		}
		
		if(count==0)
			op[m-1] = "Volunteer cheated!";
		else if(count==1)
			oup[m-1] = temp;
			
		else
			op[m-1] = "Bad Magician!";
	}
	
	for(m = 0; m < t; m++){
		if(oup[m]!=0)
			printf("Case #%d: %d\n",m+1,oup[m]);
			
		else 
		printf("Case #%d: %s\n",m+1,op[m]);
	}
	return 0;
}
