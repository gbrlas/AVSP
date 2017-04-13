#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int dir[4][2]={{-1,0},{0,-1},{0,1},{1,0}};
int map[102][102];
int res[102][102];
int n,m,tot;
int find(int x,int y)
{
	if(res[x][y]) return res[x][y];
	int min = map[x][y];
	int tmp_x,tmp_y,res_x,res_y;
	for(int i=0;i<4;i++)
	{
		tmp_x = x+dir[i][0];
		tmp_y = y+dir[i][1];
		if(tmp_x>=0 && tmp_x<n && tmp_y>=0 && tmp_y<m){
			if(map[tmp_x][tmp_y]<min) min = map[tmp_x][tmp_y],res_x=tmp_x,res_y=tmp_y;
		}
	}
	if(min==map[x][y]){
		res[x][y]=tot++;
		return res[x][y];
	}
	res[x][y] = find(res_x,res_y);
}

void output(int res[][102])
{
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++)
			printf("%d ",res[i][j]);
		printf("\n");
	}
	printf("\n");
}
int main()
{
	int T,i,j,ca=1;
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&T);
	for(ca=1;ca<=T;ca++)
	{
		memset(res,0,sizeof(res));
		tot = 1;
		scanf("%d%d",&n,&m);
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
				scanf("%d",&map[i][j]);
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
			{
				if(res[i][j]==0){
					find(i,j);
				}
			}
			//output(res);
			printf("Case #%d:\n",ca);
			for(i=0;i<n;i++){
				for(j=0;j<m;j++)
					printf("%c%c",res[i][j]-1+'a',j==m-1?'\n':' ');
			}
	}
	return 0;
}