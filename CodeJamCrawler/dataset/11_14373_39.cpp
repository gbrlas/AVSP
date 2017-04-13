#include<iostream>
#include<map>
using namespace std;
const int BUF = 1005;


int nPrime, prime[BUF];
bool isPrime[BUF];

void makePrime(){
  for(int i=0;i<BUF;i++) isPrime[i] = true;
  for(int i=2;i*i<BUF;i++)
    if(isPrime[i])
      for(int j=i*2;j<BUF;j+=i)
        isPrime[j] = false;
  nPrime = 0;
  for(int i=2;i<BUF;i++)
    if(isPrime[i])
      prime[nPrime++] = i;
}


int N;

void read(){
  cin >> N;
}


void work(int cases){
  if(N==1){
    cout << "Case #" << cases << ": " << 0 << endl;
    return;
  }

  map<int,int> prime2cnt;
  
  for(int i=0;i<nPrime && prime[i]<=N;i++){
    int n = 1, cnt = 0;
    while(n*prime[i]<=N){
      n *= prime[i];
      cnt++;
    }
    prime2cnt[prime[i]] = cnt;
  }

  int minV = prime2cnt.size(), maxV = 0;
  for(map<int,int>::iterator iter=prime2cnt.begin();iter!=prime2cnt.end();iter++)
    maxV += iter->second;

  cout << "Case #" << cases << ": " << maxV-minV+1 << endl;
}


int main(){
  makePrime();
  int cases;
  cin >> cases;
  for(int i=0;i<cases;i++){
    read();
    work(i+1);
  }
  return 0;
}
