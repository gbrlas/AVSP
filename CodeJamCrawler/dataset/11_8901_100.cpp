#include <cstdio>
#include <algorithm>
using namespace std;

void handlecase(){
  int n;
  scanf("%d",&n);
  int nums[1000],sort_nums[1000];
  for(int i=0;i<n;i++){
    scanf("%d",&nums[i]);
    sort_nums[i]=nums[i];
  }
  sort(sort_nums,sort_nums+n);
  int wrarrn=0;
  for(int i=0;i<n;i++){
    if(nums[i]!=sort_nums[i]){
      wrarrn++;
    }
  }
  printf("%.6lf\n",wrarrn*1.0);
}

int main(){
  freopen("E:\\D-small-attempt0.in","r",stdin);
  freopen("E:\\D-small-attempt0.out","w",stdout);
  int t;
  scanf("%d",&t);
  for(int i=1;i<=t;i++){
    printf("Case #%d: ",i);
    handlecase();
  }
  return 0;
}
