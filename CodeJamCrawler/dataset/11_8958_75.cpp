#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;

long long gcd(long long a,long long b){
  if(a<b){
    swap(a,b);
  }
  while(b!=0){
    long long tmp=a%b;
    a=b;
    b=tmp;
  }
  return a;
}

void handlecase(){
  int n;
  long long l,h;
  scanf("%d%lld%lld",&n,&l,&h);
  long long fres[10000];
  for(int i=0;i<n;i++){
    scanf("%lld",&fres[i]);
  }
  long long ad_fre;
  sort(fres,fres+n,greater<long long>());

//判断是否可能是最大数的约数
  int i=0;
  long long n_gcd;
  bool pos_div=true;
  long long ans;
  n_gcd=fres[0];
  for(i=1;i<n&&fres[i]>h;i++){
    n_gcd=gcd(n_gcd,fres[i]);
    if(n_gcd<l){
      pos_div=false;
      break;
    }
  }
  if(pos_div){
    long long dividers[10000];
    int dividern=0;
    for(;i<n;i++){
      if(n_gcd%fres[i]==0){
        if(fres[i]!=n_gcd){
          dividers[dividern]=fres[i];
          dividern++;
        }
      } else {
        for(int j=0;j<dividern;j++){
          n_gcd=gcd(n_gcd,dividers[j]);
        }
        n_gcd=gcd(n_gcd,fres[i]);
        if(n_gcd<l){
          pos_div=false;
          break;
        }
      }
    }
    if(pos_div){
      if(dividern==0){
        for(int j=n_gcd/l;n_gcd/j+1<=h;j--){
          if(n_gcd%j==0){
            ans=n_gcd/j;
            break;
          }
        }
      } else {
        long long d_lcm=dividers[0];
        for(int j=0;j<dividern;j++){
          d_lcm=d_lcm/gcd(d_lcm,dividers[j])*dividers[j];
        }
        pos_div=false;
        for(int j=(l-1)/d_lcm+1;d_lcm*j<=h;j++){
          if(n_gcd%(d_lcm*j)==0){
            ans=d_lcm*j;
            pos_div=true;
            break;
          }
        }
      }
    }
  }
  if(pos_div){
    printf("%lld\n",ans);
  } else {
    long long n_lcm=fres[0];
    long long pos=true;
    for(int i=1;i<n;i++){
      long long n_ngcd=gcd(n_lcm,fres[i]);
      if(n_lcm/n_ngcd>h/fres[i]+1){
        pos=false;
        break;
      } else {
        n_lcm=n_lcm/n_ngcd*fres[i];
      }
    }
    if(pos){
      int j=(l-1)/n_lcm+1;
      if(n_lcm*j<=h){
        printf("%lld\n",n_lcm*j);
      } else {
        printf("NO\n");
      }
    } else {
      printf("NO\n");
    }
  }
}

int main(){
  freopen("E:\\C-large.in","r",stdin);
  freopen("E:\\C-large.out","w",stdout);
  int t;
  scanf("%d",&t);
  for(int i=1;i<=t;i++){
    printf("Case #%d: ",i);
    handlecase();
  }
  return 0;
}
