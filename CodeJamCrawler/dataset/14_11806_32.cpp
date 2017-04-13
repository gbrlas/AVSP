#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cctype>
#include <queue>
#include <stack>
#include <cstdlib>
#include <set>
#include <string>
#include <vector>
#include <cmath>
#define MAX 100005

using namespace std;


int a[1005],b[1005];

bool cmp( int x, int y ){
	return a[x] < a[y];
}

int go(){
	int n ;
	scanf("%d",&n);
	for( int i = 0; i < n; i++) {
		scanf("%d",a+i);
		b[i] = i;
	}
	int ans = 0;
	int ini = 0, fin = n - 1;
	for( int i = 0; i < n; i++){
		sort( b , b + n, cmp );
		if ( b[i] - ini < fin - b[i] ){
			for( int j = b[i] ; j > ini; j--){
				swap( a[j], a[j-1] );
				ans++;
			}
			ini++;
		}else{
			for( int j = b[i] ; j < fin ;j++){
				swap( a[j], a[j+1] );
				ans++;
			}	
			fin--;
		}
	}	
	return ans;
}

int main(){

	int cases;
	scanf("%d",&cases);
	for( int t = 1; t <= cases; t++){
		printf("Case #%d: %d\n",t,go());
	}

	return 0;
}
