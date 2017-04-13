#include<iostream>
#include<sstream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<utility>
#include<functional>
#include<queue>

#include<cstdio>
#include<cstdlib>
#include<cctype>
#include<cstring>

using namespace std;
#define ALL(v) (v).begin(), (v).end()
#define MP make_pair
const int DEPARTURE(1);
const int ARRIVAL(-1);
const int STATION_A(0);
const int STATION_B(1);

inline int t2i(string t){
  return atoi(t.c_str())*60 + atoi(t.c_str()+3);
}

int main(){
  int n, T, NA, NB;
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> T >> NA >> NB;
    string tmp;
    priority_queue< pair<int,pair<int,int> >,
      vector<pair<int,pair<int,int> > >,
      greater<pair<int,pair<int,int>  > > > q;
    int remain[2]; remain[0]  = remain[1] = 0;
    for(int j = 0; j < NA; j++){
      cin >> tmp;
      q.push(MP(t2i(tmp), MP(DEPARTURE, STATION_A) ) );
      cin >> tmp;
      q.push(MP(t2i(tmp)+T, MP(ARRIVAL, STATION_B) ) );
    }
    for(int j = 0; j < NB; j++){
      cin >> tmp;
      q.push(MP(t2i(tmp), MP(DEPARTURE, STATION_B) ) );
      cin >> tmp;
      q.push(MP(t2i(tmp)+T, MP(ARRIVAL, STATION_A) ) );
    }
    int ans[2]; ans[0] = ans[1] = 0;
#define EVENT first 
#define PLACE second
    while(!q.empty()){
      pair<int,int> now(q.top().second); q.pop();
      remain[now.PLACE] -= now.EVENT;
      if(remain[now.PLACE] < 0) {
	remain[now.PLACE] = 0;
	ans[now.PLACE]++;
      }
    }
#undef EVENT
#undef PLACE
    printf("Case #%d: %d %d\n", i+1, ans[STATION_A], ans[STATION_B]);
  }
  return 0;
}
