#include <cstdio>
#include <memory.h>
#include <vector>
#include <map>

using namespace std;

int main()
{
	freopen("C-small.in","r",stdin);
	freopen("out.txt","w",stdout);
	int T;
	scanf("%d",&T);
	for(int z=1;z<=T;z++)
	{
		int R,K,N;
		scanf("%d%d%d",&R,&K,&N);
		vector<int> Groups;
		map<int,pair<int,int>> m1;		//key - starting position, int1 - num in cycle, int2 - money
		for(int i=0;i<N;i++)
		{
			int temp;
			scanf("%d",&temp);
			Groups.push_back(temp);
		}
		//Simulate for cycle
		int pos = 0;
		int Cycle = 1;
		while(1)
		{
			if(m1.count(pos)!=0)
				break;
			int temppos = pos;
			long long money = 0;
			int kst = 0;
			while(true)
			{
				if(money+Groups[pos]<=K)
					money+=Groups[pos];
				else
					break;
				kst++;
				pos++;
				pos%=N;
				if(kst==N)
					break;
			}
			pair<int,long long> temp;
			temp.first = Cycle;
			temp.second = money;
			m1.insert(pair<int,pair<int,long long>>(temppos,temp));
			Cycle++;
		}

		int SizeOfCycle = Cycle - (*m1.find(pos)).second.first;
		int BeforeCycle = Cycle - SizeOfCycle - 1;
		long long SumInCycle = 0;
		long long SumBeforeCycle = 0;

		for(int i=0;i<N;i++)
			if(m1.count(i)!=0)
			{
				if(((*m1.find(i)).second.first<Cycle-SizeOfCycle)&&((*m1.find(i)).second.first<R))
					SumBeforeCycle+=(*m1.find(i)).second.second;
				else 
					SumInCycle+=(*m1.find(i)).second.second;
			}
		R-=BeforeCycle;
		int QuantityOfCycles = R/SizeOfCycle;
		R-=QuantityOfCycles*SizeOfCycle;
		long long SumAfterCycle = 0;
		for(int i=0;i<N;i++)
			if(m1.count(i)!=0)
			{
				if(((*m1.find(i)).second.first>=Cycle-SizeOfCycle)&&((*m1.find(i)).second.first-BeforeCycle<=R))
					SumAfterCycle+=(*m1.find(i)).second.second;
			}	
		long long Res = SumBeforeCycle+(long long)QuantityOfCycles*SumInCycle + SumAfterCycle;
		printf("Case #%d: %lld\n",z,Res);

	}
	return 0;
}