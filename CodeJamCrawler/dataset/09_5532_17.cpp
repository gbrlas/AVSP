//Eryx

#include <algorithm>
#include <string>
#include <vector>
#include <ctype.h>
#include <math.h>
//#include <iostream>
#include <set>
//#include <map>
//#include <sstream>

int argc, cnum; char **argv;

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

// template<class T> T& operator >?= (T& x, T y) {if(y>x) x=y; return x;}
// template<class T> T& operator <?= (T& x, T y) {if(y<x) x=y; return x;}
// template<class T> T operator >? (T x, T y) {return x>y?x:y;}
// template<class T> T operator <? (T x, T y) {return x<y?x:y;}

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

int X, Y;

int fre[20][20];

struct state {
  int bx[5], by[5];
  };

state ini, final;

int qi, qe;

int moves = 0; int lmov = 1;

vector<state> cur, next, pnext;

set<state> S;

int bc;

bool operator < (const state& s1, const state& s2) {
  for(int i=0; i<bc; i++) {
    if(s1.by[i] != s2.by[i]) return s1.by[i] < s2.by[i];
    if(s1.bx[i] != s2.bx[i]) return s1.bx[i] < s2.bx[i];
    }
  return false;
  }

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

bool lex(int a1, int b1, int a2, int b2) {
  if(a1 != a2) return a1 < a2;
  return b1 < b2;
  }

void move(state s, int bad) {
  state t;
  
  for(int i=0; i<bc; i++) for(int d=0; d<4; d++) {
    int bad2, nei;

    if(!fre[s.by[i]-dy[d]][s.bx[i]-dx[d]]) continue;
    for(int j=0; j<bc; j++) 
      if(s.by[j] == s.by[i]-dy[d] && s.bx[j] == s.bx[i]-dx[d])
        goto next;

    t = s;

    t.by[i] = s.by[i] + dy[d];
    t.bx[i] = s.bx[i] + dx[d];

//  printf("ta %d %d\n", t.by[i], t.bx[i]);

    if(!fre[t.by[i]][t.bx[i]]) continue;

//  printf("tc\n");

    for(int j=0; j<bc; j++) if(j != i && t.by[i] == t.by[j] && t.bx[i] == t.bx[j])
      goto next;
    
//  printf("tb\n");
    
    nei = 0;
    for(int ii=0; ii<bc; ii++) 
    for(int j=0; j<ii; j++) if(j != ii && abs(t.by[ii]-t.by[j]) + abs(t.bx[ii]-t.bx[j]) == 1)
      nei++;
    
//  printf("test nei\n");
    bad2 = nei < bc-1;
    if(nei == 4 && bc == 5) {
      for(int j=0; j<bc; j++) if(j != i && abs(t.by[i]-t.by[j]) + abs(t.bx[i]-t.bx[j]) == 1)
        goto valid;
      bad2 = true;
      valid: ;
      }
    
    // printf("b %d %d [%d %d = %d/bc]\n", bad, bad2, i, d, nei, bc);
    if(bad && bad2) continue;
    if(bad2) move(t, bad2);
    else {
      for(int u=0; u<5; u++) for(int j=0; j<bc-1; j++)
        if(lex(t.by[j+1],t.bx[j+1],t.by[j],t.bx[j]))
          swap(t.by[j], t.by[j+1]), swap(t.bx[j], t.bx[j+1]);
      if(S.count(t)) continue;
      S.insert(t);
      if(bad) pnext.push_back(t);
      else { next.push_back(t); }
      }
    next: ;
    }
  }

void solveCase() {
  int res = 0;
  
  string s = getLine();
  sscanf(s.c_str(), "%d%d", &Y, &X);
  
  int bi = 0, bf = 0;
  
  state ini, fin;

  FOR(y,0,20) FOR(x,0,20) fre[y][x] = 0;
  
  FOR(y,0,Y) {
    s = getLine();
    for(int x=0; x<X; x++) {
      fre[y+1][x+1] = s[x] != '#';
      if(s[x] == 'o' || s[x] == 'w')
        ini.by[bi] = y+1, ini.bx[bi] = x+1, bi++;
      if(s[x] == 'x' || s[x] == 'w')
        fin.by[bf] = y+1, fin.bx[bf] = x+1, bf++;
      }
    }
  
  //proceed
  
  res = -1;
  
  fprintf(stderr, "#%d\n", cnum);
  if(bi != bf) { goto fail; }

  bc = bi;
  S.clear();
  qi = 0, qe = 1, moves = 0, lmov = 1;
  S.insert(ini);
  cur.clear();
  cur.push_back(ini);
  next.clear();
  pnext.clear();
  
  while(true) {
    while(qi >= Size(cur)) {
      // printf("[%d]\n", qi);
      cur = next; next = pnext; pnext.clear();
      if(cur.size() == 0 && next.size() == 0) goto fail;
      qi = 0; moves++;
      }
    
    ini = cur[qi];
    
    qi++;
    
    if(!(ini < fin) && !(fin < ini)) {
      res = moves; goto fail;
      }
    
    move(ini, 0);
    }
  
  fail: 
  
  // printf("queue = %d (%d %d)\n", moves, bi, bf);
  printf("Case #%d: %d\n", cnum+1, res);
  }

int main(int _argc, char** _argv) {
  argc = _argc; argv = _argv;
  int N;
  string Nstr = getLine();
  N = atoi(Nstr.c_str());
  // alternate: scanf("%d", &N);
  for(cnum=0; cnum<N; cnum++)
    solveCase();
  return 0;
  }
