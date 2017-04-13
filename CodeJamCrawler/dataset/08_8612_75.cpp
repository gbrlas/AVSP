#include<iostream>
#include<string>
#include<algorithm>
#define INF (1<<20)
#define BUF 105
using namespace std;

int n[2], turn;
pair<int,int> go[2][BUF];

int convert(string a){
  return atoi(a.substr(0,2).c_str())*60+atoi(a.substr(3).c_str());
}

void read(){
  cin >> turn;
  cin >> n[0] >> n[1];

  for(int j=0;j<2;j++)
    for(int i=0;i<n[j];i++){
      string s, t;
      cin >> s >> t;
      go[j][i] = make_pair(convert(s),convert(t));
    }

  sort(go[0],go[0]+n[0]);
  sort(go[1],go[1]+n[1]);
}

void work(int cases){
  int cnt = 0, ans[2] = {0};
  bool visited[2][BUF];

  for(int i=0;i<2;i++)
    for(int j=0;j<n[i];j++)
      visited[i][j] = false;

  while(cnt<n[0]+n[1]){
    int minV = INF;
    int pos, idx;

    for(int i=0;i<2;i++)
      for(int j=0;j<n[i];j++)
        if(minV>go[i][j].first && !visited[i][j]){
          minV = go[i][j].first;
          pos = i;
          idx = j;
        }

    ans[pos]++;
    cnt++;
    visited[pos][idx] = true;
    int curTime = go[pos][idx].second+turn;

    while(true){
      bool found = false;
      for(int i=0;i<n[!pos];i++)
        if(curTime<=go[!pos][i].first && !visited[!pos][i]){
          visited[!pos][i] = true;
          curTime = go[!pos][i].second+turn;
          pos = !pos;
          found = true;
          cnt++;
          break;
        }

      if(!found) break;
    }
  }

  cout << "Case #" << cases << ": " << ans[0] << ' ' << ans[1] << endl;
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
