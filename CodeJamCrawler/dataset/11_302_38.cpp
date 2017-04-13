#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;

const double eps=1e-8;

int x,s,run,T,n,l,r,tot,sp;
double t,ans,tmp;

struct data
{
	int x,y,z;
};

data f[2000];

bool cmp(const data &a,const data &b)
{
	return (a.z<b.z);
}

int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	int w=0,ww; cin>>ww;
	while (++w<=ww) {
		tot=-1;
		cin>>x>>s>>run>>T>>n;
		t=double(T); 
		cin>>l>>r>>sp;
		if (l>0) {
			f[++tot].x=0; f[tot].y=l; f[tot].z=0;
		}
		f[++tot].x=l; f[tot].y=r; f[tot].z=sp;
		for (int i=1; i<n; i++) {
			cin>>l>>r>>sp;
			if (l>f[tot].y) {
				f[++tot].x=f[tot-1].y; f[tot].y=l; f[tot].z=0;
			}
			f[++tot].x=l; f[tot].y=r; f[tot].z=sp;
		}
		if (f[tot].y!=x) {
			f[++tot].x=f[tot-1].y; f[tot].y=x; f[tot].z=0;
		}
		sort(f,f+tot+1,cmp);
		ans=0.0;
		for (int i=0; i<=tot; i++) {
			tmp=double(f[i].y-f[i].x) /	(f[i].z+run);
			if (t-tmp>=eps) {
				ans+=tmp; t-=tmp;
			} else {
				if (t>eps) {
					tmp=double(f[i].y-f[i].x)-t*(double(f[i].z+run));
					ans+=t; t=0.0; 
					ans+=tmp/(f[i].z+s);
				} else {
					tmp=double(f[i].y-f[i].x) / (f[i].z+s);
					ans+=tmp;
				}
			}
		}
		printf("Case #%d: ",w);

		printf("%.7f\n",ans);
	}
	return 0;
}
