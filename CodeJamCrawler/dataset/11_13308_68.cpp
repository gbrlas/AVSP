#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define maxn 510

#define eps 1e-2

int p[maxn][maxn],sum[maxn][maxn];

struct point{
  double a,b;
  void add(point& now){
    a+=now.a;
    b+=now.b;
  }
  void sub(point& now){
    a-=now.a;
    b-=now.b;
  }
  
  void makeout(double aa,double bb,double c){
    a=aa*c;b=bb*c;
  }
}q[maxn][maxn],sq[maxn][maxn];

point getSum(int a,int b,int k){
  point ans=sq[a+k][b+k];
  ans.sub(sq[a+k][b-1]);
  ans.sub(sq[a-1][b+k]);
  ans.add(sq[a-1][b-1]);
  ans.sub(q[a][b]);
  ans.sub(q[a][b+k]);
  ans.sub(q[a+k][b]);
  ans.sub(q[a+k][b+k]);
  return ans;
}

double getSum2(int a,int b,int k){
  int ans= sum[a+k][b+k]-sum[a-1][b+k]-sum[a+k][b-1]+sum[a-1][b-1];
  ans-=p[a][b]+p[a+k][b]+p[a][b+k]+p[a+k][b+k];
  return ans;
}


int i,j,n,m,d,k=0;

inline void prepare(){
  for(i=1;i<=n;i++){
    for(j=1;j<=m;j++){
      q[i][j].makeout(i-0.5,j-0.5,p[i][j]);
      sq[i][j]=sq[i-1][j];
      sq[i][j].add(sq[i][j-1]);
      sq[i][j].sub(sq[i-1][j-1]);
      sq[i][j].add(q[i][j]);
      sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+p[i][j];
    }
  }
}

bool zero(double a){
  if(a<0)a=-a;
  return a<eps;
}

bool make1(){
  point temp,temp2;
  for(i=1;i<=n-k+1;i++){
    for(j=1;j<=m-k+1;j++){
      temp=getSum(i,j,k-1);
      temp2.makeout(i+k/2-0.5,j+k/2-0.5,getSum2(i,j,k-1));
      temp.sub(temp2);
      // if(i==2&&j==2){
      // 	printf("%lf %lf %d %d %d\n",temp.a,temp.b,k,n,m);
      // }
      if(zero(temp.a)&&zero(temp.b))
	return 1;
    }
  }
  return 0;
}
bool make2(){
  point temp,temp2;
  for(i=1;i<=n-k+1;i++){
    for(j=1;j<=m-k+1;j++){
      temp=getSum(i,j,k-1);
      temp2.makeout(i+k/2-1,j+k/2-1,getSum2(i,j,k-1));
      temp.sub(temp2);
      // if(i==2&&j==2){
      // 	printf("%lf %lf %d %d %d\n",temp.a,temp.b,k,n,m);
      // }
      if(zero(temp.a)&&zero(temp.b))
	return 1;
    }
  }
  return 0;
}

bool make(){
  if(k&1){
    return make1();
  }else
    return make2();
}


int main(){
  int ii,nn;
  scanf("%d",&nn);
  char aaa;
  for(ii=1;ii<=nn;ii++){
    printf("Case #%d: ",ii);
    scanf("%d %d %d",&n,&m,&d);
    for(i=1;i<=n;i++){
      for(j=1;j<=m;j++){
	scanf(" %c",&aaa);
	p[i][j]=aaa-'0';
      }
    }
    prepare();
    k=n;
    while(k>=3){
      if(make()){
	printf("%d\n",k);
	break;
      }
      k--;
    }
    if(k<3){
      printf("IMPOSSIBLE\n");
    }
  }
  return 0;
}
