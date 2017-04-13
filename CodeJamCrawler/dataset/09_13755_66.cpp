#include <iostream>
#include <vector>
#include <map>
using namespace std;
vector<vector<int> > Result;
vector<vector<int> > TwoDimens;
int H,W;
void buildmatrix(int courrent,int x,int y)
{
	int mn = courrent,fixx = -1,fixy = -1;
	if(TwoDimens[x-1][y] < mn)
	{
		mn = TwoDimens[x-1][y];//north
		fixx = x - 1;
		fixy = y;
	}
	if(TwoDimens[x][y-1] < mn){
		mn = TwoDimens[x][y-1];//west
		fixx = x;
		fixy = y - 1;
	}
	if(TwoDimens[x][y+1] < mn){
		mn = TwoDimens[x][y+1];//East
		fixx = x;
		fixy = y + 1;
	}
	if(TwoDimens[x+1][y] < mn){
		mn = TwoDimens[x+1][y];//south
		fixx = x + 1;
		fixy = y;
	}
	if(fixx != -1 && fixy != -1)
	{
		
		buildmatrix(TwoDimens[fixx][fixy],fixx,fixy);
		Result[x][y] = Result[fixx][fixy];
	}
}
int main()
{
	freopen("B-small-attempt1.in","r",stdin);
	freopen("B-small-attempt1.out","w",stdout);
	int T;
	cin >> T;
	for(int i = 0; i < T; ++i)
	{
		printf("Case #%d:\n",i+1);
		
		cin >> H >> W;
		TwoDimens.assign(H+2,vector<int>(W+2,10001));
	    Result.assign(H+2,vector<int>(W+2,0));		
		int ter = 0;
		for(int j = 1; j <= H; ++j)
			for(int k = 1; k <= W; ++k)
			{
				scanf("%d",&TwoDimens[j][k]);//инициализация
				Result[j][k] = ter;
				ter++;
			}

		for(int j = 1; j <= H; ++j)
			for(int k = 1; k <= W; ++k)
				buildmatrix(TwoDimens[j][k],j,k);

		map<int,char> Map;
		char begin = 'a';
		for(int j = 1; j <= H; ++j)
		{
			for(int k = 1; k <= W; ++k)
			{
				if(Map.find(Result[j][k])== Map.end())
				{	
					printf("%c",begin);
					Map[Result[j][k]] = begin;
					begin++;
				}
				else{
					printf("%c",Map[Result[j][k]]);
				}
				if(k<W) printf(" ");
			}
			printf("\n");
		}
		Map.clear();
	}
}