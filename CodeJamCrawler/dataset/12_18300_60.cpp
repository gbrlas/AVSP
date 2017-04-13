#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
	int nt,nteste=1,n,s,res,p,v;
	scanf("%d",&nt);
	while (nt--) {
		scanf("%d%d%d",&n,&s,&p);	res = 0;	p *= 3;
		for (int i=0; i<n; i++) {
			scanf("%d",&v);
			if (v >= p) res++;
			else {
				int k = p - v;
				if (k == 1 || k == 2) {
					if (p/3 >= 1) res++;
				}
				else if (k == 3 || k == 4) {
					if (s && p/3 >= 2) { res++;	s--;	}
				}
			}
		}
			
		printf("Case #%d: %d\n",nteste++,res);
	}
	
	return 0;
}