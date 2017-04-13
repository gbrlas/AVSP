#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>

using namespace std;

const int N = 2007;

vector<int> G[N];
int wy[N];
int deg[N];

int first[N];
int last[N];
int seq[N];

void add_edge(int u, int v, int n, bool inv){
	if(inv){
		u = n+1 - u;
		v = n+1 - v;
	}
	G[u].push_back(v);
	deg[v]++;
}

void read(int n, bool inv){
	for(int i=1; i<=n; i++)
		first[i] = last[i] = 0;
	for(int i=1; i<=n; i++) scanf("%d", seq+i);
	if(inv) reverse(seq+1, seq+1+n);

	for(int i=1; i<=n; i++){
		if(!first[seq[i]]) first[seq[i]] = i;
		if(seq[i] > 1){
			add_edge(last[seq[i]-1], i, n, inv);
		}
		if(last[seq[i]]) add_edge(i, last[seq[i]], n, inv);
		last[seq[i]] = i;
	}
}

void toposort(int n){
	priority_queue<int, vector<int>, greater<int> > kol;
	for(int i=1; i<=n; i++){
		if(deg[i] == 0) kol.push(i);
	}
	int i=0;
	while(!kol.empty()){
		int v = kol.top(); kol.pop();
		wy[v] = ++i;
		for(vector<int>::iterator it = G[v].begin(); it != G[v].end(); it++){
			deg[*it] --;
			if(!deg[*it]) kol.push(*it);
		}
	}
}

void test(int tt){
	int n;
	scanf("%d", &n);
	for(int i=1; i<=n; i++){
		G[i].clear();
		deg[i] = 0;
	}

	read(n, false);
	read(n, true);

	toposort(n);

	printf("Case #%d: ", tt);
	for(int i=1; i<=n; i++) printf("%d%c", wy[i], " \n"[i==n]);
}

int main(){
	int t;
	scanf("%d", &t);
	
	for(int i=1; i<=t; i++){
		test(i);
	}
}
