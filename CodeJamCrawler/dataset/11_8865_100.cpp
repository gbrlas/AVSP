#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

void handlecase(){
  int n;
  scanf("%d",&n);
  int ol=1,ot=0,bl=1,bt=0;
  for(int i=0;i<n;i++){
    char color[2];
    int loc;
    scanf("%s %d",color,&loc);
    if(color[0]=='O'){
      int tp=abs(loc-ol)+1;
      ot=max(ot+tp,bt+1);
      ol=loc;
    } else if (color[0]=='B'){
      int tp=abs(loc-bl)+1;
      bt=max(bt+tp,ot+1);
      bl=loc;
    }
                  //printf("%d %d %d %d\n",ot,ol,bt,bl);
  }
  printf("%d\n",max(ot,bt));
}

int main(){
  freopen("E:\\A-small-attempt0.in","r",stdin);
  freopen("E:\\A-small-attempt0.out","w",stdout);
  int t;
  scanf("%d",&t);
  for(int i=1;i<=t;i++){
    printf("Case #%d: ",i);
    handlecase();
  }
  return 0;
}
