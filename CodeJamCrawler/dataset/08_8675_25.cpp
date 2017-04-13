#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int K;
string str;

void read(){
  cin >> K >> str;
}

string convert(int v[20]){
  string ret;
  for(int i=0;i<str.size();i+=K)
    for(int j=0;j<K;j++)
      ret += str[i+v[j]];
  return ret;
}

int eval(string s){
  int ret = 0;
  for(int i=0;i<s.size();){
    while(i+1<s.size() && s[i]==s[i+1]) 
      i++;
    i++;
    ret++;
  }
  return ret;
}

void work(int cases){
  int v[20], ans = (1<<20);
  for(int i=0;i<K;i++) v[i] = i;

  do{
    ans = min(ans,eval(convert(v)));
  }while(next_permutation(v,v+K));

  cout << "Case #" << cases << ": " << ans << endl;
}

int main(){
  int cases;
  cin >> cases;

  for(int i=0;i<cases;i++){
    read();
    work(i+1);
  }

  return 0;
}
