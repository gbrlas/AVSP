#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<cctype>
#include<cassert>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<deque>
#include<map>
#include<set>
#include<iterator>
#include<streambuf>
#include<sstream>
#include<list>
#include<stack>
#include<ostream>
#include<bitset>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int MAX =520;
const int MOD1=100000;
const int MOD2=10000;
const string XX="welcome to code jam";
int dp[MAX][30];
string S;
int go(int pos,int lvl){
	if(lvl==XX.size()){
		return 1;
	}
	if(dp[pos][lvl]!=-1) return dp[pos][lvl];
	int ans=0,i;
	for(i=pos;i<S.size();i++){
		if(S[i]==XX[lvl]){
		 ans+=go(i+1,lvl+1);;
		 ans%=MOD1;
		}
	}
	return dp[pos][lvl]=ans%MOD1;
}

int main(){
	int tc=1,no,i;
	set<char> valid;
	for(i=0;i<XX.size();i++) valid.insert(XX[i]);
	string s;
	getline(cin,s);
	sscanf(s.c_str()," %d",&no);
	while(no--){
		int ans=0;
		getline(cin,s);
	//	cout <<s<<endl;
		
		S=s;
		memset(dp,-1,sizeof(dp));
		ans=go(0,0);
		printf("Case #%d: %04d\n",tc++,ans%MOD2);
	}
	return 0;
}

