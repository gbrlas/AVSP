#include "cmath"
#include "cstdio"
#include "algorithm"
#include "map"
#include "numeric"
#include "queue"
#include "set"
#include "string"
#include "utility"
#include "vector"
using namespace std;

int t,T;
int N,n,S,p,act;
int s,ns,g,sg;
int sol;
void testc() {
	scanf("%d %d %d",&N, &S, &p);
	sg = max(p,3*p-4);
	g = max(p,3*p-2);
	s=0; ns=0;
	for(n=0;n<N;n++) {
		scanf("%d",&act);
		if(sg<=act && act<g) {
			s++;
		}
		if(g<=act) {
			ns++;
		}
	}
	sol = ns+min(S,s);
	printf("Case #%d: %d\n",t,sol);
}

int main() {
	scanf("%d",&T);
	for(t=1;t<=T;t++) {
		testc();
	}
	return 0;
}