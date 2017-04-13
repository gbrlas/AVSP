#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

#define INF (INT_MAX)
#define REP(i,n) for(int i = 0; i < n; i ++)
#define FOR(i,s,n) for(int i = s; i < n; i ++)
#define pb push_back
#define GI ({int _; scanf("%d\n", &_); _;})
#define X first
#define Y second
#define ipair pair<int,int>
#define mp make_pair

void solve() {
  int aa, ab, ra, rb;
  aa = ab = ra = rb = 0;
  int delay = GI;
  int na = GI, nb = GI;
  
  vector<pair<ipair, ipair> > stationa, stationb;
  
  REP(i, na) {
    int sh, sm, eh, em;
    scanf("%d:%d %d:%d", &sh, &sm, &eh, &em);
    em += delay;
    eh += em / 60; em %= 60;
    stationa.pb(mp(mp(sh, sm), mp(eh, em)));
  }
  REP(i, nb) {
    int sh, sm, eh, em;
    scanf("%d:%d %d:%d", &sh, &sm, &eh, &em);
    em += delay;
    eh += em / 60; em %= 60;
    stationb.pb(mp(mp(sh, sm), mp(eh, em)));
  }
  
  int hour = 0, min = 0, capa = 0, capb = 0;
  for(int hour = 0; hour < 24; hour++) {
    for(int min = 0; min < 60; min ++) {
      
      int endb = 0, enda = 0;
      //take care of ending first
      for(int i = 0; i < stationa.size(); i ++) {
        if(stationa[i].Y.X == hour and stationa[i].Y.Y == min) {
          //ends now
          endb ++;
        }
      }
      capb += endb;
      
      for(int i = 0; i < stationb.size(); i ++) {
        if(stationb[i].Y.X == hour and stationb[i].Y.Y == min) {
          //ends now
          enda ++;
        }
      }
      capa += enda;
      
      // start of journey
      //station a
      int starta = 0;
      for(int i = 0; i < stationa.size(); i++) {
        if(stationa[i].X.X == hour and stationa[i].X.Y == min) {
          //starts now
          starta ++;
        }
      }
      
      if(starta > capa) {
        ra += starta - capa;
        capa = 0;
      }
      else {
        capa -= starta;
      }
      
      
      //station b
      int startb = 0;
      for(int i = 0; i < stationb.size(); i++) {
        if(stationb[i].X.X == hour and stationb[i].X.Y == min) {
          //starts now
          startb ++;
        }
      }
            
      if(startb > capb) {
        rb += startb - capb;
        capb = 0;
      }
      else {
        capb -= startb;
      }
    }
  }
  
  static int kase = 0;
  printf("Case #%d: %d %d\n", ++kase, ra, rb);
}

int main() {
  int t; cin >> t; while(t--) { solve() ; }
  return 0;
}