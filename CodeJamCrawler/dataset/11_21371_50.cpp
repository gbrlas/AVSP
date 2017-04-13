#include <cstdio>
#include <iostream>

using namespace std;

int main(){
	int test=0;
	scanf("%d",&test);
	for ( int T=1; T<=test; ++T ){
		long long n,a,b;
		cin>>n>>a>>b;
		long long t=0;
		for ( int i=1; i<=min(100LL,n); ++i )
			if ( a*i%100==0 ){
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
