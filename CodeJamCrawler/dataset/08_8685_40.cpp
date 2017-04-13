#include<iostream>
#include<map>
#include<queue>
#define BUF 15
#define U 0
#define R 1
#define S 2
#define L 3
#define r first
#define c second
using namespace std;
typedef pair<int,int> Pos;

class Data{
public:
  int r, c, br, bc, bd, yr, yc, yd;

  Data(){}
  Data(int r, int c, int br, int bc, int bd, int yr, int yc, int yd):
    r(r), c(c), br(br), bc(bc), bd(bd), yr(yr), yc(yc), yd(yd){}

  bool operator< (const Data &d) const {
    if(r!=d.r) return r<d.r;
    if(c!=d.c) return c<d.c;
    if(br!=d.br) return br<d.br;
    if(bc!=d.bc) return bc<d.bc;
    if(bd!=d.bd) return bd<d.bd;
    if(yr!=d.yr) return yr<d.yr;
    if(yc!=d.yc) return yc<d.yc;
    if(yd!=d.yd) return yd<d.yd;
    return false;
  }
};

int row, col, initR, initC, goalR, goalC;
bool wall[BUF][BUF];

void read(){
  cin >> row >> col;
  for(int i=0;i<row;i++)
    for(int j=0;j<col;j++)
      wall[i][j] = false;

  for(int i=0;i<row;i++)
    for(int j=0;j<col;j++){
      char ch;
      cin >> ch;

      if(ch=='#') wall[i][j] = true;
      if(ch=='O') initR = i, initC = j;
      if(ch=='X') goalR = i, goalC = j;
    }
}

int dr[]={-1,0,1,0}, dc[]={0,1,0,-1};

bool isInside(Pos p){
  return 0<=p.r && p.r<row && 0<=p.c && p.c<col;
}

bool valid(){
  queue<Pos> Q;
  bool visited[BUF][BUF];

  for(int i=0;i<BUF;i++)
    for(int j=0;j<BUF;j++)
      visited[i][j] = false;
  
  visited[initR][initC] = true;
  Q.push(Pos(initR,initC));

  while(!Q.empty()){
    Pos curr = Q.front();
    Q.pop();

    if(curr==Pos(Pos(goalR,goalC))) return true;

    for(int i=0;i<4;i++){
      Pos next = Pos(curr.r+dr[i],curr.c+dc[i]);
      if(!isInside(next)) continue;
      
      if(!visited[next.r][next.c] && !wall[next.r][next.c]){
        visited[next.r][next.c] = true;
        Q.push(next);
      }
    }
  }

  return false;
}

int bfs(){
  map<Data,int> visited;
  queue<Data> Q;
  
  Data init = Data(initR,initC,-1,-1,-1,-1,-1,-1);
  Q.push(init);
  visited[init] = 0;

  while(!Q.empty()){
    Data curr = Q.front();
    Q.pop();

    int curCost = visited[curr];
    if(curr.r==goalR && curr.c==goalC) return curCost;
    
    for(int bdir=0;bdir<4;bdir++)
      for(int ydir=bdir+1;ydir<4;ydir++){
        
        int br = curr.r, bc = curr.c;
        while(isInside(Pos(br,bc)) && !wall[br][bc]){
          br += dr[bdir];
          bc += dc[bdir];
        }
        br -= dr[bdir];
        bc -= dc[bdir];

        int yr = curr.r, yc = curr.c;
        while(isInside(Pos(yr,yc)) && !wall[yr][yc]){
          yr += dr[ydir];
          yc += dc[ydir];
        }
        yr -= dr[ydir];
        yc -= dc[ydir];

        for(int i=0;i<4;i++){
          int nr = curr.r+dr[i], nc = curr.c+dc[i];
          
          if(isInside(Pos(nr,nc)) && !wall[nr][nc]){
            Data next = Data(nr,nc,br,bc,bdir,yr,yc,ydir);
            if(!visited.count(next)){
              visited[next] = curCost+1;
              Q.push(next);
            }
          }
          else{
            if(br==nr-dr[i] && bc==nc-dc[i] && bdir==i){
              Data next = Data(yr,yc,br,bc,bdir,yr,yc,ydir);              
              if(!visited.count(next)){
                visited[next] = curCost+1;
                Q.push(next);
              }
            }
            if(yr==nr-dr[i] && yc==nc-dc[i] && ydir==i){
              Data next = Data(br,bc,br,bc,bdir,yr,yc,ydir);              
              if(!visited.count(next)){
                visited[next] = curCost+1;
                Q.push(next);
              }
            }
          }
        }
      }
  }

  cout << ":::" << endl;
}

void work(int cases){
  cout << "Case #" << cases << ": ";
  if(!valid()){
    cout << "THE CAKE IS A LIE" << endl;
    return;
  }

  cout << bfs() << endl;
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
