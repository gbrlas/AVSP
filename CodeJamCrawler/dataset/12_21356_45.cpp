#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
	int test=0;
	scanf("%d",&test);
	for (int T=1; T<=test; ++T){
		printf("Case #%d: ", T);
		int n,s,p;
		scanf("%d %d %d", &n, &s, &p);
		int ans=0,tmp=0;
		for (int i=0; i<n; ++i){
			int x;
			scanf("%d", &x);
			if (x>p*3-3) ++ans; else 
				if (x>=p+max(0,p-2)+max(0,p-2)) ++tmp;
		}
		printf("%d\n", ans+min(s,tmp));
	}
}
