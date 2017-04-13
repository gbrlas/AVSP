#include<iostream>
#include<sstream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
#include<utility>
#include<iterator>
#include<functional>

#include<cstdio>
#include<cstdlib>

using namespace std;

#define FOR(i,a,n) for(int i = (int)(a); i < (int)(n); i++)
#define REP(i,n) FOR(i,0,n)
#define FOR_EACH(i,v) for(__typeof((v).begin())i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(), (v).end()
#define MP make_pair

class directory{
  map<string, directory> body;
public:
  int insert(istringstream& iss){
    string s;
    if(!(iss >> s)) return 0;
    return body[s].insert(iss) + 1;
  }

  int getUnmaked(istringstream &iss){
    string s;
    if(!(iss >> s)) return 0;
    map<string,directory>::iterator ite = body.find(s);
    if(ite == body.end()){
      return body[s].insert(iss) + 1;
    }else{
      return ite->second.getUnmaked(iss);
    }
  }
};

int main(){
  int T;
  cin >> T;
  REP(case_no, T){
    int N, M;
    cin >> N >> M;
    directory homeDirectory;
    REP(i, N){
      string path;
      cin >> path;
      replace(ALL(path), '/', ' ');
      istringstream iss(path);
      homeDirectory.insert(iss);
    }
    int ans(0);
    REP(i, M){
      string path;
      cin >> path;
      replace(ALL(path), '/', ' ');
      istringstream iss(path);
      ans += homeDirectory.getUnmaked(iss);
    }
    cout << "Case #" << case_no+1 << ": " << ans << endl;
  }
  return 0;
}
