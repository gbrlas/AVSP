#include<iostream>
#include<algorithm>
#include<numeric>
using namespace std;
const int BUF = 1005;


int nNum, num[BUF];

void read(){
  cin >> nNum;
  for(int i=0;i<nNum;i++) cin >> num[i];
}


void work(int cases){
  int judge = 0;
  for(int i=0;i<nNum;i++) judge ^= num[i];

  cout << "Case #" << cases << ": ";
  if(judge!=0)
    cout << "NO" << endl;
  else
    cout << accumulate(num,num+nNum,0)-*min_element(num,num+nNum) << endl;
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
