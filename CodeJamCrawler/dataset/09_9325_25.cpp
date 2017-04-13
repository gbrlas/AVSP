#include<iostream>
#include<string>
#include<map>
#include<queue>
#include<vector>
using namespace std;
const int BUF = 55;

class State{
public:
  int r, c;
  vector<string> s;
  State(){}
  State(int r, int c, vector<string> s): r(r), c(c), s(s){}
  bool operator< (const State &st) const {
    if(r!=st.r) return r<st.r;
    if(c!=st.c) return c<st.c;
    return s<st.s;
  }
};

class QData{
public:
  int cost;
  State st;
  QData(){}
  QData(int c, State st): cost(c), st(st){}
  bool operator< (const QData &q) const {
    return cost>q.cost;
  }
};

int row, col, limit;
vector<string> b;

void read(){
  cin >> row >> col >> limit;
  b.clear();
  for(int i=0;i<row;i++){
    string s;
    cin >> s;
    b.push_back(s);
  }
}

void work(int cases){
  map<State,int> visited;  //State(int r, int c, string s)
  priority_queue<QData> Q; //QData(int c, State st)

  Q.push(QData(0,State(0,0,b)));
  visited[State(0,0,b)] = 0;


  int dr[] = {1,1}, dc[] = {-1,1};
  while(!Q.empty()){
    State curr = Q.top().st;
    int cost = Q.top().cost;
    Q.pop();

    if(curr.r==row-1) {
      cout << "Case #" << cases << ": Yes " << cost << endl;
      return;
    }

    // right
    if(curr.c+1<col){
      State next = curr;
      // go
      if(next.s[next.r][next.c+1]=='.'){
        next.c++;
        // fall
        int cnt = 0;
        while(next.r+1<row && next.s[next.r+1][next.c]=='.'){
          next.r++;
          cnt++;
        }
        if(cnt<=limit){
          if(!visited.count(next) || visited[next]>cost){
            visited[next] = cost;
            Q.push(QData(cost,next));
          }
        }
      }
    }

    // left
    if(curr.c-1>=0){
      State next = curr;
      // go
      if(next.s[next.r][next.c-1]=='.'){
        next.c--;
        // fall
        int cnt = 0;
        while(next.r+1<row && next.s[next.r+1][next.c]=='.'){
          next.r++;
          cnt++;
        }
        if(cnt<=limit){
          if(!visited.count(next) || visited[next]>cost){
            visited[next] = cost;
            Q.push(QData(cost,next));
          }
        }
      }
    }

    // dig
    for(int i=0;i<2;i++){
      State next = curr;
      int nr = next.r+dr[i], nc = next.c+dc[i];
      if(!(0<=nr && nr<row && 0<=nc && nc<col)) continue;
      if(nr==0 || next.s[nr-1][nc]=='#') continue;
      if(next.s[nr][nc]=='.') continue;
      next.s[nr][nc] = '.';
      if(!visited.count(next) || visited[next]>cost+1){
        visited[next] = cost+1;
        Q.push(QData(cost+1,next));
      }
    }
  }

  cout << "Case #" << cases << ": No" << endl;
}

int main(){
  int cases;
  cin >> cases;
  for(int i=0;i<cases;i++){
    read();
    work(i+1);
  }
  return 0;
}
