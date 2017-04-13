#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair <char, int> ci;
vector <ci> list;
vector <int> list_O, list_B;

int main(){
  int T;
  scanf("%d\n", &T);
  for(int test_num = 1; test_num <=T; test_num++){
    list.clear();
    list_O.clear(); list_B.clear();
    int ans = 0;
    int n;
    scanf("%d\n", &n);
    for(int i=0; i<n; i++){
      char t1; int t2;
      scanf("%c %d\n", &t1, &t2);
      list.push_back( ci(t1, t2) );
      if(t1 == 'O') list_O.push_back( t2 );
      else list_B.push_back( t2 );
    }
    int pos1 = 1, pos2 = 1;
    int idx1 = 0, idx2 = 0;
    for(int i=0; i<n; i++){
      if(list[i].first == 'O'){
        int duration = abs(list[i].second - pos1);
        ans += duration;
        ans ++; duration++;
        if(idx2 < list_B.size()){
          if(pos2 > list_B[idx2]) {
            if(duration >= abs(list_B[idx2] - pos2)){
              pos2 = list_B[idx2];
            }
            else{
              pos2 -= duration;
            }
          }
          else{
            if(duration >= abs(list_B[idx2] - pos2)){
              pos2 = list_B[idx2];
            }
            else{
              pos2 += duration;
            }
          }
        }
        pos1 = list[i].second;
        idx1++;
      }
      else{
        int duration = abs(list[i].second - pos2);
        ans += duration;
        ans ++; duration++;
        if(idx1 < list_O.size()){
          if(pos1 > list_O[idx1]) {
            if(duration >= abs(list_O[idx1] - pos1)){
              pos1 = list_O[idx1];
            }
            else{
              pos1 -= duration;
            }
          }
          else{
            if(duration >= abs(list_O[idx1] - pos1)){
              pos1 = list_O[idx1];
            }
            else{
              pos1 += duration;
            }
          }
        }
        pos2 = list[i].second;
        idx2++;
      }
    }
    printf("Case #%d: %d\n",test_num, ans);
  }
  return 0;
}
