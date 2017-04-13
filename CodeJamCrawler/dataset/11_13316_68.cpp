#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define maxn 2000000
int i,j;

long long int n;

int p[maxn],q[maxn],t;

void prepare(){
  for(i=2;i<maxn;i++){
    if(!p[i]){
      q[++t]=i;
      if(double(i)*i+1e-5<maxn)
	for(j=i*i;j<maxn;j+=i){
	  p[j]=1;
	}
    }
  }
}


int main(){
  prepare();
  int ii,nn;
  scanf("%d",&nn);
  long long int temp;
  for(ii=1;ii<=nn;ii++){
    printf("Case #%d: ",ii);
    scanf("%lld",&n);
    int ans=0;
    for(i=1;i<t;i++){
      temp=q[i];
      temp*=q[i];
      if(temp<=n){
	while(temp<=n){
	  ans++;
	  temp*=q[i];
	}
      }
    }
    if(n>1)
      ans++;
    printf("%d\n",ans);
  }
  return 0;
}
