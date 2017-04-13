#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<iostream>
#include<sstream>
#include<set>
#include<cctype>
#include<cassert>
using namespace std;

#ifdef ONLINE_JUDGE

#define assert(x)
#define dbg(x)
#define trace()

#else

#define dbg(x) do { cout << "DEBUG, line " << __LINE__ << " (" << __func__ << "), " << #x << ": " << x << endl; } while(0)
#define trace() do { cout << "TRACE, line " << __LINE__ << " (" << __func__ << ")" << endl; } while(0)

#endif

#define FOREACH(i,x) for (__typeof((x).begin()) i=(x).begin(); i!=(x).end(); ++i)

const int N = 4001;
const int SIZ = 101;
char buf[N];

set<string>S;

int adj[SIZ][SIZ];

int act_id = 0;
map<char,int>IDS;
int c2i(char c){
	if(IDS.count(c)){
		return IDS[c];
	} else {
		return IDS[c] = act_id++;
	}
}
int deg[SIZ];
bool visited[SIZ];
bool color[SIZ];
int siz;

void add(char a, char b){
	string s = "";
	s+=a; s+=b;
	if(S.count(s)==0){
		adj[c2i(a)][c2i(b)]++;
		deg[c2i(a)]++;
		deg[c2i(b)]--;
	}
	S.insert(s);
}

void printstats(){
	printf("degs: ");
	for(int i=0; i<siz; i++){
		printf("%d ", deg[i]);
	}
	printf("\n");
	for(int i=0; i<siz; i++){
		for(int j=0; j<siz; j++){
			printf("%d ", adj[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

char leet(char c){
	// "o" to "0", "i" to "1", "e" to "3", "a" to "4", "s" to "5", "t" to "7", "b" to "8" and/or "g" to "9"
	if(c=='o') return '0';
	if(c=='i') return '1';
	if(c=='e') return '3';
	if(c=='a') return '4';
	if(c=='s') return '5';
	if(c=='t') return '7';
	if(c=='b') return '8';
	if(c=='g') return '9';
	return c;
}

int dfs(int v){
	if(!color[v]) return 0;
	color[v]=false;

	int result = 0;
	if(visited[v]) result = 1;

	for(int u=0; u<siz; u++) if(adj[v][u] && color[u]){
		result = max(result, dfs(u));
	}
	return result;
}

int count(){
	int res = 0;
	for(int i=0; i<siz; i++) color[i] = true;

	for(int i=0; i<siz; i++) if(color[i]){
		res+=1-dfs(i);
	}
	return res;
}

void go(int v){
	//printf("go %d\n",v);
	visited[v] = true;
	for(int u=0; u<siz; u++) if(adj[v][u]){
		//printf("v %d, u %d, adj %d\n",v,u,adj[v][u]);
		adj[v][u]--;
		deg[v]--;
		deg[u]++;
		go(u);
		break;
	}
}


int algo(){
	for(int i=0; i<SIZ; i++) {
		visited[i]=false;
	}
	int res = 0;
	while(true){
		//printstats();
		bool br = true;
		for(int i=0; i<siz; i++){
			if(deg[i]>0){
				go(i);
				res++;
				br = false;
				break;
			}
		}
		if(br)break;
	}
	res+=count();
	return res;
}

void solve(){
	int k;
	S.clear();
	IDS.clear();
	act_id = 0;

	for(int i=0; i<SIZ; i++) {
		deg[i]=0;
		for(int j=0; j<SIZ; j++) adj[i][j] = 0;
	}

	scanf("%d",&k);
	scanf("%s",buf);
	int n = strlen(buf);

	siz = 0;
	for(int i=0; i<n; i++){
		siz = max(siz, c2i(buf[i])+1);
		siz = max(siz, c2i(leet(buf[i]))+1);
	}

	for(int i=0; i+1<n; i++){
		add(buf[i], buf[i+1]);
		add(buf[i], leet(buf[i+1]));
		add(leet(buf[i]), buf[i+1]);
		add(leet(buf[i]), leet(buf[i+1]));
	}
	int res = S.size();
	res+=algo();
	printf("%d\n",res);
}

int main(){
	int t;
	scanf("%d",&t);
	for(int tc=1; tc<=t; tc++){
		printf("Case #%d: ", tc);
		solve();
	}
}
