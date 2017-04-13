#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;

const int N=(int)1e6+1;

int isprime[N+1];

void init(){
  fill(isprime,isprime+N+1,true);
  for(int i=2;i<=N;i++){
    if(isprime[i]){
      for(int k=i*2;k<=N;k+=i){
        isprime[k]=false;
      }
    }
  }
}

void handlecase(){
  long long n;
  scanf("%lld",&n);
  if(n==1){
    printf("%d\n",0);
  } else {
    int num=0;
    for(int i=2;i<=N;i++){
      if(isprime[i]){
        for(long long k=i;k<=n/i;k*=i){
          num++;
                  //printf("%d %d\n",k,num);
        }
      }
    }
    printf("%d\n",num+1);
  }
}

int main(){
  freopen("E:\\C-large.in","r",stdin);
  freopen("E:\\C-large.out","w",stdout);
  init();
  
  int t;
  scanf("%d",&t);
  for(int i=1;i<=t;i++){
    printf("Case #%d: ",i);
    handlecase();
  }
  return 0;
}
