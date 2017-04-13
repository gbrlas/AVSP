#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

string s[10];
string tmps[10];
int a[10];
int n,m,tott;
int MM, tot;
map<string, int> app;

int calc1(){
	app.clear();
	for (int i=0; i<tott; ++i){
		string now="";
		for (int j=0; j<tmps[i].size(); ++j){
			now+=tmps[i][j];
			//cout<<now<<endl;
			app[now]=1;
		}
	}
	return app.size();
}

int calc(){
	int ret=0;
	for (int i=0; i<m; ++i){
		tott=0;
		for (int j=0; j<n; ++j)
			if (a[j]==i) tmps[tott++]=s[j];
		if (tott==0) return 0;
		ret+=calc1();
	}
	return ret;
}

void dfs(int x){
	if (x==n){
		int tmp=calc();
		if (tmp>MM){
			MM=tmp; tot=1;
		} else
			if (tmp==MM) ++tot;
		return;
	} else {
		for (int i=0; i<m; ++i){
			a[x]=i; dfs(x+1);
		}
	}
}

int main(){
	int test=0;
	cin>>test;
	for (int T=1; T<=test; ++T){
		printf("Case #%d: ", T);
		cin>>n>>m;
		for (int i=0; i<n; ++i)
			cin>>s[i];
		MM=0; tot=0;
		dfs(0);
		printf("%d %d\n", MM+m, tot);
	}
}
