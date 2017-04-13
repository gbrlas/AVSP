#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;

int h[30];

int i,j,n,m;

int p[10000];

int one[10000];

int q[30];

int one1(int a){
	int last=-1,i,ans=0;
	for(i=0;i<n;i++){
		if(h[i]&a){
			ans++;
			if(last<0||last+1==q[i])
				last=q[i];
			else
				return 0;
		}
	}
	return ans;
}

int mymin(int a,int b){
	if(a*b==0)
		return a+b;
	return a<b?a:b;
}

int make(int a){
	if(a==0)
		return 0;
	if(p[a])
		return p[a];
	int i,ans=-1,temp;
	for(i=1;i<h[n];i++)if((i&a)==i){
		if(one[i]){
			temp=mymin(make(i^a),one[i]);
			if(ans<0||temp>ans)
				ans=temp;
		}
	}
	p[a]=ans;
	return p[a];
}


int main(){
	h[0]=1;
	for(i=1;i<30;i++)
		h[i]=h[i-1]*2;
	int ii,nn;
	scanf("%d",&nn);
	for(ii=1;ii<=nn;ii++){
		printf("Case #%d: ",ii);
		scanf("%d",&n);
		memset(one,0,sizeof(one));
		memset(p,0,sizeof(p));
		for(i=0;i<n;i++){
			scanf("%d",&q[i]);
		}
		sort(q,q+n);
		for(i=1;i<h[n];i++){
			one[i]=one1(i);
		}
		printf("%d\n",make(h[n]-1));
	}
	return 0;
}

