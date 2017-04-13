#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <map>
#include <sstream>
#include <queue>
#include <stack>
#include <math.h>
#include <utility>
#include <iterator>
#include <fstream>
#include <stdio.h>

using namespace std;

template<class T>
string tostring(T a){stringstream ss; ss<<a; return ss.str();}

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> II;
typedef long long LL;
#define SZ(a) int((a).size()) 
#define PB push_back 
#define ALL(c) (c).begin(),(c).end() 
#define FOR(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define LOOP(i,a,b) for((i)=(a);(i)<(b);(i)++)
#define MP(a,b) make_pair((a),(b))
#define LAST(t) (t[SZ(t)-1])

VVI g;
VI numth;
vector<bool> szurke;
int ma;
int n;

void dfs(int u, int d){
	if(d==0){
		if(u==1){
			int c=0;
			FOR(i,n)
				if(numth[i] && !szurke[i])
					c++;
			ma=max(ma,c);
		}
		return;
	}

	szurke[u]=true;

	FOR(i,SZ(g[u]))
		numth[g[u][i]]++;
	
	FOR(i,SZ(g[u])){
		int v=g[u][i];
		if(!szurke[v]){
			dfs(v,d-1);
		}
	}

	FOR(i,SZ(g[u]))
		numth[g[u][i]]--;

	szurke[u]=false;
}

int main(){
	ifstream be("D-small-attempt0.in");
	ofstream ki("ki.txt");
	int t;
	be>>t;
	FOR(tt,t){
		int P,W;
		be>>P>>W;
		g = VVI(P);
		FOR(i,W){
			string s;
			be>>s;
			int j;
			for(j=0; s[j]!=','; j++);
			s[j]=' ';
			stringstream ss;
			ss<<s;

			int u,v;
			ss>>u>>v;
			g[u].PB(v);
			g[v].PB(u);
		}
		
		n=P;
		queue<int> q;
		q.push(0);
		vector<int> volt(n);
		volt[0]=1;
		bool kesz=false;
		while(!kesz){
			int u=q.front(); q.pop();
			FOR(i,SZ(g[u])){
				int v=g[u][i];
				if(!volt[v]){
					volt[v]=volt[u]+1;
					q.push(v);
					if(v==1){
						kesz=true;
						break;
					}
				}
			}
		}
		
		int tav=volt[1]-1;

		numth=VI(n);
		szurke=vector<bool>(n);
		ma=-1;
		dfs(0,tav);

		ki<<"Case #"<<tt+1<<": "<<tav-1<<" "<<ma<<endl;
	}
	

	ki.close();
	return 0;
}