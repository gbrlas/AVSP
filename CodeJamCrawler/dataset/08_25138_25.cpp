#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;
#define MAXN 2000
bool np[MAXN]={1,1};
int p[3520]={2},tot=1;
void prime()
{ 
	int i,j;
    for(i=3;i<=MAXN;i+=2)
	{
		if(!np[i])
			p[tot++]=i;
		for(j=0;j<tot&&p[j]*i<=MAXN;j++)
		{
			np[p[j]*i]=1;
			if(i%p[j]==0)break;
		}
		
	}
}

int gcd(int a,int b)
{
	if(b==0)return a;
	return gcd(b,a%b);
}
int main()
{
	prime();
	int pk,k;
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B.out.txt","w",stdout);
	scanf("%d",&pk);
	for(k=1;k<=pk;k++)
	{
		int a,b,p;
		scanf("%d %d %d",&a,&b,&p);
		int n=b-a+1;
		int i;
		vector<vector<int> > v;
		int tot=n;
		for(i=a;i<=b;i++)
		{
			vector<int> nv;
			nv.push_back(i);
			v.push_back(nv);
		}
		bool flag=1;
		while(flag)
		{

			flag=0;
			int i,j,x,y;
			for(i=0;i<v.size();i++)
				for(j=i+1;j<v.size();j++)
					for(x=0;x<v[i].size();x++)
						for (y=0;y<v[j].size();y++)
						{
							int k=gcd(v[i][x],v[j][y]);
							int t;
							int max=-1;
							for(t=0;::p[t]<=k;t++)
								if(k%::p[t]==0)
								{
									if(::p[t]>max)max=::p[t];
									while(k%::p[t]==0)
										k/=::p[t];
								}
							if(max>=p)
							{
								tot--;
								vector<int> nv;
								nv.resize(v[i].size()+v[j].size());
								merge(v[i].begin(),v[i].end(),v[j].begin(),v[j].end(),nv.begin());
								v[i]=nv;
								v.erase(v.begin()+j);
								flag=1;
								goto next;
							}
						}
	next:
						;
		}
		printf("Case #%d: %d\n",k,tot);
	}
		
	return 0;
}