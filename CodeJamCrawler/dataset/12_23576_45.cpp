#include<map>
#include<set>
#include<stack>
#include<queue>
#include<algorithm>
#include<sstream>
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<cfloat>
#include<numeric>
#include<vector>
using namespace std;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
typedef pair<int,int> pii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;

#define sz(c) int((c).size())
#define all(c) (c).begin() , (c).end()
#define FOR(i,a,b) for (int i=(a); i<(b); i++)
#define FORD(i,a,b) for(int i=int(b)-1; i>=a; i--)
#define FORIT(i,c) for(__typeof__((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define pb push_back
#define mp make_pair

int main(){
	map<char,char> mem;
	set<char> k1, k2;
	string a1 = "ejp mysljylc kd kxveddknmc re jsicpdrysi";
	string a2 = "our language is impossible to understand";
	string b1 = "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
	string b2 = "there are twenty six factorial possibilities";
	string c1 = "de kr kd eoya kw aej tysr re ujdr lkgc jv";
	string c2 = "so it is okay if you want to just give up";
	FOR(i,0,sz(a1)){
		mem[a1[i]]=a2[i];
		k1.insert(a1[i]); k2.insert(a2[i]);
	}
	FOR(i,0,sz(b2)){
		mem[b1[i]]=b2[i];
		k1.insert(b1[i]); k2.insert(b2[i]);
	}
	FOR(i,0,sz(c1)){
		mem[c1[i]]=c2[i];
		k1.insert(c1[i]); k2.insert(c2[i]);
	}
	mem['z']='q';
	mem['q']='z';
	int tc;
	scanf("%d\n",&tc);
	FOR(tt,0,tc){
		cout << "Case #" << tt+1 << ": ";
		string inp;
		getline(cin,inp);
		FOR(i,0,sz(inp)){
			cout << mem[inp[i]];
		}
		cout << endl;
	}
	return 0;
}
