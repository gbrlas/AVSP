#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
  int t;
  scanf(" %d", &t);
  for(int cc = 0; cc < t; ++cc){
    int n;
    scanf(" %d", &n);
    vector<int> arr1, arr2;
    for(int i = 0; i < n; ++i){
      int input;
      scanf(" %d", &input);
      arr1.push_back(input);
      arr2.push_back(input);
    }
    sort(arr2.begin(), arr2.end());
    int cnt = 0;
    for(int i = 0; i < n; ++i){
      if(arr1[i] != arr2[i])++cnt;
    }
    printf("Case #%d: %d.000000\n", cc + 1, cnt);
  }
  return 0;
}
