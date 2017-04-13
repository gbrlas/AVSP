#include<iostream>
#include<vector>
#include<algorithm>
#include<iso646.h>

using namespace std;

void print(vector<int> l){
  for (int i = 0; i < l.size(); i++){
    cout << l[i] << " ";
  }
}
int main(){
  int times;
  int v = 1;
  cin >> times;
  while(times--){
  int size;
  int candy;
  int res = 0;
  cin >> size;
  vector<int> candys;
  for(int i = 0; i < size; i++){
    cin >> candy;
    candys.push_back(candy);
  }
  sort(candys.begin(), candys.end());

  for (int j = 0; j < candys.size(); j++){
    res = res ^ candys[j];
  }

  if (res == 0){
    int sum = 0;
    for (int k = candys.size() -1 ; k >= 1; k--){
      sum += candys[k];
    }
    cout << "Case #"<< v << ": "<< sum << endl;
  }else{
    cout << "Case #" << v << ": " << "NO" << endl;
  }
    v++;
 }
  return 0;
}
