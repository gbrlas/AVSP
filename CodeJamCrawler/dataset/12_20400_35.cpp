#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
	const int maxPoints = 30;
	/*int surp[maxPoints+1];
	int notsurp[maxPoints+1];*/
	int ns[] = {0,1,1,1,2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,9,9,9,10,10,10};
	int s[] =  {0,1,2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,9,9,9,10,10,10,10,10};
	/*for(int i=0;i<=maxPoints;++i)
	{
		int min = i/3;
		int rem = i - 3*min;
		switch(rem)
		{
		case 0:
			notsurp[i] = min;
			surp[i] = min+1;
			break;
		case 1:
			notsurp[i] = min+1;
			surp[i] = min+1;
			break;
		case 2:
			notsurp[i] = min+1;
			surp[i] = min+2;
			break;
		}
	}
	cout<<'{';
	for(int i=0;i<maxPoints+1;++i)
	{
		cout<<notsurp[i]<<',';
	}
	cout<<'}'<<endl;
	cout<<'{';
	for(int i=0;i<maxPoints+1;++i)
	{
		cout<<surp[i]<<',';
	}
	cout<<'}'<<endl;*/
	
	freopen("B-large.in","r",stdin);
	freopen("b1.out","w",stdout);
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;++i)
	{
		int n,ss,p;
		int count = 0;
		scanf("%d %d %d",&n,&ss,&p);
		for(int j=0;j<n;++j)
		{
			int g;
			scanf("%d",&g);
			if(ns[g] >= p)
			{
				++count; continue;
			}
			if(ss>0 && s[g] >= p)
			{
				++count; --ss; continue;
			}
		}
		printf("Case #%d: %d\n",i+1,count);
	}
	return 0;
}