#include <cstdio>
#include <iostream>
#include <stack>
#include <queue>
#include <map>
#include <cmath>
#include <string>
#include <memory>
#include <vector>
#include <set>
#include <deque>
#include <list>
#include <algorithm>

using namespace std;

const int Max = 30;

int Matr[Max][Max];

int pr[Max];

void factor1(int N)
{
	int p = 2;
	while(p*p<=N)
	{
		if(N%p==0)
		{
			pr[p]++;
			N/=p;
		}
		else
			p++;
	}
	if(N!=1)
		pr[N]++;
}
void factor2(int N)
{
	int p = 2;
	while(p*p<=N)
	{
		if(N%p==0)
		{
			pr[p]--;
			N/=p;
		}
		else
			p++;
	}
	if(N!=1)
		pr[N]--;
}

int Comb(int N, int M)
{
	memset(pr,0,sizeof(pr));
	if(N>M)
		return 0;
	int res = 1;

	for(int i=2;i<=M;i++)
	{
		factor1(i);
	}
	for(int i=2;i<=N;i++)
	{
		factor2(i);
	}
	for(int i=2;i<=M-N;i++)
	{
		factor2(i);
	}
	
	for(int i=2;i<Max;i++)
		while(pr[i]!=0)
		{
			res*=i;
			res%=100003;
			pr[i]--;
		}
	
	return res;
}

int main()
{
	freopen("C-small.in","r",stdin);
	freopen("result.txt","w",stdout);
	int T;
	scanf("%d",&T);

	for(int i=2;i<Max;i++)
		Matr[i][1] = 1; 
	for(int i=3;i<Max;i++)
	{
		for(int j=2;j<i;j++)
		{
			int sum = 0;
			for(int k=1;k<j;k++)
			{
				sum += (int)(((long long)Matr[j][k]*(long long)Comb(j-k-1,i-j-1))%(long long)100003);
				sum%=100003;
			}
			Matr[i][j] = sum;
		}
	}

	for(int z=0;z<T;z++)
	{
		int N;
		scanf("%d",&N);
		int res = 0;
		for(int i=0;i<=N;i++)
		{
			res+=Matr[N][i];
			res%=100003;
		}
		printf("Case #%d: %d\n",z+1,res);
	}
	return 0;
}