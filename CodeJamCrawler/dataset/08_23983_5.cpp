#include <stdio.h>
#include <string.h>
#include<vector>
#include<queue>
using namespace std;
int main()
{
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	int N,S,F,rez;
	char engines[100][101];
	char search[110];
	char c;
	int searches[1000];
	vector<vector<int>> sear;
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		rez=0;
		scanf("%d",&S);
		int j;
		for(j=0;j<S;j++)
		{
			scanf("%c",&c);
			scanf("%[^\n]",&engines[j]);
			
		}
		sear.clear();
		sear.resize(S);
		for(j=0;j<S;j++)
			sear[j].clear();
		scanf("%d",&F);
		int k;
		for(k=0;k<F;k++)
		{
			scanf("%c",&c);
			scanf("%[^\n]",&search);
			for(int m=0;m<S;m++)
				if(strcmp(search,engines[m])==0) {/*searches[k]=m;*/sear[m].push_back(k);break;}
		}
		//main part
		bool ok=false;
		
		
		while(!ok)
		{
			for(j=0;j<S;j++)
			if(sear[j].size()==0) {ok=true;break;}
			if(ok)break;
			int max=0;
			int maxj=0;
			for(j=0;j<S;j++)
			{
				if(max<sear[j][0]) {max=sear[j][0];maxj=j;}
			}
			for(j=0;j<S;j++)
			{
				if(sear[j].size()!=0&&max>sear[j][0]) {sear[j].erase(sear[j].begin());j--;}
			}
			if(max!=F) rez++;
			else ok=true;
		}
		printf("Case #%d: %d",i+1,rez);
		if(i<N-1) printf("\n");
	}

	return 0;
}