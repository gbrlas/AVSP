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
    int N;
    cin >> N;
#define NAME first
#define ARG second
    tr1::unordered_map<string,int> nowon, clock;
    vector<pair<string,int> > orders;
    REP(i, N){
      string name;
      int button;
      cin >> name >> button;
      orders.push_back(MP(name, button));
    }
    nowon["O"] = nowon["B"] = 1;
    clock["O"] = clock["B"] = 0;
    int time = 0;
    FOR_EACH(o, orders){
      int pos = nowon[o->NAME];
      int target = o->ARG;
      int dist = abs(pos - target);
      int basetime = clock[o->NAME];
      
      time = max(basetime+dist+1, time+1);
      clock[o->NAME] = time;
      nowon[o->NAME] = target;
      //cerr << o->NAME << " " << target << " " << time << endl;
    }

    cout << "Case #" << case_no+1 << ": " << time << endl;
  }

  return 0;
}
