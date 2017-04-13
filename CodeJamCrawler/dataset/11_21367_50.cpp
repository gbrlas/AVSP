#include <cstdio>
#include <iostream>

using namespace std;

int main(){
	int test=0;
	scanf("%d",&test);
	for ( int T=1; T<=test; ++T ){
		int n,a,b;
		scanf("%d %d %d",&n,&a,&b);
		int t=0;
		for ( int i=1; i<=min(100,n); ++i )
			if ( i*a%100==0 ){
				t=i; break;
			}
		printf("Case #%d: ", T);
		if ( t==0 ){
			printf("Broken\n");
		} else {
			if ( b==100 && a==100 )
				printf("Possible\n");
			else
				if ( b==0 && a==0)
					printf("Possible\n");
				else
					if ( b!=0 && b!=100 )
						printf("Possible\n");
					else
						printf("Broken\n");
		}
	}
}
