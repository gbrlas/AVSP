#include<iostream>
#include<vector>
using namespace std;
const int BUF = 2005;


int N, nEdge;
vector<int> adj[BUF];

void read(){
  for(int i=0;i<BUF;i++) adj[i].clear();

  cin >> N >> nEdge;

  for(int i=0;i<N;i++)
    adj[i].push_back((i+1)%N);

  int src[BUF], dst[BUF];
  for(int i=0;i<nEdge;i++){ cin >> src[i];  src[i]--; }
  for(int i=0;i<nEdge;i++){ cin >> dst[i];  dst[i]--; }

  for(int i=0;i<nEdge;i++){
    adj[src[i]].push_back(dst[i]);
    adj[dst[i]].push_back(src[i]);
  }
}


void getComponent(int bgn, int now, vector<int> &component){
  int maxV = -1;
  for(int i=0;i<adj[now].size();i++){
    if(adj[now][i]==bgn && component.size()>2) return;
    maxV = max(maxV,adj[now][i]);
  }
  component.push_back(maxV);
  getComponent(bgn,maxV,component);
}


bool rec(int idx, vector<int> &curColor, int nColor, vector<int> &ans, vector< vector<int> > &components){
  if(idx==N){
    for(int i=0;i<components.size();i++){
      bool avail[BUF]={};
      for(int j=0;j<components[i].size();j++) 
        avail[curColor[components[i][j]]] = true;
      for(int j=0;j<nColor;j++) 
        if(!avail[j]) 
          return false;
    }
    ans = curColor;
    return true;
  }

  for(int i=0;i<nColor;i++){
    curColor[idx] = i;
    if(rec(idx+1,curColor,nColor,ans,components)) return true;
    curColor[idx] = -1;
  }
  return false;
}


void work(int cases){
  vector< vector<int> > component;

 _again:
  for(int bgn=0;bgn<N;bgn++){
    //if(adj[bgn].size()<6) continue;
    while(1){
      bool updated = false;
      for(int i=0;i<adj[bgn].size();i++){
        if(bgn<adj[bgn][i]){
          component.push_back(vector<int>());
          component.back().push_back(bgn);
          component.back().push_back(adj[bgn][i]);
          getComponent(bgn,adj[bgn][i],component.back());
          updated = true;

          for(int j=0;j<component.back().size();j++){
            int src = component.back()[j];
            int dst = component.back()[(j+1)%component.back().size()];
            vector<int>::iterator pos = find(adj[src].begin(),adj[src].end(),dst);
            adj[src].erase(pos);
          }
          goto _again;
        }
      }
      if(!updated) break;
    }
  }

  assert(component.size()==nEdge+1);

  /*
  for(int i=0;i<component.size();i++){
    for(int j=0;j<component[i].size();j++)
      cout << component[i][j] << ' ';
    cout << endl;
  }cout << endl;
  */

  vector<int> ans;
  for(int nColor=1;nColor<=N;nColor++){
    vector<int> curColor(N);
    if(!rec(0,curColor,nColor,ans,component)) break;
  }

  cout << "Case #" << cases << ": " << *max_element(ans.begin(),ans.end())+1 << endl;
  for(int i=0;i<N;i++){
    if(i) cout << ' ';
    cout << ans[i]+1;
  }
  cout << endl;
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
