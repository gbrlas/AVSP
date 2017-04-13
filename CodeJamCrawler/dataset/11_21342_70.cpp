#include <cstdio>
#include <algorithm>

using namespace std;

int n,f1,f2,p1,p2;

int main(){
	int test;
	scanf("%d",&test);
	for ( int t=0; t<test; ++t ){
		printf("Case #%d: ",t+1);
		scanf("%d",&n);
		int ans=0;
		f1=f2=0;p1=p2=1;
		for ( int i=0; i<n; ++i ){
			char c;
			int x;
			scanf(" %c %d", &c,&x);
			if ( c=='B' ){
				f2=max(ans+1,f2+(1+abs(x-p2)));
				p2=x;
				ans=f2;
			} else {
				f1=max(ans+1,f1+(1+abs(x-p1)));
				p1=x;
				ans=f1;
			}
		}
		printf("%d\n",ans);
	}
}
