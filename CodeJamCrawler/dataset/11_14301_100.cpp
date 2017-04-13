#include<iostream>
#include<cstdlib>
using namespace std;
const int QUERY = 105;
const int POS = 105;


int nQuery;
pair<int,int> query[QUERY];

void read(){
  cin >> nQuery;
  for(int i=0;i<nQuery;i++){
    char ch;
    cin >> ch;
    query[i].first = ch=='O';
    cin >> query[i].second;
  }
}


void work(int cases){
  int pos[2] = {1,1}, ans = 0;

  for(int i=0;i<nQuery;i++){
    pair<int,int> &q = query[i];

    pair<int,int> oppQ = make_pair(-1,-1);
    for(int j=i+1;j<nQuery;j++)
      if(q.first!=query[j].first){
        oppQ = query[j];
        break;
      }
      
    int toAdd = abs(pos[q.first]-q.second)+1;
    ans += toAdd;
    if(oppQ!=make_pair(-1,-1)){
      if(pos[oppQ.first]<oppQ.second)
        pos[oppQ.first] = min(pos[oppQ.first]+toAdd,oppQ.second);
      else
        pos[oppQ.first] = max(pos[oppQ.first]-toAdd,oppQ.second);
    }
    pos[q.first] = q.second;
  }

  cout << "Case #" << cases << ": " << ans << endl;
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
