#include<stdio.h>
#include<string.h>
#define maxn 300

int last[maxn];

bool p[maxn][maxn];

int q[maxn][2];

int i,j,n,m;

bool checked[maxn];

int gettime(int a,int b){return a*60+b;}

int findit(int a){
	int i,q;
	for(i=1;i<=n;i++)if(!checked[i]&&p[a][i]){
		checked[i]=1;
		q=last[i];
		last[i]=a;
		if(q==0)return 1;
		if(findit(q))return 1;
		last[i]=q;
	}	
	return 0;
}

inline void make(){
	for(i=1;i<=n;i++){
		memset(checked,0,sizeof(checked));
		findit(i);
	}
}

int main(){
	int ii,nn;
	scanf("%d",&nn);
	int a,b,c,d;
	for(ii=1;ii<=nn;ii++){
		printf("Case #%d: ",ii);
		n=0;
		scanf("%d",&m);
		scanf("%d %d",&a,&b);
		while(a--){
			n++;
			scanf("%d:%d",&c,&d);
			q[n][0]=gettime(c,d);
			scanf("%d:%d",&c,&d);
			q[n][1]=gettime(c,d);
		}
		a=n;
		while(b--){
			n++;
			scanf("%d:%d",&c,&d);
			q[n][0]=gettime(c,d);
			scanf("%d:%d",&c,&d);
			q[n][1]=gettime(c,d);
		}
		memset(p,0,sizeof(p));
		for(i=1;i<=a;i++)for(j=a+1;j<=n;j++){
			if(q[i][1]+m<=q[j][0])p[i][j]=1;
			if(q[j][1]+m<=q[i][0])p[j][i]=1;
		}
		memset(last,0,sizeof(last));
		make();
		c=d=0;
		for(i=1;i<=a;i++)if(!last[i])c++;
		for(i=a+1;i<=n;i++)if(!last[i])d++;
		printf("%d %d\n",c,d);
	}
	return 0;
}