#include <cstdio>
#include <algorithm>
using namespace std;

void handlecase(){
  int n,l,h;
  scanf("%d%d%d",&n,&l,&h);
  int fres[1000];
  for(int i=0;i<n;i++){
    scanf("%d",&fres[i]);
  }
  int ans=0;
  for(int i=l;i<=h;i++){
    bool possible=true;
    for(int j=0;j<n;j++){
      if(i%fres[j]!=0 && fres[j]%i!=0){
        possible=false;
        break;
      }
    }
    if(possible){
      ans=i;
      break;
    }
  }
  if(ans>0){
    printf("%d\n",ans);
  } else {
    printf("NO\n");
  }
}

int main(){
  freopen("E:\\C-small-attempt0.in","r",stdin);
  freopen("E:\\C-small-attempt0.out","w",stdout);
  int t;
  scanf("%d",&t);
  for(int i=1;i<=t;i++){
    printf("Case #%d: ",i);
    handlecase();
  }
  return 0;
}
