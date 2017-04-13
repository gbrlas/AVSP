#include<iostream>
#include<algorithm>
#include<map>
#include<queue>
#define interval first
#define barId second
using namespace std;
const int BAR = 10005;
typedef pair<int,int> Data;

struct Bar{
  int pos, leng;
};

int nBar, dist;
Bar bar[BAR];

void read(){
  cin >> nBar;
  for(int i=0;i<nBar;i++){
    cin >> bar[i].pos >> bar[i].leng;
  }

  cin >> dist;
}


void work(int cases){
  cout << "Case #" << cases << ": ";

  map<int,int> cost; //cost[barId] := maxLeng from bar[barId].pos;
  priority_queue<Data> Q;
  
  Q.push(Data(bar[0].pos,0));
  
  while(!Q.empty()){
    Data cur = Q.top();
    Q.pop();

    if(cost.count(cur.barId) && cost[cur.barId]>=cur.interval) continue;
    cost[cur.barId] = cur.interval;
    
    if(dist-bar[cur.barId].pos<=cur.interval){
      cout << "YES" << endl;
      return;
    }

    for(int i=0;i<nBar;i++){
      if(i==cur.barId) 
        continue;
      Bar &self = bar[cur.barId];
      Bar &opp = bar[i];
      if(abs(opp.pos-self.pos)<=cur.interval && 
         !(cost.count(i) && cost[i]>=abs(opp.pos-self.pos)))
        Q.push(Data(min(opp.leng,abs(opp.pos-self.pos)),i));
    }
  }

  cout << "NO" << endl;
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
