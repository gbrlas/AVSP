#include<iostream>
#include<string>
#include<sstream>
using namespace std;

string s2("welcome to code jam");
string s1;
int dp[520][25];
int solve(int i,int j){
 // cout<<"dwd"<<" "<<i<<" "<<j<<" "<<s1<<" "<<s2.length()<<endl;
  if(j == s2.length()) return 1;
  
  if(i== s1.length())return 0;
  
  if(dp[i][j]!=-1){return dp[i][j];}
  if(s1[i]==s2[j]) dp[i][j]= (solve(i+1,j+1)%10000+ solve(i+1,j)%10000)%10000;
  else dp[i][j] = (solve(i+1,j))%10000;
  return dp[i][j];
}
int main(){

int n;
cin>>n;
getline(cin,s1);
int count=1;
for(int i=0;i<n;i++) {
getline(cin,s1);
memset(dp,-1,sizeof(dp));
solve(0,0);
stringstream s1;
s1<<dp[0][0];
string t=s1.str();
for(int i=t.length();i<4;i++){
t='0'+t;
}
cout<<"Case #"<<count<<":"<<" "<<t<<endl;
count++;
}
}
