#include<stdio.h>
#include<string.h>

#define maxn 11

double p[maxn],mul[maxn],C[maxn][maxn];

double nowAns=0;

int i,j,n,m;
int nowLeft=0;

void dfs(int a,int last,double m,double sum,int c){
  int i;
  if(a==0){
    nowAns+=sum*m;
    return;
  }
  if(c==1){
    for(i=a-1;i;i--){
      dfs(a-i,a-1,m*C[a-1][i-1]*mul[i-1],sum+p[i+nowLeft],c+1);
    }
  }else
  for(i=last;i;i--){
    if(a>=i){
      dfs(a-i,last,m*C[a-1][i-1]*mul[i-1],sum+p[i],c+1);
    }
  }
}
void dfs2(int a,int last,double m,double sum){
  int i;
  if(a==0){
    nowAns+=sum*m;
    return;
  }
  for(i=last;i;i--){
    if(a>=i){
      dfs2(a-i,last,m*C[a-1][i-1]*mul[i-1],sum+p[i]);
    }
  }
}

inline void prepare(){
  int i,j;
  for(i=2;i<maxn;i++){
    nowAns=0;
    dfs2(i,i-1,1,0);
    nowAns+=mul[i];
    nowAns/=(mul[i]-mul[i-1]);
    p[i]=nowAns;
    for(j=1;j<i;j++){
      nowLeft=i-j;
      nowAns=0;
      dfs(j,j,1,0,1);
      nowAns+=mul[j];
      nowAns/=(mul[j]-mul[j-1]);
      if(nowAns<p[i])
	p[i]=nowAns;
    }
    //    printf("%lf\n",p[i]);
  }
}

bool checked[maxn];

int q[maxn];

int main(){
  p[2]=2;
  mul[0]=mul[1]=1;
  for(i=2;i<maxn;i++)
    mul[i]=i*mul[i-1];
  C[0][0]=1;
  for(i=1;i<maxn;i++){
    C[i][0]=1;
    for(j=1;j<maxn;j++){
      C[i][j]=C[i-1][j]+C[i-1][j-1];
    }
  }
  prepare();

  int ii,nn;
  double ans;
  scanf("%d",&nn);
  for(ii=1;ii<=nn;ii++){
    printf("Case #%d: ",ii);
    scanf("%d",&n);
    for(i=1;i<=n;i++){
      scanf("%d",&q[i]);
      checked[i]=0;
    }
    ans=0;
    for(i=1;i<=n;i++){
      if(!checked[i]){
	int r=0;
	j=i;
	while(!checked[j]){
	  checked[j]=1;
	  j=q[j];
	  r++;
	}
	ans+=p[r];
      }
    }
    printf("%.8lf\n",ans);
  }
  return 0;
}
