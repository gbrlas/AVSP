#include<iostream>
using namespace std;
const int BUF = 105, INF = 1<<30;

int row, col, val[BUF][BUF];

void read(){
  cin >> row >> col;
  for(int i=0;i<row;i++)
    for(int j=0;j<col;j++)
      cin >> val[i][j];
}

int rec(int r, int c, int visited[BUF][BUF], int &nSink){
  static int dr[]={-1,0,0,1}, dc[]={0,-1,1,0};
  int &ret = visited[r][c];
  if(ret!=-1) return ret;

  int minV = INF, minDir;
  for(int i=0;i<4;i++){
    int nr = r+dr[i], nc = c+dc[i];
    if(!(0<=nr && nr<row && 0<=nc && nc<col)) continue;
    if(minV>val[nr][nc] && val[r][c]>val[nr][nc]){
      minV = val[nr][nc];
      minDir = i;
    }
  }

  if(minV==INF)
    return ret = nSink++;
  else
    return ret = rec(r+dr[minDir],c+dc[minDir],visited,nSink);
}

void work(int cases){
  int visited[BUF][BUF], nSink = 0;
  memset(visited,-1,sizeof(visited));

  for(int i=0;i<row;i++)
    for(int j=0;j<col;j++)
      visited[i][j] = rec(i,j,visited,nSink);

  int nAssigned = 0, vis2ch[26];
  memset(vis2ch,-1,sizeof(vis2ch));
  
  cout << "Case #" << cases << ":" << endl;
  for(int i=0;i<row;i++){
    for(int j=0;j<col;j++){
      if(j) cout << ' ';
      if(vis2ch[visited[i][j]]==-1) vis2ch[visited[i][j]] = nAssigned++;
      cout << (char)('a'+vis2ch[visited[i][j]]);
    }
    cout << endl;
  }
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
