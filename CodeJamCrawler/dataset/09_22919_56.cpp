#include <cstdio>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <vector>
#include <cctype>
#include <cmath>
#include <list>
#include <string>
#include <set>
#include <map>
#include <deque>
#include <queue>
#include <algorithm>
#include <stack>
#include <numeric>
#include <bitset>
#include <ext/numeric>

#define DISP(v,i) for(typeof(v.begin()) i=v.begin();i!=v.end();++i) printf("%d ",*i); printf("\n")
#define DTAB(i,start,end) for(int i=0;i<end-start;++i) printf("%d ",*(start+i)); printf("\n")
#define PRI(a) printf(#a": %d\n",a)
#define PRF(a) printf(#a": %f\n",a)

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORTO(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,b,a) for(int i=(b);i>=(a);--i)
#define FOREACH(i,v) for(typeof((v).begin()) i=(v).begin();i!=(v).end();++i)
#define REP(i,n) for(int i=0;i<(n);++i)
#define ALL(v) (v).begin(),(v).end()
#define ZLO printf("ZLOOOOOOO!\n"); return 1
#define MP make_pair
#define PB push_back
#define FI first
#define SE second
#define GCD __gcd

using namespace std;
using namespace __gnu_cxx;

inline int CEIL(int a,int b) { return a%b ? a/b+1 : a/b; }

int toi(char ch) { return int(ch)-int('0'); }
int chg(char ch) { return int(ch)-int('a'); }

typedef long long LL;
typedef unsigned long long ULL;
typedef double D;
typedef long double LD;
typedef unsigned U;
typedef vector<int> VI;
typedef pair<int,int> PI;
typedef vector<string> VS;

const int INF=2000000000;
const double EPS=1e-10;

char buff[100];

struct Node {
	string name;
	double prob;
	Node *one;
	Node *two;
	Node():name(""),prob(0.0),one(NULL),two(NULL) {}
	Node(double _p):name(""),prob(_p),one(NULL),two(NULL) {}
	Node(double _p,string _n):name(_n),prob(_p),one(NULL),two(NULL) {}
	double prune(VS& features,double pr) {
		pr=pr*prob;
		if(pr<1e-7) return 0.0;
		if(name==""||!one||!two) return pr;
		if(binary_search(ALL(features),name))
			return one->prune(features,pr);
		else return two->prune(features,pr);
	}
	~Node() {
		if(one) delete one;
		if(two) delete two;
	}
};

Node* getNode() {
	char c=getchar();
	while(c!='('&&c!=')') c=getchar();
	if(c==')') return NULL;
	double prob;
	scanf("%lf",&prob);
	while(c!=')'&&(c<'a'||c>'z')) c=getchar();
	if(c==')') return new Node(prob);
	int i=0;
	while(c<='z'&&c>='a') { buff[i++]=c; c=getchar(); }
	buff[i]=0;
	string name(buff);
	Node *ret=new Node(prob,name);
	ret->one=getNode();
	ret->two=getNode();
	while(c!=')') c=getchar();
	
//	printf("%s\n",ret->name.c_str());
	return ret;
}

int main() {
	int n;
	scanf("%d",&n);
//	printf("%d\n",n);
	REP(CASE,n) {
		int l,a;
		scanf("%d",&l);
//		printf("%d\n",l);
		Node *root=getNode();
		scanf("%d",&a);
//		printf("%d\n",a);
		printf("Case #%d:\n",CASE+1);
		REP(ANIMAL,a) {
			scanf("%s",buff);
	//		puts(buff);
			string animal(buff);
			int fts;
			scanf("%d",&fts);
			VS features;
			REP(FEATURE,fts) {
				scanf("%s",buff);
	//			puts(buff);
				features.push_back(string(buff));
			}
			sort(ALL(features));
			printf("%.7lf\n",root->prune(features,1.0));
		}
		delete root;
	}
	return 0;
}

