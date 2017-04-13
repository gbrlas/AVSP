#include <iostream>
#include <vector>
#include <algorithm>

#define vs vector<string>
#define PB push_back
using namespace std;

int opsesearch(int hd, string str, vs opse){
  char a, b, c, d;
  a = str[hd];
  for(int i = hd; i >= 0; i--){
    b = str[i];
    if(b == '|')continue;
    for(int j = 0; j < (int)opse.size(); j++){
      c = opse[j][0];
      d = opse[j][1];
      if((a == c && b == d) || (a == d && b == c)){
	return 0;
      }
    }
  }
  return -1;
}

char combsearch(int index, string str, vs comb, int *tmp){
  char a, b, c, d;
  int hoge;
  a = str[index];
  hoge = index - 1;
  while(hoge >= 0 && str[hoge] == '|')hoge--;
  if(hoge < 0)return '|';
  b = str[hoge];
  for(int i = 0; i < (int)comb.size(); i++){
    c = comb[i][0];
    d = comb[i][1];
    if((a == c && b == d) || (a == d && b == c)){
      *tmp = hoge;
      return comb[i][2];
    }
  }
  return '|';
}

string solve(vs comb, vs opse, string str){
  int size = (int)str.size();
  char c;
  int tmp;
  for(int i = 1; i < size; i++){
    while( (c = combsearch(i, str, comb, &tmp)) != '|'){
      str[i] = c;
      str[tmp] = '|';
    }
    tmp = opsesearch(i, str, opse);
    if(tmp != -1){
      for(int j = tmp; j <= i; j++){
	str[j] = '|';
      }
    }
  }
  /* |を消す */
  #if 1
  string res;
  for(int i = 0; i < size; i++){
    if(str[i] != '|')res.PB(str[i]);
  }
  return res;
  #else
  return str;
  #endif
}

void show(int i, string res){
  if(res.size() == 0){
    cout << "Case #" << (i + 1) << ": []" << endl;
  }
  else {
    cout << "Case #" << (i+1) << ": [";
    for(int j = 0; j < (int)res.size() - 1; ++j){
      cout << (char)res[j] << ", ";
    }
    cout << (char)res[(int)res.size() - 1] << "]" << endl;
  }
}

int main(void){
  int T, C, D, N;
  string str, res;
  vs comb, opse;
  cin >> T;
  for(int i = 0; i < T; i++){
    comb = vs(0);
    opse = vs(0);
    cin >> C;
    while(C--){
      cin >> str;
      comb.PB(str);
    }
    cin >> D;
    while(D--){
      cin >> str;
      opse.PB(str);
    }
    cin >> C;
    cin >> str;
    res = solve(comb, opse, str);
    show(i, res);
  }
  return 0;
}
