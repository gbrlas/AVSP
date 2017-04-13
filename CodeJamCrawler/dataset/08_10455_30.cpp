#include <iostream>
#include <queue>

using namespace std;

#define start first.first
#define type first.second 
#define end second

int main()
{
//	freopen("inB.in","rt",stdin);
//	freopen("outB.out","wt",stdout);
	int TC,tc;
	int Time;
	int i;
	char c;
	int N,M,h,m,h2,m2;
	priority_queue< pair< pair<int,char> ,int > ,vector< pair< pair<int,char> ,int > > ,greater< pair< pair<int,char> ,int > > > Train;
	priority_queue< int , vector<int> , greater<int> > Aq,Bq;
	int Aans,Bans;
	cin>>TC;

	for(tc=1;tc<=TC;tc++)
	{
		cin>>Time;
		cin>>N>>M;
		for(i=0;i<N;i++)
		{
			cin>>h>>c>>m;
			cin>>h2>>c>>m2;
			Train.push(make_pair( make_pair(h*60+m,'A') , h2*60+m2) );
			if( h*60+m == h2*60+m2) cout<<"ooooooooooops\n";//must never happen
		}
		for(i=0;i<M;i++)
		{
			cin>>h>>c>>m;
			cin>>h2>>c>>m2;
			Train.push(make_pair( make_pair(h*60+m,'B') , h2*60+m2) );
			if( h*60+m == h2*60+m2) cout<<"ooooooooooops\n";//must never happen
		}
		Aans = Bans = 0;
		while(!Aq.empty()) Aq.pop();
		while(!Bq.empty()) Bq.pop();
		while(!Train.empty())
		{
			if( Train.top().type == 'A')
			{
				if(Aq.empty() || Aq.top() > Train.top().start ) Aans++;
				else Aq.pop();
				Bq.push( Train.top().end+Time );
			}
			else
			{
				if(Bq.empty() || Bq.top() > Train.top().start ) Bans++;
				else Bq.pop();
				Aq.push( Train.top().end+Time );
			}
			Train.pop();
		}
		cout<<"Case #"<<tc<<": "<<Aans<<" "<<Bans<<endl;
	}
	return 0;
}
