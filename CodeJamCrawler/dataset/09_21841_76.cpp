#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <iostream>
#include <cstring>
#include <cctype>
#include <queue>
#include <list>
#include <cstdlib>
#include <cmath>
#include <deque>
using namespace std;

typedef long long LL;
typedef pair<int,int> para;
typedef vector<int> VI;
typedef vector<vector<int> > VII;
typedef vector<string> VS;

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define FOREACH(a,n) for (__typeof(n.begin())a=n.begin();a!=n.end();++a)
#define FOR(i,a,b) for (int i=(a);i<=(b);++i)
#define FORD(i,a,b) for (int i=(a);i>=(b);--i)
#define REP(i,n) for (int i=0;i<(n);++i)
#define ALL(x) x.begin(),x.end()
#define CLR(t) memset(t,0,sizeof(t));

int l, d, n;	
char buf[307];

set<string> dict;

vector<string> tokenize(string s)
{
	int i,n=s.size();
  bool f=false;
	string a;
	vector<string> w;
	for(i=0;i<n;i++){    
		if(s[i]=='(')
      f=true;
    else if(s[i]==')'){
      f=false;
      w.PB(a);
      a.clear();
    }
    else{
      if(f)
        a += s[i];
      else
        w.PB(string("")+s[i]);
    }
	}
	return w;
}

int main()
{
  scanf("%d %d %d",&l,&d,&n);
  REP(i,d){
    scanf("%s",buf);
    dict.insert(string(buf));
  }
  REP(i,n){
    scanf("%s",buf);
    int wyn = 0;
    vector<string> pos = tokenize(string(buf));
/*    FOREACH(it, p1){
      if((*it)[0] != '('){
        FOREACH(i2, (*it)){
//          cout<<string("#")+(*i2)<<endl;
          pos.PB(string("#")+(*i2));
        }
      }
      else
        pos.PB(*it);
    }*/
/*    FOREACH(it,pos)
      cout<<*it<<endl;*/
    FOREACH(it, dict){
      bool f = true;
      REP(i,l){
        char c = (*it)[i];
        if(find(ALL(pos[i]),c) == pos[i].end())
          f = false;
      }
      if(f)
        wyn++;
    }
    printf("Case #%d: %d\n",i+1,wyn);
  }
	return 0;
}
