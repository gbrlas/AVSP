#include <cstdio>
#include <cstring>
#include <algorithm>
#define REP(i,n) for(int i = 0;i<n;i++)
#define LD long double
#define INF 1000000000

using namespace std;

int w[200];
int t[200][200];
int p, q;

int f(int a, int b) {
	if(b<a) return 0;
	if(t[a][b]!=-1) return t[a][b];
	int v = INF;
	int temp=0;
	if(a==0) temp-=0;
	else temp-=w[a-1];
	if(b==q-1) temp+=p;
	else temp+=w[b+1]-1;
	temp--;
	if(a==b) {
		t[a][b]=temp;
		return t[a][b];
	}
	REP(i,b-a+1) {
		v=min(v,temp+f(a,a+i-1)+f(a+i+1,b));
	}
	t[a][b]=v;
	return t[a][b];
}

int main() {
	int T;
	scanf("%d", &T);
	REP(z,T) {
		printf("Case #%d: ", z+1);
		scanf("%d %d", &p, &q);
		REP(i,q) scanf("%d", &w[i]);
		REP(i,q) REP(j,q) t[i][j]=-1;
		printf("%d\n", f(0,q-1));
	}
	return 0;
}
