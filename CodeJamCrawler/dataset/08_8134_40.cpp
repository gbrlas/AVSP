//#include <cstdio>
#include <vector>
#include <algorithm>

#define maxn 60


using namespace std;

int di[2][2]={
	1,0,0,1};
 
const int N = 6000;
const int INF = 1 << 28;
bool vst[N] ; 
int up=N;
class Edge {
public:
	int u, v, cuv, cvu, flow, cost;
	Edge(int cu, int cv, int ccu, int ccv, int cc) 
		: u(cu), v(cv), cuv(ccu), cvu(ccv), flow(0), cost(cc) {}
	int other(int p) const { return p == u ? v : u; }
	int cap(int p) const { return p == u ? cuv-flow : cvu+flow; }
	int ecost(int) const;
	void addFlow(int p, int f) { flow += (p == u ? f : -f); }
};
int Edge::ecost(int p) const {
	if(flow == 0) return cost;
	else if(flow > 0) return p == u ? cost : -cost;
	else return p == u ? -cost : cost;
}
 
class Network {
public:
	vector<Edge> eg;
	vector<Edge*> net[N];
	Edge *prev[N];
	int v, s, t;
	int flow, cost, phi[N], dis[N], pre[N];
	void initNet();
	void initFlow();
	bool dijkstra();
	bool Network::Bellman();
public:
	int getCost() const { return cost; }
	int getFlow() const { return flow; }
	int mincost(int, int);
	
}minflow;
void Network::initNet() {
	int i;
	for(i = 0; i < v; i++) net[i].clear();
	for(i = eg.size()-1; i >= 0; i--) {
		net[eg[i].u].push_back(&eg[i]);
		net[eg[i].v].push_back(&eg[i]);
   }
}

void Network::initFlow() {
	flow = cost = 0;
	memset(phi, 0, sizeof(int)*up);
	initNet();
}

bool Network::dijkstra() {
	int i;
	for(i = 0; i < v; i++) dis[i] = INF;
	dis[s] = 0; prev[s] = NULL; pre[s] = -1;
	
	memset(vst,0,sizeof(bool)*up);
	for(i = 1; i < v; i++) {
		int md = INF, u,j;
		for(j = 0; j < v; j++)
			if(!vst[j] && md > dis[j]) { md = dis[j]; u = j; }
		if(md == INF) break;
		vst[u] = true;
		for(j = net[u].size()-1; j >= 0; j--) {
			Edge *ce = net[u][j];
			if(ce->cap(u) > 0) {
				int p = ce->other(u), cw = ce->ecost(u)-phi[u]+phi[p];
				if(dis[p] > dis[u]+cw) { dis[p] = dis[u]+cw; prev[p] = ce; pre[p] = u; }
			}
		}
	}
	return (dis[t] != INF);
}


bool Network::Bellman() {
	int i,j;
	for(i = 0; i < v; i++) dis[i] = INF;
	dis[s] = 0; prev[s] = NULL; pre[s] = -1;
	bool o;
	for(i = 1; i < v; i++) {
		o=1;
		for(j=0;j<eg.size();j++)if(dis[eg[j].u]<INF)if(dis[eg[j].u]+eg[j].cost<dis[eg[j].v])
			dis[eg[j].v]=dis[eg[j].u]+eg[j].cost,o=0;
		if(o)break;
	}
	for(i = 0; i < v; i++) phi[i] -= dis[i];
	return (dis[t] != INF);
}

int Network::mincost(int ss, int tt) {
	s = ss; t = tt; initFlow();
	//Add it if needed.
	Bellman(); 
	int c;
	while(dijkstra()) {
		int ex = INF;
		//for(c = t; c != s; c = pre[c]) ex <?= prev[c]->cap(pre[c]);
		for(c = t; c != s; c = pre[c]) ex = (ex<prev[c]->cap(pre[c])?ex:prev[c]->cap(pre[c]));
		for(c = t; c != s; c = pre[c]) prev[c]->addFlow(pre[c], ex);
		flow += ex; cost += ex*(dis[t]-phi[t]);
		for(int i = 0; i < v; i++) phi[i] -= dis[i];
	}
	return cost;
}

int i,j,n,m,ii,jj,r;

int p[maxn];

int q[maxn];




int main(){
	//freopen("a.txt","r",stdin);
	int ii,nn;
	scanf("%d",&nn);
	for(ii=1;ii<=nn;ii++){
		printf("Case #%d	: ",ii);
		scanf("%d",&n);
		minflow.eg.clear();
		for(i=1;i<=n;i++){
			scanf("%d",&p[i]);
			minflow.eg.push_back(Edge(0,i,1,0,0));
		}
		for(i=1;i<=n;i++){
			scanf("%d",&q[i]);
			minflow.eg.push_back(Edge(i+n,n+n+1,1,0,0));
		}
		for(i=1;i<=n;i++)for(j=1;j<=n;j++){
			minflow.eg.push_back(Edge(i,j+n,1,0,p[i]*q[j]));
		}
		up=minflow.v=n+n+2;
		up+=10;
		minflow.initFlow();
		minflow.mincost(0,n+n+1);
		printf("%d\n",minflow.getCost());
	}
	
	return 0;
	
}
