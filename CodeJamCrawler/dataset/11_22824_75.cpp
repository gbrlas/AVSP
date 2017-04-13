#include<cstdio>
#include<algorithm>
#include<vector>
#include<utility>
using namespace std;

int sign(int a){
  if(a != 0) return a / abs(a);
  return 0;
}

int main(){
  int t;
  scanf(" %d", &t);
  for(int cc = 0; cc < t; ++cc){
    int n;
    scanf(" %d", &n);
    vector<pair<int, int> > prob[2];
    for(int i = 0; i < n; ++i){
      char c;
      int a;
      scanf(" %c %d", &c, &a);
      if(c == 'O'){
        prob[0].push_back(pair<int, int>(i, a));
      }else if(c == 'B'){
        prob[1].push_back(pair<int, int>(i, a));
      }
    }
    reverse(prob[0].begin(), prob[0].end());
    reverse(prob[1].begin(), prob[1].end());
    int pos[2] = {1, 1};
    int epos = 0;
    int step = 0;
    for(; epos < n; ++step){
      //printf("(%d, %d, %d, %d)\n", n, epos, pos[0], pos[1]);
      int d_epos = 0;
      if(!prob[0].empty()){
        if(pos[0] == prob[0].back().second){
          if(prob[0].back().first == epos){
            d_epos += 1;
            prob[0].pop_back();
          }
        }else{
          pos[0] += sign(prob[0].back().second - pos[0]);
        }
      }
      if(!prob[1].empty()){
        if(pos[1] == prob[1].back().second){
          if(prob[1].back().first == epos){
            d_epos += 1;
            prob[1].pop_back();
          }
        }else{
          pos[1] += sign(prob[1].back().second - pos[1]);
        }
      }
      epos += d_epos;
    }
    printf("Case #%d: %d\n", cc + 1, step);
  }
  return 0;
}
