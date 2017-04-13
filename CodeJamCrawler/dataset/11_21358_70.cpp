#include <cstdio>

int n;

int main(){
	int test=0;
	scanf("%d",&test);
	for ( int T=1; T<=test; ++T ){
		scanf("%d",&n);
		int ans=0,mm=-1,s=0;
		for ( int i=0; i<n; ++i ){
			int x;
			scanf("%d",&x);
			s+=x;
			ans^=x;
			if ( mm==-1 || x<mm ) mm=x;
		}
		printf("Case #%d: ", T);
		if ( ans==0 )
			printf("%d\n", s-mm);
		else
			printf("NO\n");
	}
}
