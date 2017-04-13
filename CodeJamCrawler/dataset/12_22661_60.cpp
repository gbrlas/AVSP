#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	freopen("Blarge.in","r",stdin);
	freopen("Blarge.out","w",stdout);
	int T,N,S,startS,p,ans=0;
	vector<int> googlers;
	scanf("%d\n",&T);
	for(int i=1;i<=T;i++)
	{
		ans=0;
		scanf("%d %d %d",&N,&S,&p);
		startS=S;
		googlers.resize(0);
		googlers.resize(N);
		for(int i=0;i!=N;i++)
			scanf(" %d",&googlers[i]);
		if(p==0)
		{
			printf("Case #%d: %d\n",i,N);
			continue;
		}
		sort(googlers.begin(),googlers.end(),greater<int>());
		for(int i=0;i!=N;i++)
		{
			if(startS!=0&&S==0||googlers[i]==0)
				break;
			if(googlers[i]%3==0)
			{
				if(googlers[i]/3>=p)
					ans++;
				else if(googlers[i]/3==p-1&&S>0)
				{
					ans++;
					S--;
				}
			}
			else if(googlers[i]%3==1&&(googlers[i]+2)/3>=p)
					ans++;
			else
			{
				if((googlers[i]+1)/3>=p)
					ans++;
				else if((googlers[i]+1)/3==p-1&&S>0)
				{
					ans++;
					S--;
				}
			}
		}
		printf("Case #%d: %d\n",i,ans);
	}
	return 0;
}