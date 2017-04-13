#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;

int big[1001];
int small[1001];

void init(){
  bool isprime[1001];
  fill(isprime+2,isprime+1000,true);
  for(int i=2;i<=1000;i++){
    if(isprime[i]){
      for(int k=i*2;k<=1000;k+=i){
        isprime[k]=false;
      }
    }
  }
  //small
  small[1]=1;
  small[2]=1;
  for(int i=3;i<=1000;i++){
    small[i]=small[i-1]+isprime[i];
  }
  //big
  bool isprimek[1001];
  fill(isprimek+2,isprimek+1000,false);
  for(int i=2;i<=1000;i++){
    if(isprime[i]){
      for(int k=i;k<=1000;k*=i){
        isprimek[k]=true;
      }
    }
  }
  big[1]=1;
  for(int i=2;i<=1000;i++){
    big[i]=big[i-1]+isprimek[i];
  }
}

void handlecase(){
  int n;
  scanf("%d",&n);
  printf("%d\n",big[n]-small[n]);
}

int main(){
  freopen("E:\\C-small-attempt0.in","r",stdin);
  freopen("E:\\C-small-attempt0.out","w",stdout);
  init();
  
  int t;
  scanf("%d",&t);
  for(int i=1;i<=t;i++){
    printf("Case #%d: ",i);
    handlecase();
  }
  return 0;
}
