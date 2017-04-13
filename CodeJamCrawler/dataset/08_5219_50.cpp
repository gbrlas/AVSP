#include <algorithm>
#include <string>
#include <vector>
#include <ctype.h>
#include <math.h>
//#include <iostream>
//#include <set>
//#include <map>
//#include <sstream>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<int> vll;
typedef vector<string> vs;

#define LS <
#define Size(x) (int(x.size()))
#define LET(k,val) typeof(val) k = (val)
#define CLC(act,val) (*({act; static typeof(val) CLCR; CLCR = (val); &CLCR;}))

#define FOR(k,a,b) for(typeof(a) k=(a); k LS (b); ++k)
#define FORREV(k,a,b) for(typeof(b) k=(b); (a) <= (--k);)

#define FIRST(k,a,b,cond) CLC(LET(k, a); for(; k LS (b); ++k) if(cond) break, k)
#define LAST(k,a,b,cond) CLC(LET(k, b); while((a) <= (--k)) if(cond) break, k)
#define EXISTS(k,a,b,cond) (FIRST(k,a,b,cond) LS (b))
#define FORALL(k,a,b,cond) (!EXISTS(k,a,b,!(cond)))
#define FOLD0(k,a,b,init,act) CLC(LET(k, a); LET(R##k, init); for(; k LS (b); ++k) {act;}, R##k)
#define SUMTO(k,a,b,init,x)  FOLD0(k,a,b,init,R##k += (x))
#define SUM(k,a,b,x) SUMTO(k,a,b,(typeof(x)) (0), x)
#define PRODTO(k,a,b,init,x) FOLD0(k,a,b,init,R##k *= (x))
#define PROD(k,a,b,x) PRODTO(k,a,b,(typeof(x)) (1), x)
#define MAXTO(k,a,b,init,x)  FOLD0(k,a,b,init,R##k >?= (x))
#define MINTO(k,a,b,init,x)  FOLD0(k,a,b,init,R##k <?= (x))
#define QXOR(k,a,b,x) FOLD0(k,a,b,(typeof(x)) (0), R##k ^= x)
#define QAND(k,a,b,x) FOLD0(k,a,b,(typeof(x)) (-1), R##k &= x)
#define QOR(k,a,b,x) FOLD0(k,a,b,(typeof(x)) (-1), R##k |= x)
#define FOLD1(k,a,b,init,act) CLC(LET(k, a); LET(R##k, init); for(++k; k LS (b); ++k) act, R##k)
#define MAX(k,a,b,x) FOLD1(k,a,b,x, R##k >?= (x))
#define MIN(k,a,b,x) FOLD1(k,a,b,x, R##k <?= (x))
#define FIRSTMIN(k,a,b,x) (MIN(k,a,b,make_pair(x,k)).second)

int bitc(ll r) {return r == 0 ? 0 : (bitc(r>>1) + (r&1));}
ll gcd(ll x, ll y) {return x ? gcd(y%x,x) : y;}

template<class T> T& operator >?= (T& x, T y) {if(y>x) x=y; return x;}
template<class T> T& operator <?= (T& x, T y) {if(y<x) x=y; return x;}
template<class T> T operator >? (T x, T y) {return x>y?x:y;}
template<class T> T operator <? (T x, T y) {return x<y?x:y;}

#define Pa(xy) ((xy).first)
#define Ir(xy) ((xy).second)

string cts(char c) {string s=""; s+=c; return s;}

/// ----

#define BUFSIZE 1000000
char buf[BUFSIZE];

#ifdef DEBUG
#define DEB(x) x
#else
#define DEB(x)
#endif

string getLine() {
  string s;
  while(!feof(stdin)) {
    char c = fgetc(stdin);
    if(c == 13) continue;
    if(c == 10) return s;
    s += c;
    }
  return s;
  }

int getNum() {
  string s = getLine();
  return atoi(s.c_str());
  }

vi parsevi(string s) {
  s = s + " ";
  int q = 0;
  bool minus = false;
  vi res;
  FOR(l,0, Size(s)) {
    if(s[l] == ' ') { res.push_back(minus?-q:q); q = 0; minus = false;}
    else if(s[l] == '-') { minus = true; }
    else { q = q * 10 + s[l] - '0'; }
    }
  return res;
  }

int SY, SX;

vs map;

struct state {
  int x;
  int y;
  int px;
  int py;
  };

int encode(state s) {
  return s.x + s.y * 20 + s.px * 400 + s.py * 8000;
  }

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

#define MS 20*20*20*20

int vis[MS];

void solveCase(int cnum) {
  int res = 0;
  
  string s = getLine();
  sscanf(s.c_str(), "%d%d", &SY, &SX);
  
{ 
  map.clear();
  string q = "##";
  FOR(x,0,SX) q += "#";
  map.push_back(q);
  FOR(y,0,SY) map.push_back("#" + getLine() + "#");
  map.push_back(q);}
  SX += 2;
  SY += 2;
  
//FOR(y,0,SY) printf("%s\n", map[y].c_str());
  
  int stx, sty, enx, eny;
  FOR(y,0,SY) FOR(x,0,SX) {
    if(map[y][x] == 'O') sty = y, stx = x, map[y][x] = '.';
    if(map[y][x] == 'X') eny = y, enx = x, map[y][x] = '.';
    }
  
  state ini;
  ini.x = stx;
  ini.y = sty;
  ini.px = 0;
  ini.py = 0;
  
  vector<state> q;
  int qpos = 0;
  
  FOR(u,0,MS) vis[u] = 0;
  vis[encode(ini)] = 1;
  q.push_back(ini);
  
  while(qpos < Size(q)) {
    state s = q[qpos];
    int tim = vis[encode(s)];
    
//  if(cnum == 1) printf("t=%d (%d,%d) (%d,%d)\n", tim, s.x,s.y, s.px,s.py);
    
    if(s.x == enx && s.y == eny) {
      printf("Case #%d: %d\n", cnum+1, tim-1);
      return;
      }
    
    state t = s;
    FOR(sdir,0,5) FOR(mdir,0,4) {
      s = t;
      if(sdir != 4) {
        s.px = s.x; s.py = s.y;
        while(map[s.py+dy[sdir]][s.px+dx[sdir]] == '.')
          s.py += dy[sdir], s.px += dx[sdir];
        }
      if(map[s.y+dy[mdir]][s.x+dx[mdir]] == '#') {
        s.x = s.px;
        s.y = s.py;
        }
      else {
        s.x += dx[mdir];
        s.y += dy[mdir];
        }
      if(s.x == 0 && s.y == 0) continue;
      int enc = encode(s);
      if(!vis[enc]) {
        vis[enc] = tim+1;
        q.push_back(s);
        }
      }

    qpos++;
    }
  
  printf("Case #%d: THE CAKE IS A LIE\n", cnum+1);
  }

int main() {
  int N;
  string Nstr = getLine();
  N = atoi(Nstr.c_str());
  FOR(cnum,0,N) 
    solveCase(cnum);
  return 0;
  }
