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
struct node{
	int arr[26];
	node(char x){ memset(arr,0,sizeof(arr)); arr[x-'a']=1;}
	node(){ memset(arr,0,sizeof(arr)); }
	void doset(char x) { arr[x-'a']=1; }
	bool isset(char x) { if(arr[x-'a']==1) return true; return false; }
};

void parse(string &s,vector<node> &v){
	int idx=0,i;
	bool open=false;
	for(i=0;i<s.size();i++){
		if(s[i]==')') { 
			open=false;continue; 
		}
		if(s[i]=='('){ 
			open=true;
			v.push_back(node());
			continue;
		 }
		if(!open){
			v.push_back(node(s[i]));
		} else {
			v.back().doset(s[i]);
		}
		if(v.size()>17) break;
	}
	return;
}

bool match(string &s,vector<node> &v){
		if(s.size()>v.size()) return false;
	int i;
	for(i=0;i<s.size();i++){
		if(!v[i].isset(s[i])) return false;
	}
	return true;
}

int main(){
	int L,D,N;
	while(scanf (" %d %d %d",&L,&D,&N)!=EOF){
		string s;
		vector<string> v;
		int i,j;
		for(i=0;i<D;i++){ cin >>s; v.push_back(s); }
		sort(v.begin(),v.end());
		for(i=0;i<N;i++){ 
			cin >>s; 
		vector<node> tmp;
		parse(s,tmp);

		int ans=0;
		for(j=0;j<D;j++) if(match(v[j],tmp)) ans++;
		printf("Case #%d: %d\n",i+1,ans);

			
		}
		
		
	}
	return 0;
}

