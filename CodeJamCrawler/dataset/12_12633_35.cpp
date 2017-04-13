#include<iostream>
#include<algorithm>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
const double EPS = 1e-3;
const int BUF = 1005;

int W, H, nCircle;
double r[BUF];

void read(){
  cin >> nCircle >> W >> H;
  for(int i=0;i<nCircle;i++){
    cin >> r[i];
    r[i] += EPS;
  }
}


void work(int cases){
  int order[BUF], invOrder[BUF];
  for(int i=0;i<nCircle;i++) order[i] = i;

  while(1){
    random_shuffle(order,order+nCircle);
    for(int i=0;i<nCircle;i++)
      invOrder[order[i]] = i;

    double xPos[BUF], yPos[BUF];

    int puttingIdx = 0;
    vector<int> prePut, curPut;
    while(puttingIdx<nCircle){
      double maxY = 0;
      for(int i=0;i<prePut.size();i++)
        maxY = max(maxY,yPos[prePut[i]]+r[prePut[i]]);
      
      double curX = 0;
      while(puttingIdx<nCircle && curX<=W){
        if(!prePut.empty() && maxY+r[order[puttingIdx]]>H) 
          goto _fail;
        xPos[order[puttingIdx]] = curX;
        yPos[order[puttingIdx]] = (prePut.empty() ? 0 : maxY+r[order[puttingIdx]]);
        curX += r[order[puttingIdx]]+(puttingIdx+1<nCircle ? r[order[puttingIdx+1]] : 0);
        curPut.push_back(order[puttingIdx]);
        puttingIdx++;
      }

      if(curPut.empty()) 
        goto _fail;

      prePut = curPut;
      curPut.clear();
    }


#define sq(x) ((x)*(x))
    for(int i=0;i<nCircle;i++)
      for(int j=i+1;j<nCircle;j++){
        double dist = sqrt(sq(xPos[order[i]]-xPos[order[j]])+sq(yPos[order[i]]-yPos[order[j]]));
        if(dist<r[order[i]]+r[order[j]]-EPS*2){
          cout << "h" << endl;
          goto _fail;
        }
        if(!(0<=xPos[order[i]] && xPos[order[i]]<=W && 
             0<=yPos[order[i]] && yPos[order[i]]<=H)){
          cout << "g" << endl;
          goto _fail;
        }
      }

    cout << "Case #" << cases << ":";
    for(int i=0;i<nCircle;i++)
      printf(" %f %f",xPos[invOrder[order[i]]],yPos[invOrder[order[i]]]);
    printf("\n");
    return;
    
  _fail:;
  }



  /*
    cout << "Case #" << cases << ":";
    for(int i=0;i<nCircle;i++)
      printf(" %f %f",posX[order[i]],posY[order[i]]);
    printf("\n");
  */
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
