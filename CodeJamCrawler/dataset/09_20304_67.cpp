#include <cstdio>
#include <iostream>
#include <sstream>

using namespace std;

int a[20], tot, limit=10;
int app[20000000], now;
int ok[12000000];

bool check( int x, int base ){
    now++; app[x]=now;
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
		if ( app[sum]==now ) return false;
		app[sum]=now;
		tot=0;
		while ( sum>0 ){
			a[tot++]=sum%base;
			sum/=base;
		}
	}
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    now=0;
    for ( int i=2; i<=11814485; i++ ){
        //if ( i%100000==0 ) printf("%d\n", i);
    	for ( int j=2; j<=10; j++ )
    		if ( check(i,j) )
    			ok[i]+=(1<<(j-2));
   } 
/*    int test=0;
    scanf("%d ", &test);
    int T=0;
    while ( test-- ){
        gets(s);
        istringstream sin(s);
        int n=0, x;
        while ( sin>>x )
        	aa[n++]=x;*/
    for ( int i=0; i<512; i++ )
    	for ( int j=0; j<=11814485; j++ ){
    	    bool can=true;
    		for ( int k=0; k<9; k++ )
    			if ( (i&(1<<k)) && ((ok[j]&(1<<k))==0) ){
    				can=false; break;
    			}
			if (can){
				printf("%d,\n", j);
				break;
			}				
		}				
//}
}
