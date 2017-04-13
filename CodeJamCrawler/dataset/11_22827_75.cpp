#include<cstdio>
#include<algorithm>
#include<climits>
using namespace std;

const int inf = INT_MAX;

int main(){
  int t;
  scanf(" %d", &t);
  for(int cc = 0; cc < t; ++cc){
    int n;
    scanf(" %d", &n);
    int a = 0, b = inf, c = 0;
    for(int i = 0; i < n; ++i){
      int input;
      scanf(" %d", &input);
      a = a ^ input;
      b = min(b, input);
      c += input;
    }
    if(a == 0){
      printf("Case #%d: %d\n", cc + 1, c - b);
    }else{
      printf("Case #%d: NO\n", cc + 1);
    }
  }
  return 0;
}
