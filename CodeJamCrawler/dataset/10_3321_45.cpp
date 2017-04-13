#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include<string>


using namespace std;
#define pi acos(-1.0)
typedef struct node
{
	int x,y;
}NODE;
NODE T[1003];
int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("1.out","w",stdout);
	int cas;
	int cass=1;

	scanf("%d",&cas);
	while(cas--)
	{
		int n,sum=0;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			cin >> T[i].x>>T[i].y;
		}
		for(int i=0;i<n;i++)
			for(int j=i;j<n-1;j++)
				if(T[j].x>T[j+1].x)
		{
			NODE temp;
			temp=T[j];
			T[j]=T[j+1];
			T[j+1]=temp;
		}
				for(int i=0;i<n;i++)
			for(int j=i;j<n-1;j++)
				if(T[j].y>T[j+1].y)
		{
			NODE temp;
			temp=T[j];
			T[j]=T[j+1];
			T[j+1]=temp;
			sum++;

		}
		printf("Case #%d: %d\n",cass++,sum);
	}
}
