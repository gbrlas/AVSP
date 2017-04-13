#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
using namespace std;
const int BUF = 1005;

class Way{
public:
  int bgn, end, speed;
  Way(){}
  Way(int b, int e, int s): bgn(b), end(e), speed(s){}
  bool operator< (const Way &opp) const {
    return speed<opp.speed;
  }
};

int leng, walkSpeed, runSpeed, runTime, nWay;
Way ways[BUF];

void read(){
  cin >> leng >> walkSpeed >> runSpeed >> runTime >> nWay;
  for(int i=0;i<nWay;i++)
    cin >> ways[i].bgn >> ways[i].end >> ways[i].speed;
}


void work(int cases){
  vector<Way> wayList;

  if(ways[0].bgn!=0)
    wayList.push_back(Way(0,ways[0].bgn,0));
  
  for(int i=0;i<nWay;i++){
    wayList.push_back(ways[i]);
    if(i==nWay-1){
      if(ways[i].end!=leng)
        wayList.push_back(Way(ways[i].end,leng,0));
    }
    else if(ways[i].end!=ways[i+1].bgn){
      wayList.push_back(Way(ways[i].end,ways[i+1].bgn,0));
    }
  }

  sort(wayList.begin(),wayList.end());

  /*
  for(int i=0;i<wayList.size();i++){
    cout << wayList[i].bgn << ' ' << wayList[i].end << ' ' << wayList[i].speed << endl;
  }
  cout << endl;
  */

  double needTime = 0;
  double remain = runTime;
  for(int i=0;i<wayList.size();i++){
    double toRunTime = 1.0*(wayList[i].end-wayList[i].bgn)/(wayList[i].speed+runSpeed);
    
    if(remain<=toRunTime){
      // run till in the middle, then walk
      double remainDist = (wayList[i].end-wayList[i].bgn)-remain*(wayList[i].speed+runSpeed);
      needTime += remain;
      remain = 0;
      needTime += remainDist/(wayList[i].speed+walkSpeed);
    }
    else{ 
      // run whole way
      
      needTime += toRunTime;
      remain -= toRunTime;
    }
  }

  printf("Case #%d: %.10lf\n",cases,needTime);
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
