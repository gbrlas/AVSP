#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
int a[1010];
int tot[10010];
int num[1010],tn;

int main(){
	int test=0;
	scanf("%d",&test);
	for ( int T=1; T<=test; ++T ){
		scanf("%d",&n);
		int ans=10000;
		if (n==0) ans=0;
		memset(tot,0,sizeof(tot));
		for ( int i=0; i<n; ++i ){
			scanf("%d",&a[i]);
			++tot[a[i]];
		}
		memset(num,0,sizeof(num));
		tn=0;
		for ( int now=0; now<=10000; ++now ){
			if ( tn )
				sort(num,num+tn);
			for ( int i=0; i<min(tot[now],tn); ++i )
				++num[i];
			if ( tn>tot[now] )
				for ( int i=tot[now]; i<tn; ++i )
					ans=min(ans,num[i]);
			else
				for ( int i=tn; i<tot[now]; ++i )
					num[i]=1;
			tn=tot[now];
		}
		for ( int i=0; i<tn; ++i )
			ans=min(ans,num[i]);
		printf("Case #%d: %d\n", T,ans);
	}
}
