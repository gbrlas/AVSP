#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<stack>
#include<list>

#include<tr1/unordered_map>
#include<tr1/unordered_set>

#include<algorithm>
#include<functional>
#include<utility>
#include<iomanip>
#include<iterator>

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cctype>
#include<cmath>

using namespace std;

#define FOR(i,a,n) for(int i = (int)(a); i < (int)(n); i++)
#define REP(i,n) FOR(i,0,n)
#define FOR_EACH(i,v) for(__typeof((v).begin())i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(), (v).end()
#define MP make_pair

int main(){
  int T;
  cin >> T;
  REP(case_no, T){
    int C, D, N;
    string invoke;    
    map<pair<char,char>, char> combiner;    
    set<pair<char,char> > opposer;
    cin >> C;
    REP(i, C){
      string temp; cin >> temp;
      combiner[MP(temp[0], temp[1])] = combiner[MP(temp[1], temp[0])] = temp[2];
    }
    cin >> D;
    REP(i, D){
      string temp; cin >> temp;
      opposer.insert(MP(temp[0], temp[1]));
      opposer.insert(MP(temp[1], temp[0]));
    }
    cin >> N >> invoke;
    vector<char> out;
    FOR_EACH(c,invoke){
      if(out.empty()){
	out.push_back(*c);
      }else{
	char top = out.back();
	if(combiner.find(MP(*c, top)) != combiner.end()){
	  out.pop_back();
	  out.push_back(combiner[MP(*c, top)]);
	}else{
	  FOR_EACH(o, out){
	    if(opposer.find(MP(*o, *c)) != opposer.end()){
	      out.clear();
	      break;
	    }
	  }
	  if(!out.empty()){
	    out.push_back(*c);
	  }
	}	
      }
    }
    cout << "Case #" << case_no+1 << ": [";
    REP(i, out.size()){
      cout << (i?", ":"") << out[i];
    }
    cout << "]" << endl;
  }

  return 0;
}
