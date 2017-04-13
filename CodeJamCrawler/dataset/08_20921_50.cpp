#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <map>
using namespace std;
#define MAX 110

int t,T;
map < string,int > name;
bool have[MAX];
char str[110];

int main()
{
	freopen("a-small-attempt0.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&T);
	int i,j;
	for (t=1;t<=T;t++)
	{
		name.clear();
		memset(have,0,sizeof(have));
		int n,m,res=0;
		scanf("%d",&n);gets(str);
		for (i=0;i<n;i++)
		{
			gets(str);
			name[str]=i;
		}
		scanf("%d",&m);gets(str);
		for (i=0;i<m;i++)
		{
			gets(str);
			int num=name[str];
			have[num]=true;
			bool ok=true;
			for (j=0;j<n;j++)
				if (!have[j]) ok=false;
			if (ok)
			{
				res++;
				memset(have,0,sizeof(have));
				have[num]=true;
			}
		}
		printf("Case #%d: %d\n",t,res);
	}
	
	return 0;
}