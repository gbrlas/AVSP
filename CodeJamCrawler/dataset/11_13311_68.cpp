#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define maxn 10000
int i,j,n,m;

int p[maxn];

int makeMin(){
  if(n==1)
    return 1;
  int temp,ans=0;
  memset(p,0,sizeof(p));
  for(i=2;i<=n;i++){
    temp=i;
    for(j=2;j*j<=temp;j++){
      if(temp%j==0){
	p[j]=1;
	while(temp%j==0){
	  temp/=j;
	}
      }
    }
    p[temp]=1;
  }
  for(i=2;i<=n;i++){
    if(p[i])
      ans++;
  }
  return ans;
}

int makeMax(){
  int temp,ans=1,dome;
  memset(p,0,sizeof(p));
  bool o;
  for(i=2;i<=n;i++){
    o=0;
    temp=i;
    for(j=2;j*j<=temp;j++){
      if(temp%j==0){
	dome=0;
	while(temp%j==0){
	  temp/=j;
	  dome++;
	}
	if(dome>p[j]){
	  o=1;
	  p[j]=dome;
	}
      }
    }
    if(temp>1){
      if(p[temp]==0){
	p[temp]=1;
	o=1;
      }
    }
    if(o)
      ans++;
  }

  return ans;
}

int main(){
  int ii,nn;
  scanf("%d",&nn);
  for(ii=1;ii<=nn;ii++){
    printf("Case #%d: ",ii);
    scanf("%d",&n);
    //    printf("%d %d\n",makeMax(),makeMin());
    printf("%d\n",makeMax()-makeMin());
  }
  return 0;
}
