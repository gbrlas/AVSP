#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

#define PB push_back
#define MP make_pair

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,l,h) for(int i=(l);i<=(h);++i)
#define FORD(i,h,l) for(int i=(h);i>=(l);--i)

//#define coutpoint5 setiosflags(ios::fixed)<<setprecision(5)

#define maxN 1000
#define maxM 1000
//#define MM 1000000007

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;

const int weiyi[4][2]={{-1,0},{1,0},{0,-1},{0,1}};

bool a[maxN][maxM];

#define maxn 100100
#define maxm 401000
#define oo 100000000

struct node
{
	int v,c;
	node *opp,*next;
}mapp[maxm];

node *list[maxn];
int d[maxn],vd[maxn];
int e,n;

void addedge(int i,int j)
{
	int c=1;
	
	mapp[++e].v=j;
	mapp[e].c=c;
    mapp[e].opp=&mapp[e+1];
    mapp[e].next=list[i];
    list[i]=&mapp[e];
  
    mapp[++e].v=i;
    mapp[e].c=0;
    mapp[e].opp=&mapp[e-1];
    mapp[e].next=list[j];
    list[j]=&mapp[e];
}

int dfs(int i,int flow)
{
	int j,temp,ff=0;
	node *u;
    if (i==n) return(flow);
	u=list[i];
    while (u!=NULL)
	{
		j=u->v;
		if (u->c>0 && d[i]==d[j]+1)
		{
			temp=dfs(j,min(u->c,flow-ff));
			u->c = u->c-temp;
			u->opp->c = u->opp->c+temp;
			ff+=temp;
			if (ff==flow) return(flow);
		}
		u=u->next;
	}
    if (d[1]>=n) return(ff);
    vd[d[i]]--;
    if (vd[d[i]]==0) d[1]=n;
    d[i]++;
    vd[d[i]]++;
	return (ff);
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	//ios_base::sync_with_stdio(false);
	
	int T;
	scanf("%d",&T);
	FOR(TT,1,T)
	{
		printf("Case #%d: ",TT);
		e=0;
		for (int i=0;i<maxn;i++)
			list[i]=NULL;
		memset(a,0,sizeof(a));
		int N,M,K;
		scanf("%d%d%d",&N,&M,&K);
		FOR(i,1,K)
		{
			int l1,r1,l2,r2;
			scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
			l1++,r1++,l2++,r2++;
			FOR(i1,l1,l2)
				FOR(j1,r1,r2)
					a[i1][j1]=true;
		}
		FOR(i,1,N)
			FOR(j,1,M)
			{
				if (a[i][j]) continue;
				addedge(((i-1)*M+j)*2-1+1,((i-1)*M+j)*2+1);
				REP(k,4)
				{
					int i1=i+weiyi[k][0],j1=j+weiyi[k][1];
					if (i1>=1 && i1<=N && j1>=1 && j1<=M && !a[i1][j1])
						addedge(((i-1)*M+j)*2+1,((i1-1)*M+j1)*2-1+1);
				}
			}
		FOR(i,1,N)
		{
			if (!a[i][1])
			{
				addedge(1,((i-1)*M+1)*2-1+1);
			}
			if (!a[i][M])
			{
				addedge(((i-1)*M+M)*2+1,N*M*2+2);
			}
		}
		n=N*M*2+2;
		memset(d,0,sizeof(d));
		memset(vd,0,sizeof(vd));
		vd[0]=n;
		int maxflow=0;
		while (d[1]<=n-1)
			maxflow=maxflow+dfs(1,oo);
		printf("%d\n",maxflow);
	}
	
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
