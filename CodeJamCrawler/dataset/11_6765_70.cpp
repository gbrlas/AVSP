#include <iostream>
#include <queue>
#include <map>
using namespace std;
void solve(int testnum)
{
	int n;
	cin>>n;
	queue<pair<int,int> > q1,q2;
	for(int i=0;i<n;i++)
	{
		char c;
		cin>>c;
		int k;
		cin>>k;
		k--;
		if(c=='O')q1.push(make_pair(i,k));
		if(c=='B')q2.push(make_pair(i,k));
	}
	int cnt=0,pos1=0,pos2=0,t=0;
	while(!(q1.empty() && q2.empty()))
	{
		int ocnt=cnt;
		if(!q1.empty())
		{
			int q1p=q1.front().second;
			if(q1p==pos1)
				if(q1.front().first==ocnt){q1.pop();cnt++;}
			if(q1p<pos1)
				pos1--;
			if(q1p>pos1)
				pos1++;
		}
		if(!q2.empty())
		{
			int q2p=q2.front().second;
			if(q2p==pos2)
				if(q2.front().first==ocnt){q2.pop();cnt++;}
			if(q2p<pos2)
				pos2--;
			if(q2p>pos2)
				pos2++;
		}
		t++;
	}
	cout<<"Case #"<<testnum<<": "<<t<<'\n';
}
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		solve(i+1);
	return 0;
}
