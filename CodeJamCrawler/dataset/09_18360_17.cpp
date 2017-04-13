#include<stdio.h>
#include<queue>
#include<algorithm>
#include<set>
using namespace std;
int r,c;
char z[14][14];
vector<pair<int,int> > goal;
int n;
struct qn
{
	vector<pair<int,int> > v;
	int st;
	bool operator<(const qn &a)const
	{
		return st>a.st;
	}
	qn(const int &r,const int &c)
	{
		st=0;
		memset(z,'#',sizeof(z));
		for(int i=1;i<=r;i++)scanf("%s",z[i]+1),z[i][c+1]='#';
		v.clear();
		for(int i=1;i<=r;i++)for(int j=1;j<=c;j++)
			switch(z[i][j])
			{
			case 'w':
				z[i][j]='x';
				v.push_back(make_pair(i,j));
				break;
			case 'o':
				z[i][j]='.';
				v.push_back(make_pair(i,j));
				break;
			}
		n=v.size();
		goal.clear();
		for(int i=1;i<=r;i++)for(int j=1;j<=c;j++)if(z[i][j]=='x')goal.push_back(make_pair(i,j));
	}
	bool stable()
	{
		static bool l[5][5];
		memset(l,0,sizeof(l));
		sort(v.begin(),v.end());
		for(int i=0;i<n;i++)
		{
			l[i][i]=true;
			for(int j=i+1;j<n;j++)
			{
				if(v[i].first==v[j].first&&(v[i].second-v[j].second==1||v[i].second-v[j].second==-1))l[i][j]=l[j][i]=true;
				if(v[i].second==v[j].second&&(v[i].first-v[j].first==1||v[i].first-v[j].first==-1))l[i][j]=l[j][i]=true;
			}
		}
		for(int k=0;k<n;k++)for(int i=0;i<n;i++)for(int j=0;j<n;j++)if(l[i][k]&&l[k][j])l[i][j]=true;
		for(int i=0;i<n;i++)for(int j=0;j<n;j++)if(!l[i][j])return false;
		return true;
	}
	vector<qn> next()const
	{
		vector<qn> re;
		for(int i=0;i<n;i++)
		{
			if(z[v[i].first-1][v[i].second]=='#'||z[v[i].first+1][v[i].second]=='#')continue;
			int j=0;
			for(;j<n;j++)
				if(v[j].second==v[i].second&&(v[j].first-v[i].first==1||v[j].first-v[i].first==-1))break;
			if(j<n)continue;
			qn x=*this;
			x.v[i].first--;
			x.st++;
			re.push_back(x);
			x=*this;
			x.v[i].first++;
			x.st++;
			re.push_back(x);
		}
		for(int i=0;i<n;i++)
		{
			if(z[v[i].first][v[i].second-1]=='#'||z[v[i].first][v[i].second+1]=='#')continue;
			int j=0;
			for(;j<n;j++)
				if(v[j].first==v[i].first&&(v[j].second-v[i].second==1||v[j].second-v[i].second==-1))break;
			if(j<n)continue;
			qn x=*this;
			x.v[i].second--;
			x.st++;
			re.push_back(x);
			x=*this;
			x.v[i].second++;
			x.st++;
			re.push_back(x);
		}
		return re;
	}
};
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int t;
	scanf("%d",&t);
	for(int tt=1;tt<=t;tt++)
	{
		scanf("%d%d",&r,&c);
		qn init(r,c);
		priority_queue<qn> q;
		q.push(init);
		set<vector<pair<int,int> > > s;
		s.insert(init.v);
		while(!q.empty())
		{
			//for(int i=0;i<n;i++)printf("%d,%d ",q.top().v[i].first,q.top().v[i].second);
			//printf("  %d\n",q.top().st);
			if(q.top().v==goal)break;
			vector<qn> next=q.top().next();
			q.pop();
			for(vector<qn>::iterator i=next.begin();i!=next.end();i++)
				if(i->stable())
				{
					if(s.find(i->v)==s.end())q.push(*i),s.insert(i->v);
				}
				else
				{
					vector<qn> nn=i->next();
					for(vector<qn>::iterator j=nn.begin();j!=nn.end();j++)
					{
						if(j->stable()&&s.find(j->v)==s.end())q.push(*j),s.insert(j->v);
					}
				}
		}
		if(q.empty())printf("Case #%d: -1\n",tt);
		else printf("Case #%d: %d\n",tt,q.top().st);
	}
}
