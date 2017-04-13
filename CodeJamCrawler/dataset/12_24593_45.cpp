#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
using namespace std;
#define MAX 10000
int mincy[2000001];
bool used[2000001];
int table[2000001];
string tostr(int x){
  stringstream ss;
  ss << x;
  string s;
  ss >> s;
  return s;
}
int toint(string s){
  stringstream ss;
  ss<<s;
  int i;
  ss>>i;
  return i;
}
vector<int> getCycle(int x){ //x以下のCycleとなる集合
  vector<int> ret;
  string s = tostr(x);
  reverse(s.begin(),s.end());
  while(s.length()<7) s+='0';
  reverse(s.begin(),s.end());
  int n = s.length();
  for(int i=1;i<n;++i){
    string t("");
    for(int j=0;j<n;++j) t+=s[(i+j)%s.length()];
    int next = toint(t);
    ret.push_back(next);
  }
  return ret;
}
int main(){
  int n;
  scanf("%d",&n);
  vector<int> group = getCycle(n);
  printf("%d\n",group.size());
  for(int i=0;i<group.size();++i) printf("%d ",group[i]);
  printf("\n");
  return 0;
}
/*
int main(){
  for(int i=MAX;i>=1;--i){
    if(mincy[i]) continue;
    vector<int> next = getCycle(i);
    sort(next.begin(),next.end());
    for(int j=0;j<next.size();++j){
      mincy[next[j]] = next[0];
    }
  }
  for(int i=1;i<=MAX;++i){
    if(!used[mincy[i]]) used[mincy[i]]=true,table[i]=table[i-1];
    else table[i]=table[i-1]+1;
  }
  int T;
  scanf("%d",&T);
  for(int t=1;t<=T;++t){
    int a,b;
    scanf("%d%d",&a,&b);
    printf("Case #%d: %d\n",t,table[b]-table[a-1]);
  }
  return 0;
}
*/
