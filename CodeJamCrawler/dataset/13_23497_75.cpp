#include<stdio.h>
char a[10][10];
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int tc,tcn;
	int i,j;
	scanf("%d",&tc);
	for(tcn=1;tcn<=tc;tcn++){
		printf("Case #%d: ",tcn);
		for(i=0;i<4;i++){
			scanf("%s",a[i]);
			if(a[i][0]!='O'&&a[i][0]!='X'&&a[i][0]!='T'&&a[i][0]!='.'){
				i--;
			}
		}
		for(i=0;i<4;i++){
			for(j=0;j<4;j++){
				if(a[i][j]!='O'&&a[i][j]!='T')break;
			}
			if(j==4){
				printf("O won\n");
				goto end;
			}
		}
		for(i=0;i<4;i++){
			for(j=0;j<4;j++){
				if(a[j][i]!='O'&&a[j][i]!='T')break;
			}
			if(j==4){
				printf("O won\n");
				goto end;
			}
		}
		for(i=0;i<4;i++){
			if(a[i][i]!='O'&&a[i][i]!='T')break;
		}
		if(i==4){
			printf("O won\n");
			goto end;
		}
		for(i=0;i<4;i++){
			if(a[3-i][i]!='O'&&a[3-i][i]!='T')break;
		}
		if(i==4){
			printf("O won\n");
			goto end;
		}
		for(i=0;i<4;i++){
			for(j=0;j<4;j++){
				if(a[i][j]!='X'&&a[i][j]!='T')break;
			}
			if(j==4){
				printf("X won\n");
				goto end;
			}
		}
		for(i=0;i<4;i++){
			for(j=0;j<4;j++){
				if(a[j][i]!='X'&&a[j][i]!='T')break;
			}
			if(j==4){
				printf("X won\n");
				goto end;
			}
		}
		for(i=0;i<4;i++){
			if(a[i][i]!='X'&&a[i][i]!='T')break;
		}
		if(i==4){
			printf("X won\n");
			goto end;
		}
		for(i=0;i<4;i++){
			if(a[3-i][i]!='X'&&a[3-i][i]!='T')break;
		}
		if(i==4){
			printf("X won\n");
			goto end;
		}
		for(i=0;i<4;i++){
			for(j=0;j<4;j++){
				if(a[i][j]=='.'){
					printf("Game has not completed\n");
					goto end;
				}
			}
		}
		printf("Draw\n");
end:
		continue;
	}
}