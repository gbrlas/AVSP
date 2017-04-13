#include<stdio.h>
#include<string.h>


int main(){
	int nt;
	int chosen[20];
	int ans, num;

	scanf("%d",&nt);
	for(int t=0;t<nt;t++){
		memset(chosen,0,sizeof(chosen));

		scanf("%d",&ans);
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++){
				scanf("%d",&num);
				if(i==ans-1){
					chosen[num]++;
				}
			}
		}

		scanf("%d",&ans);
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++){
				scanf("%d",&num);
				if(i==ans-1){
					chosen[num]++;
				}
			}
		}

		int numAnswer = 0;
		int chosenCard = -1;
		for(int i=1;i<=16;i++){
			if(chosen[i] == 2){
				numAnswer++;
				chosenCard = i;
			}
		}

		printf("Case #%d: ", t+1);
		if(numAnswer == 0){
			printf("Volunteer cheated!\n");
		}
		else if(numAnswer == 1){
			printf("%d\n", chosenCard);
		}
		else{
			printf("Bad magician!\n");
		}

	}

	return 0;
}