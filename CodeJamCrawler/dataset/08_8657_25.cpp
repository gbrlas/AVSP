#include<iostream>
#define BUF 100
using namespace std;

class Node{
public:
  bool leaf;

  // if interior
  int gate, change;

  // if leaf
  int value;
};

int nNode, dst;
Node nodes[BUF];

void read(){
  cin >> nNode >> dst;
  
  for(int i=0;i<(nNode-1)/2;i++){
    nodes[i].leaf = false;
    cin >> nodes[i].gate >> nodes[i].change;
  }

  for(int i=(nNode-1)/2;i<nNode;i++){
    nodes[i].leaf = true;
    cin >> nodes[i].value;
  }
}

int rec(int idx){
  if(nodes[idx].leaf) return nodes[idx].value;

  if(nodes[idx].gate==1)
    return rec(idx*2+1)&rec(idx*2+2);
  else
    return rec(idx*2+1)|rec(idx*2+2);
}

void get(int idx, int cnt, int &ans){
  if(cnt>=ans) return;

  if(idx==(nNode-1)/2){
    if(rec(0)==dst)
      ans = cnt;
    return;
  }

  get(idx+1,cnt,ans);

  if(nodes[idx].change==1){
    nodes[idx].gate = !nodes[idx].gate;
    get(idx+1,cnt+1,ans);
    nodes[idx].gate = !nodes[idx].gate;
  }
}

void work(int cases){
  int ans = (1<<20);

  get(0,0,ans);

  cout << "Case #" << cases << ": ";
  if(ans==(1<<20))
    cout << "IMPOSSIBLE" << endl;
  else
    cout << ans << endl;
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
