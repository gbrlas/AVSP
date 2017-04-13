#include<iostream>
#include<sstream>
#include<map>
#include<set>
#include<algorithm>
#include<utility>

#include<cstdio>
#include<cstdlib>
#include<cctype>
#include<cstring>

using namespace std;

int main(){
  string tmp;
  getline(cin, tmp);
  int n = atoi(tmp.c_str());
  for(int i = 0; i < n; i++){
    map<string, int> dat;
    getline(cin , tmp);
    int s = atoi(tmp.c_str());
    int ans(0);
    for(int j = 0; j < s; j++) {
      getline(cin , tmp);
      dat[tmp] = 1;
    }
    int used(s);
    getline(cin , tmp);
    int q = atoi(tmp.c_str());
    for(int j = 0; j < q; j++){
      getline(cin , tmp);
      map<string,int>::iterator x = dat.find(tmp);
      if(x != dat.end() && x->second == 1){
	used--;
	x->second = 0;
      }
      if(used == 0){
	for(map<string,int>::iterator ite=dat.begin(); ite!=dat.end(); ite++){
	  if(x != ite) ite->second = 1;
	}
	used = s-1;
	ans++;
      }
    }
    printf("Case #%d: %d\n", i+1, ans);
  }
  return 0;
}
