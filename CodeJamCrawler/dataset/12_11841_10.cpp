#include<stdio.h>
#include<algorithm>
#include<map>
#include<string>
#include<string.h>
#include<set>
#include <vector>
using namespace std;
#define maxn 3000
map<char,char> dict;




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
	bool Bellman();
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
	//Bellman(); 
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


void initDict(){
        char a;
        for(a='a';a<='z';a++){
                dict[a]=a;
        }
        dict['o']='0';
        dict['i']='1';
        dict['e']='3';
        dict['a']='4';
        dict['s']='5';
        dict['t']='7';
        dict['b']='8';
        dict['g']='9';
}

set<string> all;

string que[maxn];

int t,i,j,n,m,k;

char buffer[maxn];

void add(string& a){
        if(all.find(a)==all.end()){
                que[++n]=a;
                all.insert(a);
        }
}


bool p[maxn][maxn];

int last[maxn];

int checked[maxn];

bool findit(int a){
        int i,q;
        for(i=1;i<=n;i++){
                if(!checked[i]){
                        checked[i]=1;
                        q=last[i];
                        last[i]=a;
                        if(q==0)
                                return 1;
                        if(findit(q))
                                return 1;
                        last[i]=q;
                }
        }
        return 0;
}



int max_match(){
        memset(last,0,sizeof(last));
        int ans=0,i;
        for(i=1;i<=n;i++){
                memset(checked,0,sizeof(checked));
                if(findit(i))
                        ans++;
        }
        return ans;
}

int main(){
        initDict();
        int ii,nn;
        scanf("%d",&nn);
        for(ii=1;ii<=nn;ii++){
                printf("Case #%d: ",ii);
                scanf("%d",&i);
                scanf("%s",buffer);
                n=0;
                all.clear();
                for(i=1;buffer[i];i++){
                        string now="";
                        now+=buffer[i-1];
                        now+=buffer[i];
                        string temp;

                        for(j=0;j<4;j++){
                                temp=now;
                                for(k=0;k<2;k++)
                                        if((1<<k)&j){
                                                temp[k]=dict[temp[k]];

                                        }
                                add(temp);
                        }
                }
                // for(i=1;i<=n;i++){
                //         printf("%s\n",que[i].c_str());
                // }
                memset(p,0,sizeof(p));
                minflow.eg.clear();

                
                
                // for(i=1;i<=n;i++){
                //         for(j=1;j<=n;j++){
                //                 if(i!=j)
                //                         if(que[i][1]==que[j][0]){
                //                                 p[i][j]=1;
                                                
                //                         }
                //         }
                // }
                // i=max_match();
                int s[1000];
                memset(s,0,sizeof(s));
                for(i=1;i<=n;i++){
                        s[que[i][0]]++;
                        s[que[i][1]]--;                        
                }
                j=0;
                for(i=0;i<1000;i++){
                        if(s[i]>0){
                                j+=s[i];
                        }
                }
                if(j==0)
                        printf("%d\n",n+1);
                else
                        printf("%d\n",n+j);
        }
        return 0;
}
