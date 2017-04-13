#include<iostream>
#include<string>

#include<cstdio>
#include<cstdlib>

using namespace std;

#define FOR(i,a,n) for(int i = (int)(a); i < (int)(n); i++)
#define REP(i,n) FOR(i,0,n)
#define FOR_EACH(i,v) for(__typeof((v).begin())i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(), (v).end()

int main(){
  int t;
  cin >> t;
  REP(i, t){
    int n, k;
    cin >> n >> k;
    int mul = 1<<n;
    int lstat = k % mul;
    cout << "Case #" << i+1 << ": " << (lstat==(mul-1) ? "ON" : "OFF") << endl;
  }
}

