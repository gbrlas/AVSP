#include <iostream>

using namespace std;

struct edge
{
	int v;
	edge *next;
	edge(int v,edge *next):v(v),next(next) {}
} *e[222];
bool used[222];
int q,match[222],data[111][111];

bool find(int v)
{
	for(edge *t=e[v];t;t=t->next)
		if(!used[t->v])
		{
			used[t->v]=true;
			if(!match[t->v]||find(match[t->v]))
			{
				match[t->v]=v;
				return true;
			}
		}
	return false;
}

void addedge(int a,int b)
{
	e[a]=new edge(b,e[a]);
}

int compare(int a,int b)
{
	bool greater=true,smaller=true;
	for(int i=1;i<=q;++i)
	{
		//printf("%d %d\n",data[a][i],data[b][i]);
		if(data[a][i]<=data[b][i]) greater=false;
		if(data[a][i]>=data[b][i]) smaller=false;
	}
	if(greater) return 1;
	if(smaller) return -1;
	return 0;
}

int main()
{
    freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int zz,p;
	cin>>zz;
	for(int z=1;z<=zz;++z)
	{
		int r=0;
		cin>>p>>q;
		for(int i=1;i<=p;++i)
			for(int j=1;j<=q;++j)
				cin>>data[i][j];
		memset(match,0,sizeof(match));
		memset(e,0,sizeof(e));
		for(int i=1;i<p;++i)
			for(int j=i+1;j<=p;++j)
			{
				int cmp=compare(i,j);
				if(cmp==-1) addedge(j,i);
				else if(cmp==1) addedge(i,j);
				//printf("%d %d %d %d\n",q,i,j,cmp);
			}
		for(int i=1;i<=p;++i)
		{
			memset(used,false,sizeof(used));
    		if(find(i)) ++r;
		}
		printf("Case #%d: %d\n",z,p-r);
	}
	return 0;
}
