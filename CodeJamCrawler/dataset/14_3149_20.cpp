#include <cstdio>
#include <vector>
#include <algorithm>

#define all(x) x.begin(), x.end()

using namespace std;

const int INF = 11111111;

struct compress{
  vector<int> p;
  void clear(){ p.clear(); }
  void add(int x){
    p.push_back(x);
  }
  void proc(){
    sort(all(p));
    p.erase(unique(all(p)),p.end());
  }
  int idx(int x){ return lower_bound(all(p),x)-p.begin() + 1; }
}cm;

int T,N;
int A[1005],B[1005];
int fw[1005];

void add(int x){
  for(int c = x ; c <= 1000 ; c += c & -c)
    fw[c]++;
}

int query(int x){
  int ret = 0;
  for(int c = x ; c ; c -= c & -c)
    ret += fw[c];
  return ret;
}

void clear(){
  for(int c = 1 ; c <= 1000 ; c++)
    fw[c] = 0;
}

int cnt1(int i){
  int ret = 0;
  for(int c = 1 ; c <= i ; c++){
    ret += query(1000)-query(B[c]);
    add(B[c]);
  }
  clear();
  return ret;
}

int cnt2(int i){
  int ret = 0;
  for(int c = i ; c <= N ; c++){
    ret += query(B[c]);
    add(B[c]);
  }
  clear();
  return ret;
}

int main(){
  scanf("%d",&T);
  for(int cc = 1 ; cc <= T ; cc++){
    scanf("%d",&N);
    cm.clear();
    for(int c = 1 ; c <= N ; c++){
      scanf("%d",&A[c]);
      cm.add(A[c]);
    }
    cm.proc();
    int sol = INF;
    for(int xx = 1 ; xx <= N ; xx++){
      // printf(" --- %d --- \n",xx);
      for(int c = 1 ; c <= N ; c++)
	B[c] = cm.idx(A[c]);
      sol = min(sol,cnt1(xx)+cnt2(xx+1));
      sol = min(sol,cnt1(xx-1)+cnt2(xx));
      int offset = 0;
      for(int d = xx-1 ; d ; d--){
	offset++;
	swap(B[d],B[d+1]);
	sol = min(sol,cnt1(d)+cnt2(d+1)+offset);
	sol = min(sol,cnt1(d-1)+cnt2(d)+offset);
      }
      for(int c = 1 ; c <= N ; c++)
	B[c] = cm.idx(A[c]);
      offset = 0;
      for(int d = xx+1 ; d <= N ; d++){
	offset++;
	swap(B[d],B[d-1]);
	sol = min(sol,cnt1(d)+cnt2(d+1)+offset);
	sol = min(sol,cnt1(d-1)+cnt2(d)+offset);
      }
    }
    printf("Case #%d: %d\n",cc,sol);
  }
}
