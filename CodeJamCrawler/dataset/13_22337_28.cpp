#include <cstdio>
#include <algorithm>

using namespace std;

struct data{
	int x,kd;
	int p;
	bool operator <(const data &b) const{
		return x<b.x || x==b.x && kd<b.kd;
	}
};

const int mod=1000002013;

int n,m;
data a[2010];
int ret;
int st[2010],p[2010];
int tots;

int main(){
	int test=0;
	scanf("%d", &test);
	for (int T=1; T<=test; ++T){
		scanf("%d%d",&n,&m);
		int tot=0;
		long long ret=0;
		for (int i=0; i<m; ++i){
			int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			long long tmp=(y-x);
			tmp=tmp*(tmp-1)/2%mod;
			ret=(ret-tmp*z%mod)%mod;
			a[tot].x=x;a[tot].p=z;a[tot].kd=0;++tot;
			a[tot].x=y;a[tot].p=z;a[tot].kd=1;++tot;
		}
		sort(a,a+tot);
		tots=0;
		for (int i=0; i<m*2; ++i)
			if (a[i].kd==0){
				st[++tots]=a[i].p;
				p[tots]=a[i].x;
			} else {
				int t=a[i].p;
				while (t>0){
					int use=min(t,st[tots]);
					long long tmp=a[i].x-p[tots];
					tmp=tmp*(tmp-1)/2%mod;
					tmp=tmp*use%mod;
					ret=(ret+tmp)%mod;
					t-=use; st[tots]-=use;
					if (st[tots]==0) --tots;
				}
			}
		printf("Case #%d: %d\n", T,ret);
	}
}
