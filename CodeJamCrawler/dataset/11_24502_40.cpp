#include <iostream>
#include <string.h>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <iomanip>
#include <bitset>
#include <ctime>
#include <climits>
using namespace std;

int num[1000000];

bool judge(int a,int b)
{
	if(a%b==0 || b%a==0)
		return 1;
	else
		return 0;
}

int main()
{
	freopen("C-small-attempt0.in","r",stdin);
	freopen("C-small.out","w",stdout);
	int n,i;
	scanf("%d",&n);
	for(i=1; i<=n; i++)
	{
		printf("Case #%d:",i);
		int a,b,c,j,k,flag=0;
		scanf("%d %d %d",&a,&b,&c);
		for(j=0; j<a; j++)
			scanf("%d",&num[j]);
		for(j=b; j<=c; j++)
		{
			flag=0;
			for(k=0; k<a; k++)
			{
				if(judge(j,num[k]))
				{
					flag++;
				}
			}
			if(flag==a) break;
		}
		if(flag==a) printf("%d\n",j);
		else printf("NO\n");
	}
	return 0;
}
