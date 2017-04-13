#include<iostream>
#include<string>
#include<map>

#include<cstdio>
#include<cstdlib>

using namespace std;

#define FOR(i,a,n) for(int i = (int)(a); i < (int)(n); i++)
#define REP(i,n) FOR(i,0,n)
#define FOR_EACH(i,v) for(__typeof((v).begin())i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(), (v).end()
#define MP make_pair

pair<int, int> getCostAndHead(int head, long long* dat, int k, int N){
  int cost = 0;
  int init = head;
  while(k > 0){
    if(dat[head] > k)break;
    k -= dat[head];
    cost+= dat[head];
    head = (head >= N-1) ? 0 : (head+1);
    if(head == init)break;
  }
  return MP(cost, head);
}

int main(){
  int t;
  cin >> t;
  REP(case_no, t){
    long long R, k, N;
    cin >> R >> k >> N;
    long long dat[N];
    REP(i, N) cin >> dat[i];
    map<int, pair<int,long long> > memo;
    
    int i = 0;
    int head = 0;
    long long total = 0;
    for(; i < R; i++){
      //      cerr << " " << head << endl;
      map<int,pair<int,long long> >::iterator cur = memo.find(head);
      if(cur != memo.end()){
	int remCt = R - i;
	int period = i - cur->second.first;
	long long int periodicCost = total - cur->second.second;
	//	cerr << " " << remCt << " " << period << " " << periodicCost << endl;
	total += (long long)(remCt / period) * periodicCost;
	i += remCt - (remCt % period);
	break;
      }
      memo[head] = MP(i, total);
      pair<int,int> tmp = getCostAndHead(head, dat, k, N);
      total += tmp.first;
      head = tmp.second;
    }
    for(; i < R; i++){
      pair<int,int> tmp = getCostAndHead(head, dat, k, N);
      total += tmp.first;
      head = tmp.second;      
    }
    cout << "Case #" << case_no+1 << ": " << total << endl;
  }
}

