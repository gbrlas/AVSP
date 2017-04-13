#include <iostream>
#include <vector>

#define vi vector<int>
#define PB push_back

using namespace std;

int maxx;
int badans;

void solve(vi v, int i, int sean, int patrik, int val){
  if(i >= (int)v.size()){
    if(sean == patrik && val > maxx && val != badans)maxx = val;
    return;
  }
  solve(v, i+1, sean ^ v[i], patrik, val + v[i]);
  solve(v, i+1, sean, patrik ^ v[i], val);
  return;
}

int main(void){
  int T, N, tmp;
  vi vec;
  cin >> T;
  for(int i = 0; i < T; i++){
    vec = vi(0);
    cin >> N;
    for(int j = 0; j < N; j++){
      cin >> tmp;
      vec.PB(tmp);
    }
    maxx = -1;
    badans = 0;
    for(int j = 0; j < (int)vec.size(); j++){
      badans += vec[j];
    }
    solve(vec, 0, 0, 0, 0);
    cout << "Case #" << (i+1) << ": ";
    if(maxx < 0)cout << "NO" << endl;
    else cout << maxx << endl;
  }
  return 0;
}
