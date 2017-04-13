#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<deque>
using namespace std;
#define CLR(arr,val) memset(arr,val,sizeof(arr))
int Pos[2];
deque<int> cmd[2];
deque<int> Who;
inline int mabs(int num)
{
	return num>=0?num:-num;
}
int Run(int num)
{
	int w=Who[num],target[2]={cmd[0].front(),cmd[1].front()};
	cmd[w].pop_front();
	int mv=mabs(target[w]-Pos[w])+1,mv2=mabs(target[!w]-Pos[!w]);
	if(mv>mv2) Pos[!w]=target[!w];
	else Pos[!w]=target[!w]-(mv2-mv);
	Pos[w]=target[w];
	return mv;
}
int main()
{
	freopen("A-large.in","r",stdin);
	freopen("out.txt","w",stdout);
	int t,n,c;
	char who;
	scanf("%d",&t);
	for(int i=0;i!=t;i++)
	{
		Who.clear();
		cmd[0].clear();cmd[1].clear();
		scanf("%d",&n);
		for(int j=0;j!=n;j++)
		{
			cin>>who>>c;
			if(who=='B') cmd[0].push_back(c);
			else cmd[1].push_back(c);
			Who.push_back(who=='O');
		}
		cmd[0].push_back(1000000);cmd[1].push_back(1000000);
		Pos[0]=Pos[1]=1;
		int sum=0;
		for(int j=0;j!=n;j++)
			sum+=Run(j);
		printf("Case #%d: %d\n",i+1,sum);
	}
}