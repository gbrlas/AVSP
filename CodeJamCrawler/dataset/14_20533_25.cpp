#include<iostream>

using namespace std;

int main(){
	int t;
	scanf("%d", &t);
	int i,j,k;
	int a1,a2;
	int cards1[4][4], cards2[4][4];
	for(i=1;i<=t;i++){
		scanf("%d",&a1);
		for(j=0;j<4;j++)
			for(k=0;k<4;k++)
				scanf("%d",&cards1[j][k]);

		scanf("%d",&a2);
		for(j=0;j<4;j++)
			for(k=0;k<4;k++)
				scanf("%d",&cards2[j][k]);
	
		int count=0, value;
		a1-=1;
		a2-=1;
		for(j=0;j<4;j++){
			for(k=0;k<4;k++){
				if(cards1[a1][j] == cards2[a2][k]){
					count++;
					value = cards1[a1][j];
				}
			}

		}
		
		printf("Case #%d: ", i);

		if(count==0)
			printf("Volunteer cheated!");
		else if(count>1)
			printf("Bad magician!");
		else
			printf("%d", value);
		printf("\n");
	}
	return 0;
}