#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <ctime>
#include <algorithm>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <string>
#include <map>
#include <set>
using namespace std;

#define MP make_pair
#define PB push_back

void show(int ti,string s){
	printf("Case #%d: [",ti);
	for (int i=0;i<s.size();i++){
		if (i) printf(", ");
		printf("%c",s[i]);
	}
	printf("]\n");
}

int T,ti,c,d,n;
string s,ans;
string cs[100],ds[100];
map<string,char> ch;
set<string> op;

void tryclear(){
	if (ans.size()<2) return;
	char c=ans[ans.size()-1];
	string t="  ";
	for (int i=0;i<ans.size()-1;i++){
		t[0]=ans[i];t[1]=c;
		if (op.find(t)!=op.end()){
			ans="";
			return;
		}
		t[0]=c;t[1]=ans[i];
		if (op.find(t)!=op.end()){
			ans="";
			return;
		}
	}
}

char change(char a,char b){
	string t="  ";t[0]=a;t[1]=b;
	if (ch.find(t)!=ch.end())return ch[t];
	t[0]=b;t[1]=a;
	if (ch.find(t)!=ch.end()) return ch[t];
	return ' ';
}

void add(char now){
	ans+=now;
	if (ans.size()==1) return;
	char k=change(ans[ans.size()-2],ans[ans.size()-1]);
	if (k!=' '){
		ans=ans.substr(0,ans.size()-2)+k;
	}
	tryclear();
}

int main(){
	scanf("%d",&T);
	for (ti=1;ti<=T;ti++){
		cin>>c;
		ch.clear();
		op.clear();
		for (int i=0;i<c;i++){
			cin>>cs[i];
			ch[cs[i].substr(0,2)]=cs[i][2];
		}
		cin>>d;
		for (int i=0;i<d;i++) {
			cin>>ds[i];
			op.insert(ds[i]);
		}
		cin>>n;
		cin>>s;
		ans="";
		for (int i=0;i<n;i++) add(s[i]);
		show(ti,ans);
	}
    return 0;
}
