#include<stdio.h>
#include<string.h>

#define maxn 2000

int r,k,n,i,j;

int p[maxn];

int q[maxn];

__int64 qq[maxn];

__int64 ans,now,sum;

int main(){
	freopen("C-small-attempt0.in","r",stdin);
	freopen("b.txt","w",stdout);
	int ii,nn;
	scanf("%d",&nn);
	for(ii=1;ii<=nn;ii++){
		printf("Case #%d: ",ii);
		
		scanf("%d %d %d",&r,&k,&n);
		now=0;
		for(i=1;i<=n;i++){
			scanf("%d",&p[i]);
			now+=p[i];
		}
		if(k>=now){
			printf("%I64d\n",r*now);
			continue;
		}
		sum=0;
		memset(q,0,sizeof(q));
		memset(qq,0,sizeof(qq));
		i=1;
		j=1;
		while(i<=r){
			if(q[j])break;
			q[j]=i;
			qq[j]=sum;
			now=0;
			while(now+p[j]<=k){
				now+=p[j];
				j++;
				if(j>n)j=1;
			}
			sum+=now;
			i++;
		}
		if(i>r){
			printf("%I64d\n",sum);
			continue;
		}
		ans=qq[j];
		r-=q[j]-1;
		if(r>=i-q[j]){
			ans+=(sum-qq[j])*(r/(i-q[j]));
			r%=(i-q[j]);
		}
		i=1;
		while(i<=r){
			now=0;
			while(now+p[j]<=k){
				now+=p[j];
				j++;
				if(j>n)j=1;
			}
			ans+=now;
			i++;
		}
		printf("%I64d\n",ans);
	}

	return 0;
}