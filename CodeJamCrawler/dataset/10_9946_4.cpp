#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
const int BUF = 200, INF = 1<<30;

int sz, b[BUF][BUF];

void read(){
  cin >> sz;
  for(int r=0;r<sz*2-1;r++){
    if(r<sz){
      int row = r, col = 0;
      for(int i=0;i<=r;i++){
        cin >> b[row][col];
        row--, col++;
      }
    }
    else {
      int row = sz-1, col = r-sz+1;
      for(int i=0;i<2*sz-r-1;i++){
        cin >> b[row][col];
        row--, col++;
      }
    }
  }
}

void print(int mat[BUF][BUF], int len){
  for(int r=0;r<len*2-1;r++){
    if(r<len){
      int row = r, col = 0;
      for(int i=0;i<=r;i++){
        cout << mat[row][col] << ' ';
        row--, col++;
      }
    }
    else{
      int row = len-1, col = r-len+1;
      for(int i=0;i<2*len-r-1;i++){
        cout << mat[row][col] << ' ';
        row--, col++;
      }
    }
    cout << endl;
  }
  cout << endl;
}

int eval(int mat[BUF][BUF], int len){
  int ret = 0;
  for(int i=0;i<len;i++)
    for(int j=0;j<len;j++)
      ret += mat[i][j]==-1;
  //print(mat,len);
  for(int r=0;r<len;r++)
    for(int c=0;c<len;c++){
      //int U = mat[r][c], R = mat[c][r], L = mat[len-c-1][r], D = mat[r][len-c-1];
      int rr[] = {r,c,len-c-1,len-r-1};
      int cc[] = {c,r,len-r-1,len-c-1};
      int v[4];

      for(int i=0;i<4;i++)
        v[i] = mat[rr[i]][cc[i]];
      
      if(r==c){ 
        if(v[0]==-1 && v[3]==-1){
          mat[rr[0]][cc[0]] = mat[rr[3]][cc[3]] = v[0] = v[3] = 0;
        }
        if(v[0]!=-1 && v[3]==-1){
          mat[rr[3]][cc[3]] = v[3] = v[0];
        }
        if(v[3]!=-1 && v[0]==-1){
          mat[rr[0]][cc[0]] = v[0] = v[3];
        }
        if(v[0]!=-1 && v[3]!=-1 && v[0]!=v[3]) return INF;
        continue;
      }
      else if(r==len-c-1){
        if(v[0]==-1 && v[1]==-1){
          mat[rr[0]][cc[0]] = mat[rr[1]][cc[1]] = v[0] = v[1] = 0;
        }
        if(v[0]!=-1 && v[1]==-1){
          mat[rr[1]][cc[1]] = v[1] = v[0];
        }
        if(v[1]!=-1 && v[0]==-1){
          mat[rr[0]][cc[0]] = v[0] = v[1];
        }
        if(v[0]!=-1 && v[1]!=-1 && v[0]!=v[1]) return INF;        
        continue;
      }

      for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
          if(v[i]!=-1 && v[j]==-1) {
            mat[rr[j]][cc[j]] = v[j] = v[i];
            //ret++;
          }
          if(v[j]!=-1 && v[i]==-1) {
            mat[rr[i]][cc[i]] = v[i] = v[j];
            //ret++;
          }
          if(v[j]!=-1 && v[i]!=-1 && v[j]!=v[i]) return INF;
        }
      }

      for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
          if(v[i]==-1 && v[j]==-1)
            mat[rr[i]][cc[i]] = mat[rr[j]][cc[j]] = v[i] = v[j] = 0;

    }
  //print(mat,len);
  //cout << ret << endl;
  return ret;
}

void work(int cases){
  int minV = INF;
  for(int len=sz;len<sz*3;len++)
    for(int putR=0;putR+sz<=len;putR++)
      for(int putC=0;putC+sz<=len;putC++){
        int mat[BUF][BUF];
        memset(mat,-1,sizeof(mat));
        
        for(int r=0;r<sz;r++)
          for(int c=0;c<sz;c++)
            mat[putR+r][putC+c] = b[r][c];

        minV = min(minV,eval(mat,len));
      }
  cout << "Case #" << cases << ": " << minV << endl;
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
