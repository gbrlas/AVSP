#include<stdio.h>
#include<vector>
using namespace std;
vector<vector<int> > al;
int mark[10000];
int map[100][100];
int H,W;

void dfs(int n,int c){
int i;
mark[n]=c;
for(i=0;i<al[n].size();i++)
{
	if(mark[al[n][i]] == -1)
	dfs(al[n][i],c);
}
}

int main(){
	int N,t,i,j,k,dx,dy,min;
	scanf("%d",&N);
	for(t=1;t<=N;t++)
	{
		scanf("%d%d",&H,&W);
		for(i=0;i<H;i++)
		for(j=0;j<W;j++)
		scanf("%d",&map[i][j]);
		al.clear();
		al.resize(H*W);
		for(i=0;i<H;i++)
		for(j=0;j<W;j++)
		{
			min = 10001;
			if( (i>0) && (map[i-1][j]<min) )
			{
				min = map[i-1][j];
				dx=-1;
				dy=0;
			}
			if( (j>0) && (map[i][j-1]<min) )
			{
				min = map[i][j-1];
				dx=0;
				dy=-1;
			}
			if( (j<W-1) && (map[i][j+1]<min) )
			{
				min = map[i][j+1];
				dx=0;
				dy=1;
			}
			if( (i<H-1) && (map[i+1][j]<min) )
			{
				min = map[i+1][j];
				dx=1;
				dy=0;
			}
			if(min<map[i][j])
			{
				al[i*W+j].push_back((i+dx)*W+j+dy);
				al[(i+dx)*W+j+dy].push_back(i*W+j);
			}
		}
		k=0;
		for(i=0;i<H*W;i++)
		mark[i]=-1;
		for(i=0;i<H*W;i++)
		{
			if(mark[i]==-1)
			{
				dfs(i,k);
				k++;
			}
		}
		printf("Case #%d:\n",t);
		for(i=0;i<H;i++)
		{
			for(j=0;j<W;j++)
			printf("%c ",'a'+mark[i*W+j]);
			printf("\n");
		}		
	}
	return 0;
}
