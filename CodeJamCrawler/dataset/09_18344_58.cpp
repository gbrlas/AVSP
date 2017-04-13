#include<stdio.h>
#include<queue>
#include<set>
using namespace std;
int r,c,f;
struct zt
{
	long long a[50];
	int x,y,d;
	bool operator<(const zt &z)const
	{
		if(d!=z.d)return d>z.d;
		if(x!=z.x)return x>z.x;
		if(y!=z.y)return y>z.y;
		for(int i=0;i<r;i++)if(a[i]!=z.a[i])return a[i]>z.a[i];
		return false;
	}
	zt()
	{
		memset(this,0,sizeof(zt));
	}
	void pnt()const
	{
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)printf("%lld",(a[i]>>j)&1ll);
			putchar('\n');
		}
		printf("%d %d %d\n",x,y,d);
	}
};
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int n;
	scanf("%d",&n);
	for(int nn=1;nn<=n;nn++)
	{
		scanf("%d%d%d",&r,&c,&f);
		zt st;
		for(int i=0;i<r;i++)
		{
			char s[51];
			scanf("%s",s);
			for(int j=0;j<c;j++)if(s[j]=='#')st.a[i]|=(1ll<<j);
		}
		priority_queue<zt> q;
		set<zt> s;
		q.push(st);
		s.insert(st);
		while((!q.empty())&&q.top().x<r-1)
		{
			st=q.top();
			q.pop();
			//st.pnt();
			if(st.y+1<c)
			{
				zt now=st;
				now.y++;
				if(now.a[now.x]&(1ll<<now.y));
				else
				{
					if(now.a[now.x+1]&(1ll<<now.y))
					{
						if(s.find(now)==s.end())q.push(now),s.insert(now);
					}
					else
					{
						int x=now.x;
						while(now.x<r-1&&!(now.a[now.x+1]&(1ll<<now.y)))now.x++;
						if(now.x-x<=f)
						{
							if(s.find(now)==s.end())q.push(now),s.insert(now);
						}
					}
				}
			}
			if(st.y>0)
			{
				zt now=st;
				now.y--;
				if(now.a[now.x]&(1ll<<now.y));
				else
				{
					if(now.a[now.x+1]&(1ll<<now.y))
					{
						if(s.find(now)==s.end())q.push(now),s.insert(now);
					}
					else
					{
						int x=now.x;
						while(now.x<r-1&&!(now.a[now.x+1]&(1ll<<now.y)))now.x++;
						if(now.x-x<=f)
						{
							if(s.find(now)==s.end())q.push(now),s.insert(now);
						}
					}
				}
			}
			zt now=st;
			now.d++;
			if(now.y+1<c&&(now.a[now.x+1]&(1ll<<(now.y+1)))&&!(now.a[now.x]&(1ll<<(now.y+1))))
			{
				now.a[now.x+1]^=(1ll<<(now.y+1));
				if(s.find(now)==s.end())q.push(now),s.insert(now);
				now.a[now.x+1]^=(1ll<<(now.y+1));
			}
			if(now.y-1>=0&&(now.a[now.x+1]&(1ll<<(now.y-1)))&&!(now.a[now.x]&(1ll<<(now.y-1))))
			{
				now.a[now.x+1]^=(1ll<<(now.y-1));
				if(s.find(now)==s.end())q.push(now),s.insert(now);
				now.a[now.x+1]^=(1ll<<(now.y-1));
			}
		}
		//q.top().pnt();
		if(q.empty())printf("Case #%d: No\n",nn);
		else printf("Case #%d: Yes %d\n",nn,q.top().d);
	}
}
