#include<iostream>
#include<vector>
#include<numeric>
#define BUF 105
using namespace std;

class Tree{
public:
  int nNode, adj[BUF][BUF];
};

Tree a, b;

void read(){
  for(int i=0;i<BUF;i++)
    for(int j=0;j<BUF;j++)
      a.adj[i][j] = b.adj[i][j] = 0;

  cin >> a.nNode;
  for(int i=0;i<a.nNode-1;i++){
    int s, t;
    cin >> s >> t;
    a.adj[s-1][t-1] = a.adj[t-1][s-1] = 1;
  }

  cin >> b.nNode;
  for(int i=0;i<b.nNode-1;i++){
    int s, t;
    cin >> s >> t;
    b.adj[s-1][t-1] = b.adj[t-1][s-1] = 1;
  }
}

bool match(int apre, int acur, int bpre, int bcur){
  int aDegree = accumulate(a.adj[acur],a.adj[acur]+a.nNode,0);
  int bDegree = accumulate(b.adj[bcur],b.adj[bcur]+b.nNode,0);
  if(bDegree==0) return true;
  if(bDegree==1){
    for(int i=0;i<b.nNode;i++)
      if(b.adj[bcur][i] && i==bpre)
	return true;
  }
  if(aDegree<bDegree) return false;

  bool used[BUF];
  for(int i=0;i<a.nNode;i++) used[i] = false;

  vector<int> aChild, bChild;
  for(int i=0;i<a.nNode;i++) 
    if(a.adj[acur][i] && i!=apre)
      aChild.push_back(i);
  
  for(int i=0;i<b.nNode;i++) 
    if(b.adj[bcur][i] && i!=bpre)
      bChild.push_back(i);
  
  do{
    sort(bChild.begin(),bChild.end());
    do{
      bool ok = true;
      for(int i=0;i<bChild.size();i++)
	if(!match(acur,aChild[i],bcur,bChild[i])){
	  ok = false;
	  break;
	}
      if(ok) return true;
    }while(next_permutation(bChild.begin(),bChild.end()));
  }while(next_permutation(aChild.begin(),aChild.end()));

  return false;
}

void work(int cases){
  cout << "Case #" << cases << ": ";
  
  for(int i=0;i<a.nNode;i++)
    if(match(-1,i,-1,0)){
      cout << "YES" << endl;
      return;
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
