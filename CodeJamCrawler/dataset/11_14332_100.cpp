#include<iostream>
#include<cstdio>
using namespace std;
const int BUF = 1005;


int nNum, num[BUF];

void read(){
  cin >> nNum;
  for(int i=0;i<nNum;i++) cin >> num[i];
}


void work(int cases){
  int cnt = 0;
  for(int i=0;i<nNum;i++)
    if(num[i]!=i+1)
      cnt++;
  printf("Case #%d: %.8lf\n",cases,1.0*cnt);
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
