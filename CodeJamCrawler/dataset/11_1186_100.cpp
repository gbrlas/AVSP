#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <bitset>
#include <algorithm>
#include <utility>

using namespace std;


#define llong long long 
const double pi = acos(-1.0);

int c,d,n;
char grid[26][26];
vector<char>vi[26];


string solve(char str[]){
	int i,j,k;
	int len = strlen(str);
	string ans;
	for(i = 0;i<len;i++){
		int v = str[i]-'A';
		if(ans.size()>0){
			int u = ans[ans.size()-1]-'A';
			if(grid[u][v]!=0){
				ans[ans.size()-1] = grid[u][v];
				continue;
			}
		}
		
		for(j = 0;j<vi[v].size();j++){
			if(ans.find(vi[v][j])!=string::npos)break;
		}
		if(j<vi[v].size()){
			ans = "";
		}else{
			ans += str[i];
		}
	}
	return ans;
}
int main(){
	freopen("B-small-attempt0.in","r",stdin);
	//freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int i,j,k,t,nc = 0;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&c);
		memset(grid,0,sizeof(grid));
		for(i = 0;i<c;i++){
			char str[4];
			scanf("%s",str);
			int u = str[0]-'A';
			int v = str[1]-'A';
			int w = str[2];
			grid[u][v] = grid[v][u] = w;
		}
		scanf("%d",&d);
		for(i = 0;i<26;i++)vi[i].clear();
		for(i = 0;i<d;i++){
			char str[3];
			scanf("%s",str);
			int u = str[0]-'A';
			int v = str[1]-'A';
			vi[u].push_back(str[1]);
			vi[v].push_back(str[0]);
		}
		scanf("%d",&n);
		char str[105];
		scanf("%s",str);
		string ans = solve(str);
		printf("Case #%d: [",++nc);
		for(i = 0;i<ans.size();i++){
			char c = ans[i];
			if(i<ans.size()-1){
				printf("%c, ",c);
			}else{
				printf("%c",c);
			}
		}
		printf("]\n");
	}
	return 0;
}