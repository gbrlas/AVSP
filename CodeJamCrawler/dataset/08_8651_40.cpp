#include<iostream>
#define BUF 5005
#define QUERY 105
using namespace std;

int nCard, nQuery, query[QUERY];

void read(){
  cin >> nCard >> nQuery;
  for(int i=0;i<nQuery;i++)
    cin >> query[i];
}

void work(int cases){
  int id[BUF];
  for(int i=0;i<BUF;i++) id[i] = -1;
  id[0] = 0;

  int idx = 1, cnt = 0, nDetermined = 1;
  while(nDetermined<nCard){
    if(cnt==nDetermined%(nCard-nDetermined) && id[idx]==-1){
      id[idx] = nDetermined++;
      cnt = -1;
      continue;
    }


    idx = (idx+1)%nCard;
    while(id[idx]!=-1) idx = (idx+1)%nCard;
    cnt++;
  }

  cout << "Case #" << cases << ":";
  for(int i=0;i<nQuery;i++)
    cout << ' ' << id[query[i]-1]+1;
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
