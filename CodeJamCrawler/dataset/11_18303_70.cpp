#include <cstdio>
#include <cstring>

using namespace std;

typedef struct cmd {
	int btm, pos;
} cmd;

#define MAXN 110

int main() {
	int t,n,posa,posb,x,flag,cont,nteste=1;
	int qa, qb,d, exec[MAXN], execa, execb;
	cmd roboa[MAXN], robob[MAXN];
	char c;
	scanf("%d",&t);
	while (t--) {
		scanf("%d",&n);
		qa = qb = 0;
		for (int i=0; i<n; i++) {
			scanf(" %c %d",&c,&d);
			if (c == 'O') {
				roboa[qa].btm = d;
				roboa[qa++].pos = i;
			}

			else {
				robob[qb].btm = d;
				robob[qb++].pos = i;
			}
		}

		execa = execb = cont = 0;
		posa = posb = 1;
		for (int i=0; i<n; i++) exec[i] = 0;
		
		while (!exec[n-1]) {
			cont++;
			flag = 0;
			if (execa != qa) {
				x = roboa[execa].btm;
				if (posa == x && exec[roboa[execa].pos-1]) flag = 1;
				else if (posa<x) posa++;
				else if (posa>x) posa--;
			}

			if (execb != qb) {
				x = robob[execb].btm;
				if (posb == x && exec[robob[execb].pos-1]) { exec[robob[execb].pos] = 1; execb++; }
				else if (posb<x) posb++;
				else if (posb>x) posb--;
			}

			if (flag) { exec[roboa[execa].pos] = 1; execa++; }
			
		}
		
		
		printf("Case #%d: %d\n",nteste++,cont);
		
	}

	return 0;
}
