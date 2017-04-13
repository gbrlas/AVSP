#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
const int LENG = 505, WELCO = 20, MOD = 10000;

string s;

void read(){
  getline(cin,s);
}

void work(int cases){
  static string welco = "welcome to code jam";

  static int dp[LENG][WELCO];
  memset(dp,0,sizeof(dp));
  dp[0][0] = 1;
  
  for(int i=0;i<s.size();i++)
    for(int j=0;j<=welco.size();j++){
      dp[i+1][j] = (dp[i+1][j]+dp[i][j])%MOD;
      if(j<welco.size() && s[i]==welco[j])
        dp[i+1][j+1] = (dp[i+1][j+1]+dp[i][j])%MOD;
    }
  
  printf("Case #%d: %04d\n",cases,dp[s.size()][welco.size()]);
}

int main(){
  int cases;
  string dummy;  
  cin >> cases;
  getline(cin,dummy);
  for(int i=0;i<cases;i++){
    read();
    work(i+1);
  }
  return 0;
}
