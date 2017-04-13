#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <iostream>
using namespace std;
const int maxn=10100;

set<string> mp;
double p[maxn], ret; 
string id[maxn];
int l, o, ll;
int task, cs=0;
char s[maxn], st[maxn];
string all, alls;

void readd( int x){
	while ( s[o]!='(' ) o++;
	o++;
	sscanf(s+o, "%lf%n", &p[x], &ll);
	o+=ll;
	sscanf(s+o, "%s%n", st, &ll);	
	if ( st[0]==')' ){
		id[x] = "-1";
		return;
	}
	id[x] = st;
	readd( x*2 );
	readd( x*2+1);
	while ( s[o]!=')' ) o++;
	o++;
}

void dfs( int x ){
	ret *= p[x];
	if ( id[x]=="-1" ) return;
	if ( mp.count( id[x] )>0 )
		dfs( x*2 );else
		dfs( x*2+1 );
}

int main(){
	freopen("A-small-attempt0.in","r",stdin);
	freopen("a.out","w",stdout);
	for (scanf("%d\n", &task); task--;){
		all = "";
		scanf("%d\n", &l); 
		for (int i=1;i <=l; i++){
			gets(s); alls = s;
			all += alls;
		}
		for (int i=0; i<all.length(); i++)
			s[i] = all[i];
		s[all.length()] = 0;
		o = 0;
		readd( 1 );
		printf("Case #%d:\n", ++cs);
		int tt, num;
		for (scanf("%d", &tt); tt--;){
			mp.clear();
			for (scanf("%s %d", s, &num);num--;){
				scanf("%s", s);
				alls = s;
				mp.insert( alls );
			}
			ret = 1;
			dfs( 1 );
			printf("%.7lf\n", ret);
		}
	}
	return 0;
}
