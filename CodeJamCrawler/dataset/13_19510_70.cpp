#include<stdio.h>

int main(){
	int nt;
	char ttt[10][10];
	
	scanf("%d",&nt);
	for(int t=0; t<nt; t++){
		for(int i=0;i<4;i++){
			scanf("%s",ttt[i]);
		}	
		bool isFull = true;
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++){
				if(ttt[i][j]=='.'){
					isFull = false;
					break;	
				}	
			}	
			if(!isFull) break;
		}
		
		/*for(int i=0;i<4;i++){
			for(int j=0;j<4;j++){
				printf("%c",ttt[i][j]);	
			}	
			printf("\n");
		}*/
		
		int winner = 0;
		
		// horizontal
		for(int i=0;i<4;i++){
			int countX = 0;
			int countO = 0;
			for(int j=0;j<4;j++){
				if(ttt[i][j]=='X' || ttt[i][j]=='T'){
					countX++;	
				}
				if(ttt[i][j]=='O' || ttt[i][j]=='T'){
					countO++;	
				}
			}	
			if(countX==4){
				winner = 1;	
			}
			else if(countO==4){
				winner = 2;	
			}
		}

		// vertical
		for(int i=0;i<4;i++){
			int countX = 0;
			int countO = 0;
			for(int j=0;j<4;j++){
				if(ttt[j][i]=='X' || ttt[j][i]=='T'){
					countX++;	
				}
				if(ttt[j][i]=='O' || ttt[j][i]=='T'){
					countO++;	
				}
			}	
			if(countX==4){
				winner = 1;	
			}
			else if(countO==4){
				winner = 2;	
			}
		}
		
		// diagonal 1
		{
			int countX = 0;
			int countO = 0;		
			for(int i=0;i<4;i++){
				if(ttt[i][i]=='X' || ttt[i][i]=='T'){
					countX++;	
				}
				if(ttt[i][i]=='O' || ttt[i][i]=='T'){
					countO++;	
				}
			}
			if(countX==4){
				winner = 1;	
			}
			else if(countO==4){
				winner = 2;	
			}
		}
		
		// diagonal 2
		{
			int countX = 0;
			int countO = 0;		
			for(int i=0;i<4;i++){
				if(ttt[i][3-i]=='X' || ttt[i][3-i]=='T'){
					countX++;	
				}
				if(ttt[i][3-i]=='O' || ttt[i][3-i]=='T'){
					countO++;	
				}
			}
			if(countX==4){
				winner = 1;	
			}
			else if(countO==4){
				winner = 2;	
			}
		}
		
		
		printf("Case #%d: ",t+1);
		if(winner==0){
			if(isFull){
				printf("Draw\n");
			}	
			else{
				printf("Game has not completed\n");	
			}
		}
		else{
			if(winner==1){
				printf("X won\n");
			}	
			else{
				printf("O won\n");	
			}
		}
	}
	return 0;	
}