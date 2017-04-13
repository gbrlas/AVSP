#include <cstdio>
#include <algorithm>

using namespace std;
int main(){
  int T;
  scanf("%d", &T);
  for(int test_num=1; test_num <= T; test_num++){
    int n;
    scanf("%d", &n);
    int a[1111];
    for(int i=0; i<n; i++){
      scanf("%d", &a[i]);
    }

    int ans = -1;
    for(int i=0; i<(1<<n); i++){
      int add1 = 0, add2 = 0;
      int num1 = 0, num2 = 0;
      int real_add1 = 0, real_add2 = 0;
      for(int j=0; j<n; j++){
        if( ((1<<j)&(i)) != 0){
          add1 = add1^a[j];
          real_add1 += a[j];
          num1++;
        }
        else{
          add2 = add2^a[j];
          real_add2 += a[j];
          num2++;
        }
      }
      if(add1 == add2 && num1 > 0 && num2 > 0){
        ans = max(ans, max(real_add1, real_add2));
      }
    }
    if(ans==-1) printf("Case #%d: NO\n", test_num);
    else        printf("Case #%d: %d\n", test_num, ans);
  }
  return 0;
}
