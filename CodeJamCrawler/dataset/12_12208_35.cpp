#include<stdio.h>
#include<algorithm>
using namespace std;

int tqn,tqi,ps[111111],ax[111111],ay[111111],i,j,cx,cy,n,w,h;
pair<int,int>a[111111];

int touch(int q1,int q2,int l1,int l2){
	if(q2<l1||q1>l2)return 0;else return 1;
}

int findhei(int yy1,int yy2){
	int ret=-1000000000;
	for(j=1;j<i;j++)if(touch(ay[j]-a[j].first,ay[j]+a[j].first,yy1,yy2))ret=max(ret,a[j].first+ax[j]);
	return max(0,ret+a[i].first);
}

int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	scanf("%d",&tqn);
	for(tqi=0;tqi<tqn;tqi++){
		scanf("%d%d%d",&n,&w,&h);
		for(i=1;i<=n;i++){
			scanf("%d",&a[i].first);
			a[i].second=i;
		}
		sort(a+1,a+n+1);
//		reverse(a+1,a+n+1);
		for(i=1;i<=n;i++)ps[a[i].second]=i;
		cy=0;
		for(i=1;i<=n;i++){
			cx=findhei(cy-a[i].first+1,cy+a[i].first-1);
			ax[i]=cx,ay[i]=cy;
			cy+=a[i].first+a[i+1].first;
			if(cy>h)cy=0;
			assert(ax[i]<=w/*&&ay[i]<=h*/);
		}
		for(i=1;i<=n;i++)for(j=i+1;j<=n;j++)if(max(abs(ax[i]-ax[j]),abs(ay[i]-ay[j]))<a[i].first+a[j].first){
			printf("%d\n",tqi);
			return 0;
		}
		printf("Case #%d:",tqi+1);
		for(i=1;i<=n;i++)printf(" %d %d",ax[ps[i]],ay[ps[i]]);
		puts("");
	}
	return 0;
}