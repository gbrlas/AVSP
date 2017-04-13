#include <cstdio>
#include <algorithm>
using namespace std;

int gcd(int a, int b){
  if(a<b){
    swap(a,b);
  }
  while(b>0){
    int tmp=a%b;
    a=b;
    b=tmp;
  }
  return a;
}

void handlecase(){
  long long n;
  int pd,pg;
  scanf("%lld%d%d",&n,&pd,&pg);
  if( 100/gcd(pd,100) <= n && ( pg!=100 && pg!=0 || (pg==100 && pd==100) || (pg==0 && pd==0) ) ){
    puts("Possible");
  } else {
    puts("Broken");
  }
}

int main(){
  freopen("E:\\A-small-attempt2.in","r",stdin);
  freopen("E:\\A-small-attempt2.out","w",stdout);
  int t;
  scanf("%d",&t);
  for(int i=1;i<=t;i++){
    printf("Case #%d: ",i);
    handlecase();
  }
  return 0;
}
