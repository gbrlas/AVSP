#include<stdio.h>
#include<algorithm>

using namespace std;

typedef int FLOW;
const int MaxNode=200012;
const int MaxEdge=340000;
const FLOW FLOW_INF=((FLOW)1<<(sizeof(FLOW)*8-1))-1;

struct Edge {
	int t;
	FLOW weight;
	Edge *next;
}edges[MaxEdge*2];
int edgecnt=0;

struct Node {
	int d;
	Edge *edge;
}nodes[MaxNode];

void InitGraph(int n) {
	for(int i=0;i<n;i++) nodes[i].edge=NULL;
	edgecnt=0;
}

void _AddEdge(int s, int t, FLOW weight) {
	edges[edgecnt].t=t;
	edges[edgecnt].weight=weight;
	edges[edgecnt].next=nodes[s].edge;
	nodes[s].edge=edges+edgecnt;
	edgecnt++;
}

void AddEdge(int s, int t, FLOW weight) {
	_AddEdge(s, t, weight);
	_AddEdge(t, s, 0);
}

Edge inline *OthEd(Edge *e) { return &edges[(e-edges)^1]; }

bool bfs(int s, int t, int n) {
	Node *queue[MaxNode];
	int head=0, tail=0;
	for(int i=0;i<n;i++) nodes[i].d=MaxNode;
	queue[tail++]=nodes+t;
	nodes[t].d=0;
	while(head<tail) {
		Node *cur=queue[head++];
		for(Edge *p=cur->edge;p!=NULL;p=p->next) {
			if(OthEd(p)->weight>0 && nodes[p->t].d==MaxNode) {
				nodes[p->t].d=cur->d+1;
				if(p->t==s) return true;
				queue[tail++]=nodes+p->t;
			}
		}
	}
	return false;
}

int trm;
FLOW dfs(Edge *ce, FLOW flow) {
	if(flow>ce->weight) flow=ce->weight;
	FLOW f=0;
	if(ce->t==trm) f=flow;
	else {
		Node *n=nodes+ce->t;
		int mn=MaxNode;
		Edge *e;
		for(e=n->edge;e!=NULL && f<flow;e=e->next) {
			if(e->weight>0 && nodes[e->t].d<n->d)
				f+=dfs(e, flow-f);
			if(e->weight>0)
				mn=std::min(mn, nodes[e->t].d);
		}
		for(;e!=NULL && mn>=n->d;e=e->next)
			if(e->weight>0)
				mn=std::min(mn, nodes[e->t].d);
		n->d=mn+1;
	}
	OthEd(ce)->weight+=f;
	ce->weight-=f;
	return f;
}

FLOW dinic(int s, int t, int n) {
	FLOW flow=0;
	trm=t;
	while(bfs(s, t, n))
		for(Edge *e=nodes[s].edge;e!=NULL;e=e->next) 
			if(e->weight>0 && nodes[e->t].d<nodes[s].d)
				flow+=dfs(e, FLOW_INF);
	return flow;
}

bool u[110][510];

int main()
{
	int t,p;
	int i,j,k;
	int h,w,n;
	freopen("C-small-attempt1.in","r",stdin);
	freopen("C-small-attempt1.out","w",stdout);
	scanf("%d",&t);
	for (p=1;p<=t;p++)
	{
		scanf("%d%d%d",&w,&h,&n);
		InitGraph(2*w*h+2);
		for (i=1;i<=w;i++)
			AddEdge(0,i,1);
		for (i=1;i<=w;i++)
			AddEdge(h*w+(h-1)*w+i,2*h*w+1,1);
		memset(u,true,sizeof(u));
		for (i=1;i<=n;i++)
		{
			int x1,y1,x2,y2;
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			for (j=x1+1;j<=x2+1;j++)
				for (k=y1+1;k<=y2+1;k++)
					u[j][k]=false;
		}
		for (i=1;i<=w;i++)
			for (j=1;j<=h;j++)
			{
				if (u[i][j]) AddEdge((j-1)*w+i,h*w+(j-1)*w+i,1);
				if (j>1) AddEdge(h*w+(j-1)*w+i,(j-2)*w+i,1);
				if (j<h) AddEdge(h*w+(j-1)*w+i,j*w+i,1);
				if (i>1) AddEdge(h*w+(j-1)*w+i,(j-1)*w+i-1,1);
				if (i<w) AddEdge(h*w+(j-1)*w+i,(j-1)*w+i+1,1);
			}
		printf("Case #%d: %d\n",p,dinic(0,2*h*w+1,2*h*w+2));
	}
	return 0;
}
