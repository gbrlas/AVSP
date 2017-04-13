#include<iostream>
#include<string>
using namespace std;
const int BUF = 50;

int sz;
string b[BUF];

void read(){
  cin >> sz;
  for(int i=0;i<sz;i++)
    cin >> b[i];
}

int getIdx(string &s){
  for(int i=sz-1;;i--)
    if(s[i]=='1')
      return i;
  return -1;
}

void work(int cases){
  int ans = 0;
  for(int i=0;i<sz;i++){
    if(getIdx(b[i])<=i) continue;

    for(int j=i+1;j<sz;j++)
      if(getIdx(b[j])<=i){
        for(int k=j-1;k>=i;k--){
          swap(b[k],b[k+1]);
          ans++;
        }
        break;
      }
  }
  
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
