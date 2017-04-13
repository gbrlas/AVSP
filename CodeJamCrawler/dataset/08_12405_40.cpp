#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int>v1[1100], v2[1100];

int w[11],m,n;

bool cal(int p)
{
	int i,j,k ,temp;

	for(i = 0; i < m; i ++){

		if(v1[i].size() == 0) continue;
		for(k = 0; k < n; k ++){
			
			temp = p&w[k];
		
			if(temp) temp=1;
			else temp	=	0;

			for(j = 0; j < v1[i].size(); j ++)
				if(v1[i][j] == k && v2[i][j] == temp)	break;
		
			if(j<v1[i].size())break;
		}

		if(k==n)return 0;
	}

	return 1;
}

int main()
{
	int T, t, i, j, Mm , x, y;

	w[0]=1;
	for(i=1;i<=10;i++)	w[i]=w[i-1]*2;

	scanf("%d",&T);

	for(t = 1; t <= T; t ++)
	{
		printf("Case #%d: ",t);


		for(i =0; i < 1100; i ++)	v1[i].clear();
		for(i =0; i < 1100; i ++)	v2[i].clear();

		scanf("%d%d",&n,&m);

		for(i=0;i<m;i++){

			Mm=0;
			scanf("%d", &Mm);
			for(j = 0; j < Mm; j ++ )
			{
				scanf("%d%d",&x,&y);
				x--;
				v1[i].push_back(x);
				v2[i].push_back(y);
			}
		}


		int Num = (1<<n);

		for(i = 0; i < Num; i ++ )		if(	cal(i))	break;

		if(i<Num)
		{
			for(j=0;j<n;j++)
			{
				if(j)	printf(" ");
				printf("%d",(i&w[j]) > 0 ? 1:0);
			}
			printf("\n");
		}
		else printf("IMPOSSIBLE\n");
	}
	return 0;
}
