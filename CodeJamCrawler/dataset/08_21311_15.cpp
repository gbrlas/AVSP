#include <cstdio>
#include <string>
using namespace std;

const int MAXN = 1024 ; 

int casenum, n, a[MAXN], b[MAXN] ; 
long long ans ; 

int main(){
	int i,j,ca ; 
	freopen("A-large.in","r",stdin);
	freopen("a_out_large.txt","w",stdout);
	scanf("%d",&casenum);
	for(ca = 1 ; ca <= casenum ; ca++){
		scanf("%d",&n);
		for(i = 0 ; i < n ; i++) scanf("%d",&a[i]);
		for(i = 0 ; i < n ; i++) scanf("%d",&b[i]);
		sort(a,a+n);
		sort(b,b+n) ; 
		ans = 0  ;
		for(i = 0 , j = n - 1 ; i < n && j >= 0 ; i++, j--)
			ans += (long long)a[i] * b[j] ; 
		printf("Case #%d: %I64d\n", ca, ans);
	}	
	return 0;
}
