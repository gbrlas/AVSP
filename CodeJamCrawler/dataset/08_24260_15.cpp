#include <stdio.h>
#include <algorithm>
using namespace std;

int l[1001];

int cmp(const void *a,const void *b)
{ 
	int a1 = *(int *)a; 
	int a2 = *(int *)b; 
	return a2 - a1; 
} 

int main()
{
	int numCase;
	int i;
	int typecase;  //每个键字母
	int casei;     //按键数目
	int alldata;
	int j;
	int t;
	int count = 0;
	__int64 sum= 0;
	int time;
	freopen("A-small-attempt0.in","r",stdin);
	freopen("c.out","w",stdout);
	scanf("%d",&numCase);

	for(i= 0; i < numCase; ++i)
	{
		scanf("%d",&typecase);
		scanf("%d",&casei);
		scanf("%d",&alldata);
		memset(l,0,sizeof(l));
		for(j=1; j<=alldata;++j)
		{
			scanf("%d",&l[j]);
		}
		qsort(l+1,alldata,sizeof(int),cmp);

		sum = 0;
		t = casei;
		time = 1;
		for(j = 1;j <= alldata;j++)
		{
				sum += l[j] * time;
				t--;
				if(t == 0)
				{
					t = casei;
					time++;
				}
		}
		printf("Case #%d: %I64d\n",i+1,sum);
	}

	return 0; 
}