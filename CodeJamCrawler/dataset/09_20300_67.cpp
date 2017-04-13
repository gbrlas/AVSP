#include <cstdio>
#include <iostream>
#include <sstream>

using namespace std;

int a[20], tot, limit=10;

bool check( int x, int base ){
	tot=0;
	while ( x>0 ){
		a[tot++]=x%base;
		x/=base;
	}
	int tt=0;
	while ( true ){
		int sum=0;
		for ( int i=0; i<tot; i++ )
			sum+=a[i]*a[i];
		if ( sum==1 ) return true;
		tot=0;
		while ( sum>0 ){
			a[tot++]=sum%base;
			sum/=base;
		}
		tt++;
		if ( tt==limit ) return false;
	}
}

char s[10000];
int aa[10];

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int test=0;
    scanf("%d ", &test);
    int T=0;
    while ( test-- ){
        gets(s);
        istringstream sin(s);
        int n=0, x;
        while ( sin>>x )
        	aa[n++]=x;
	for ( int i=2; ;i++ ){
		bool ok=true;
		for ( int j=0; j<n; j++ )
			if ( ! check(i, aa[j]) ){
				ok=false; break;
			}
		if ( ok ){
			printf("Case #%d: %d\n", ++T, i);
			break;
		}
	}
}	
}
