#include <cstdio>

using namespace std;

void handlecase(){
  int n;
  scanf("%d",&n);
  int dsum=0,sum=0,min=10000000;
  for(int i=0;i<n;i++){
    int num;
    scanf("%d",&num);
    dsum=dsum^num;
    sum+=num;
    if(num<min){
      min=num;
    }
  }
  if(dsum!=0){
    printf("NO\n");
  } else {
    printf("%d\n",sum-min);
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
