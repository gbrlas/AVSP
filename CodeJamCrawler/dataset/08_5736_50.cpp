#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

int a[2][101],d[2][101];

struct tr{
	int ini,cur,time;
	tr(int ini,int cur,int time):ini(ini),cur(cur),time(time){}
};

struct trip{
	int ind,time,sta;
	trip(int ind,int time,int sta):ind(ind),time(time),sta(sta){}
	bool operator<(const trip t)	const{
		if(time!=t.time) return time<t.time;
		if(sta!=t.sta) return sta<t.sta;
		return ind<t.ind;
	}
};

int main()	{

	freopen("B-large0.in","r",stdin);
	freopen("my.out","w",stdout);

	int n,i,j,t,na,nb,h,m,nc;
	char c;

	cin>>n;

	for(nc=1;nc<=n;nc++)	{
		
		cin>>t>>na>>nb;

		vector<trip> s;
		vector<tr> v;

		for(i=0;i<na;i++)	{
			cin>>h>>c>>m;
			d[0][i]=h*60+m;
			cin>>h>>c>>m;
			a[0][i]=h*60+m;
			s.push_back(trip(i,d[0][i],0));
		}

		for(i=0;i<nb;i++)	{
			cin>>h>>c>>m;
			d[1][i]=h*60+m;
			cin>>h>>c>>m;
			a[1][i]=h*60+m;
			s.push_back(trip(i,d[1][i],1));
		}

		sort(s.begin(),s.end());

		int sz=s.size();

		for(i=0;i<sz;i++)	{
			trip temp = s[i];
			for(j=0;j<v.size();j++)	{
				if(!(v[j].cur == temp.sta && v[j].time+t <= temp.time)) continue;
				v[j].cur = (temp.sta+1)%2;
				v[j].time = a[temp.sta][temp.ind];
				break;
			}
			if(j!=v.size()) continue;
			v.push_back(tr(temp.sta,(temp.sta+1)%2,a[temp.sta][temp.ind]));
		}

		int tb=0,ta=0;

		for(i=0;i<v.size();i++)
			if(v[i].ini) tb++;
			else ta++;

		cout<<"Case #"<<nc<<": "<<ta<<" "<<tb<<endl;
	}

	return 0;
}