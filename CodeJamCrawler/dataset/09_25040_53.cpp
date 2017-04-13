#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<queue>
#include<string>
#include<cmath>
#include<fstream>
using namespace std;
#define FOR(i,a,b) for(int (i)=(a); (i)<(b); ++(i))
#define all(a) (a).begin(),(a).end()
#define MOD 1000000007
string s;
int memo[550][25];
string r;
int dfs(int index,int cur)
{
	if(cur==s.size()) return 1;
	if(index==r.size()) return 0;
	if(memo[index][cur]!=-1) 
		return memo[index][cur];
	int ret=0;
	if(s[cur]==r[index]) 
	{
		ret=dfs(index+1,cur+1);
	}
	ret+=dfs(index+1,cur);
	memo[index][cur]=ret;
	return ret;
}

int main()
{
	int t;
	s="welcome to code jam";
	ifstream fin("C:\\C-small.in");
	fin>>t;
	FILE *fp=fopen("C:\\C.out","w");
	fin.ignore();
	FOR(i,0,t)
	{
		memset(memo,-1,sizeof(memo));
		getline(fin,r);
		//cout<<r<<endl;
		int ans=dfs(0,0);
		fprintf(fp,"Case #%d: %04d\n",i+1,ans);
	}
}