#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;
typedef long long LL;
#define MAX(a,b) a = max(a,b)
#define MIN(a,b) a = min(a,b)
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pi acos(-1)
#define INF 1000000000
bool ada[17],ada2[17];
int main()
{
	freopen("MAGIC.out","w",stdout);
	int t;
	scanf("%d", &t);
	for(int tc=1;tc<=t;tc++)
	{
		memset(ada,0,sizeof ada);
		memset(ada2,0,sizeof ada2);
		int pert;
		scanf("%d", &pert);
		for(int i=1;i<=4;i++)
		{
			if(i==pert)
			for(int j=0;j<4;j++)
			{
				int a;scanf("%d",&a);
				ada[a]=1;
			}
			else for(int j=0;j<4;j++) scanf("%*d");
		}
		int ked;
		scanf("%d", &ked);
		for(int i=1;i<=4;i++)
		{
			if(i==ked)
			for(int j=0;j<4;j++)
			{
				int a;scanf("%d",&a);
				ada2[a]=1;
			}
			else for(int j=0;j<4;j++) scanf("%*d");
		}
		int banyak = 0,angka=-1;
		for(int i=1;i<=16;i++)
		{
			if(ada[i] && ada2[i])
			{
				banyak++;angka=i;
			}
		}
		printf("Case #%d: ",tc);
		if(banyak==0) puts("Volunteer cheated!");
		else if(banyak==1) printf("%d\n", angka);
		else puts("Bad magician!");
	}
	return 0;
	
}
