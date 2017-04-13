#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

int task, CASE=0, x, y, d, lostA, lostB, pA, pB, winA;
long long n;

int gcd( int a, int b ){
	if ( b==0 ) return a;
	return gcd( b, a%b );
}

bool check(){
	d = gcd( x, 100 );
	pA = 100/d;
	lostA = (100-x)/d;
	if ( pA>n ) return false;
	if ( y==100 && x!=100 ) return false;
	if ( y==0 && x!=0 ) return false;
/*	winA = x/d;

	d = gcd( y, 100 );
	pB = 100/d;
	lostB = (100-y)/d;
	cout<<pA<<' '<<n<<' '<<lostA<<' '<<lostB<<endl;
*/
}

int main(){
	freopen("A-large.in","r",stdin);
//	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	for (scanf("%d", &task); task--;){
		scanf("%I64d%d%d", &n, &x, &y);
		if ( check() )
			printf("Case #%d: Possible\n", ++CASE);else
			printf("Case #%d: Broken\n", ++CASE);
	}
	return 0;
}
