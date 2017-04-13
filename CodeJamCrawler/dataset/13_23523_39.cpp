#include<stdio.h>
#include<queue>
int tcn,tc;
long long int mod=1000002013;
long long int a[1010][3];
long long int tmp[1010][3];
long long int ans;
int n;
int m;
struct nodea{
	long long int start;
	long long int pnum;
	bool operator<(const nodea& r)const{
		return start<r.start;
	}
};
struct nodeb{
	long long int end;
	long long int pnum;
	bool operator<(const nodeb& r)const{
		return end>r.end;
	}
};
std::priority_queue<nodea> p;
std::priority_queue<nodeb> q;
void sort(int start,int end){
	if(end-start<2)return;
	int mid=(start+end)/2;
	sort(start,mid);
	sort(mid,end);
	int i,j,k;
	i=start;
	j=mid;
	k=start;
	for(;i<mid&&j<end;k++){
		if(a[i][0]<a[j][0]||(a[i][0]==a[j][0]&&a[i][1]<a[j][1])){
			tmp[k][0]=a[i][0];
			tmp[k][1]=a[i][1];
			tmp[k][2]=a[i][2];
			i++;
		}
		else{
			tmp[k][0]=a[j][0];
			tmp[k][1]=a[j][1];
			tmp[k][2]=a[j][2];
			j++;
		}
	}
	for(;i<mid;k++){
		tmp[k][0]=a[i][0];
		tmp[k][1]=a[i][1];
		tmp[k][2]=a[i][2];
		i++;
	}
	for(i=start;i<k;i++){
		a[i][0]=tmp[i][0];
		a[i][1]=tmp[i][1];
		a[i][2]=tmp[i][2];
	}
}
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int i;
	nodea x;
	nodeb y;
	scanf("%d",&tcn);
	for(tc=1;tc<=tcn;tc++){
		ans=0;
		scanf("%d%d",&n,&m);
		for(i=0;i<m;i++){
			scanf("%lld%lld%lld",&a[i][0],&a[i][1],&a[i][2]);
		}
		sort(0,m);
		for(i=0;i<m;i++){
			ans+=mod;
			ans-=((((a[i][1]-a[i][0])*(a[i][1]-a[i][0]-1)/2)%mod)*a[i][2])%mod;
			ans%=mod;
		}
		for(i=0;i<m;i++){
			while(!q.empty()&&q.top().end<a[i][0]){
				y=q.top();
				q.pop();
				while(y.pnum!=0){
					x=p.top();
					p.pop();
					if(y.pnum>=x.pnum){
						ans+=((((y.end-x.start)*(y.end-x.start-1)/2)%mod)*x.pnum)%mod;
						ans%=mod;
						y.pnum-=x.pnum;
					}
					else{
						ans+=((((y.end-x.start)*(y.end-x.start-1)/2)%mod)*y.pnum)%mod;
						ans%=mod;
						x.pnum-=y.pnum;
						y.pnum=0;
						p.push(x);
					}
				}
			}
			x.start=a[i][0];
			x.pnum=a[i][2];
			p.push(x);
			y.end=a[i][1];
			y.pnum=a[i][2];
			q.push(y);
		}
		while(!q.empty()){
			y=q.top();
			q.pop();
			while(y.pnum!=0){
				x=p.top();
				p.pop();
				if(y.pnum>=x.pnum){
					ans+=((((y.end-x.start)*(y.end-x.start-1)/2)%mod)*x.pnum)%mod;
					ans%=mod;
					y.pnum-=x.pnum;
				}
				else{
					ans+=((((y.end-x.start)*(y.end-x.start-1)/2)%mod)*y.pnum)%mod;
					ans%=mod;
					x.pnum-=y.pnum;
					y.pnum=0;
					p.push(x);
				}
			}
		}
		while(!p.empty())p.pop();
		while(!q.empty())q.pop();
		printf("Case #%d: %lld\n",tc,ans);
	}
}