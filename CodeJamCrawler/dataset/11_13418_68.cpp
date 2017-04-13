#include<iostream>
#include<cstdio>
#include<string>
#include<sstream>
#include<iomanip>
#include<map>
#include<vector>
#include<queue>
#include<set>
#include<algorithm>
#include<memory.h>
#include<iomanip>
using namespace std;


int main()
{
	int test_count;
	cin>>test_count;
	for(int test_num=0;test_num<test_count;test_num++)
	{
		int N;
		scanf("%d",&N);

		vector<int> prost(N+1);
		vector<int> pr;
		for(int i=2;i<=N;i++)
			prost[i]=0;
		for(int i=2;i<=N;i++)
			if (prost[i]==0)
			{
				pr.push_back(i);
				for(int j=2*i;j<=N;j+=i)
					if (prost[j]==0)
					{
						prost[j]=pr.size();
					}			
			}
		int MinA = pr.size();
		int P = pr.size();
		vector<int> HOK(P);
		for(int i=2;i<=N;i++)
		{
			int x=i;
			for(int j=0;j<P;j++)
				if (x%pr[j]==0)
				{
					int a = 0;
					while(x%pr[j]==0)
					{
						a++;
						x/=pr[j];
					}
					if (a>HOK[j]) HOK[j]=a;
				}
		}
		int MaxA = 1;
		for(int i=0;i<P;i++)
			MaxA += HOK[i];
		if (N==1) MinA = MaxA = 1;
		printf("Case #%d: %d\n",test_num+1,MaxA-MinA);
	}
	return 0;
}