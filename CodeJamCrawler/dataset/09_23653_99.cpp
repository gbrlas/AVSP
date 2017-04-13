#include <stdio.h>

int gor[4]={-1 ,0 ,0 ,1};
int goc[4]={ 0,-1, 1 ,0};
char ans[110][110];
bool con[110][110][4];
char id;

void dfs(int r,int c){
	if(ans[r][c]=='\0'){
		int i;
		ans[r][c]=id;
		for(i=0;i<4;i++)
			if(con[r][c][i])
				dfs(r+gor[i],c+goc[i]);
	}
}

int main(){
	int ecase,ecount;
	int er,ec;
	int einfo[110][110];
	int i,j,k;
	scanf("%d",&ecase);
	for(ecount=1;ecount<=ecase;ecount++){
		scanf("%d%d",&er,&ec);
		for(i=0;i<er;i++)
			for(j=0;j<ec;j++)
				scanf("%d",&einfo[i][j]);
		for(i=0;i<er;i++)
			for(j=0;j<ec;j++)
				for(k=0;k<4;k++)
					con[i][j][k]=false;
		for(i=0;i<er;i++)
			for(j=0;j<ec;j++){
				int c=-1;
				int nl=einfo[i][j];
				for(k=0;k<4;k++){
					int tr=i+gor[k];
					int tc=j+goc[k];
					if(tr>=0 && tr<er && tc>=0 && tc<ec)
						if(einfo[tr][tc]<nl){
							nl=einfo[tr][tc];
							c=k;
						}
				}
				if(c!=-1){
					con[i][j][c]=true;
					con[ i+gor[c] ][ j+goc[c] ][3-c]=true;
				}
			}
		for(i=0;i<er;i++)
			for(j=0;j<ec;j++)
				ans[i][j]='\0';
		id='a';
		for(i=0;i<er;i++)
			for(j=0;j<ec;j++)
				if(ans[i][j]=='\0'){
					dfs(i,j);
					id++;
				}
		printf("Case #%d:\n",ecount);
		for(i=0;i<er;i++){
			for(j=0;j<ec;j++){
				if(j>0)
					printf(" ");
				printf("%c",ans[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}
