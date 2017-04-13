#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int s,q;

int query[1002];

int dp[1002][102];

int solve(int pos, int engine) {
	if(pos==q) return 0;
	int &ret=dp[pos][engine];
	if(ret!=-1) return ret;
	for(int i=0;i<s;i++)
		if(i!=query[pos]) {
			int res=solve(pos+1,i);
			if(res==-1) continue;
			if(i!=engine) res++;
			if(ret==-1||res<ret) ret=res;
		}
	return ret;
}

int main() {
	int cases;
	cin>>cases;
	string tmp;
	for(int tc=1;tc<=cases;tc++) {
		map<string,int> m;
		int idx=0;
		cin>>s;
		getline(cin,tmp);
		for(int i=0;i<s;i++) {
			getline(cin,tmp);
			m[tmp]=idx++;
		}
		cin>>q;
		getline(cin,tmp);
		for(int i=0;i<q;i++) {
			getline(cin,tmp);
			query[i]=m[tmp];
		}
		memset(dp,-1,sizeof(dp));
		int ret=max(0,solve(0,s+1)-1);
		cout<<"Case #"<<tc<<": "<<ret<<endl;
	}
}
