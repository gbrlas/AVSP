#include <stdio.h>
#include <string>
#include <map>
using namespace std;
map<string,int> index;
int ss[1010],ww[1010];
int s,w;
int matr[1010][110];
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int nt,t,cnt;
	scanf("%d",&nt);
	
	for (t=0;t<nt;t++)
	{
		char buf[1010];
		index.clear();
		memset(matr,0,sizeof(matr));
		scanf("%d",&s);
		gets(buf);
		cnt=0;
		for (int i=0;i<s;i++)
		{
			gets(buf);
			if (index.find(buf)==index.end())
				index[buf]=cnt++;
			ss[i]=index[buf];
		}

		scanf("%d",&w);
		gets(buf);
		cnt=0;
		for (int i=0;i<w;i++)
		{
			gets(buf);
			if (index.find(buf)==index.end())
				index[buf]=cnt++;
			ww[i]=index[buf];
		}

		for (int i=0;i<s;i++)
			if (ww[0]==ss[i])
				matr[0][i]=-1;
			else
				matr[0][i]=0;

		for (int k=1;k<w;k++)
		{
			for (int i=0;i<s;i++)
			{
				if (ww[k]==ss[i])
					matr[k][i]=-1;
				else
				{
					int min=101010;
					for (int j=0;j<s;j++)
					{
						int x = matr[k-1][j]+(j!=i);
						if (matr[k-1][j]!=-1 && x< min)
							min=x;
					}
					matr[k][i]=min;
				}			
			}
		}
		int min=101010;
		for (int i=0;i<s;i++)
			if (matr[w-1][i]!=-1 && matr[w-1][i]<min)
				min=matr[w-1][i];
		printf("Case #%d: %d\n",t+1,min);
	}
	return 0;
}