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

using namespace std;

#define MP make_pair
#define PB push_back

int T;
int n,m,N,r[2000];
vector<pair<int,int> > t,la;
vector<pair<int,int> > ans;

bool make(int &i){
	la=t;
	t.clear();
	reverse(la.begin(),la.end());
	int x=0;
	for (;i<N;){
		int len=r[i]*2;
		int ts=0,q=0,h=m;
		for (q=0;q<la.size();q++){
			ts+=la[(int)la.size()-1-q].first;
			h=min(h,la[(int)la.size()-1-q].second);
			if (ts>=len) break;
		}
		if (ts>=len){
			if (h<len) break;
			t.PB(MP(len,h-len));
			ans.PB(MP(x+r[i],h-r[i]));
			i++;
			x+=len;
			for (int z=1;z<=q;z++) la.pop_back();
			if (ts-len) la[(int)la.size()-1].first=ts-len;
			else la.pop_back();
		}
		else break;
	}
	return true;
}

int getrand(int mo){
	int k=((rand()&65535)<<15)+(rand()&65535);
	return k%mo;
}

bool check(int x,int y,int ri){
	for (int i=0;i<ans.size();i++){
		double dist=sqrt((x-ans[i].first+0.1)*(x-ans[i].first+0.1)+(y-ans[i].second+0.1)*(y-ans[i].second+0.1)+0.1);
		if (dist<r[i]+ri+1.1) return false;
	}
	return true;
}

int main(){
	srand(time(0));
	scanf("%d",&T);
	for (int ti=1;ti<=T;ti++){
		scanf("%d%d%d",&N,&n,&m);
		t.clear();
		ans.clear();
		for (int i=0;i<N;i++) scanf("%d",&r[i]);
		t.PB(MP(n,m));
		for (int i=0;i<N;i++){
			for (;;){
				int a,b;
				bool f=check(a=getrand(n+1),b=getrand(m+1),r[i]);
				if (f) {ans.PB(MP(a,b));break;}
			}
		}
		printf("Case #%d:",ti);
		for (int i=0;i<N;i++) printf(" %d %d",ans[i].first,ans[i].second);
		puts("");
	}
    return 0;
}
