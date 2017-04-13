#include <algorithm>
#include <string>
#include <vector>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
//#include <iostream>
#include <set>
//#include <map>
//#include <sstream>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<int> vll;
typedef vector<string> vs;

int err;

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

int Tests, cnum;

//Eryx

// !FDI

char blade[600][600];

ll bx[600][600], by[600][600], bt[600][600], ubx[600][600], uby[600][600], ubt[600][600];

ll Sum;

void init() { Sum = 0; }
void add(ll& val) { swap(val, Sum); Sum += val; }

int X, Y;

int iabs(int x) { return x>0?x:-x; }

bool balance(int ox, int oy, int size) {
  // printf("[%d %d %d]\n", ox, oy, size);
  //printf("[!]\n", cx, cy, rad);
  
  int ex = ox+size, ey = oy+size;
  int ux = ex-1, uy = ey-1;
  
 // if(1) {
  
  ll recx = bx[ey][ex] - bx[ey][ox] - bx[oy][ex] + bx[oy][ox];
  ll recy = by[ey][ex] - by[ey][ox] - by[oy][ex] + by[oy][ox];
  ll rect = bt[ey][ex] - bt[ey][ox] - bt[oy][ex] + bt[oy][ox];
  
  recx -= ubx[oy][ox] + ubx[uy][ox] + ubx[oy][ux] + ubx[uy][ux];
  recy -= uby[oy][ox] + uby[uy][ox] + uby[oy][ux] + uby[uy][ux];
  rect -= ubt[oy][ox] + ubt[uy][ox] + ubt[oy][ux] + ubt[uy][ux];
  //}
  
  // printf("rect = %d recx = %d recy = %d ", int(rect), int(recx),int(recy));

  bool ok = rect * (ox+ux) == recx*2 && rect * (oy+uy) == recy*2;
  
  // if(ok) printf("%d %d %d\n", ox,oy,size);
  
  return ok;
  }

int solve() {
  for(int rad=600; rad>=3; rad--) {
    for(int x=0; x+rad<=X; x++)
    for(int y=0; y+rad<=Y; y++)
      if(balance(x,y,rad)) return rad;
    }
  
  return 0;
  }

void solveCase() {
  int res = 0;

  int N, D;
  
  scanf("%d%d%d", &Y, &X, &D);
  for(int y=0; y<Y; y++)
    scanf("%s", blade[y]);

  for(int y=0; y<600; y++) for(int x=0; x<600; x++)
    by[y][x] = bx[y][x] = bt[y][x] = 0;
  
  for(int y=0; y<Y; y++) for(int x=0; x<X; x++)
    uby[y][x] = by[y][x] = (blade[y][x] - '0') * y,
    ubx[y][x] = bx[y][x] = (blade[y][x] - '0') * x,
    ubt[y][x] = bt[y][x] = (blade[y][x] - '0');
  
  for(int y=0; y<Y; y++) {
    init(); for(int x=0; x<=X; x++) add(by[y][x]);
    init(); for(int x=0; x<=X; x++) add(bx[y][x]);
    init(); for(int x=0; x<=X; x++) add(bt[y][x]);
    }
  
  for(int x=0; x<=X; x++) {
    init(); for(int y=0; y<=Y; y++) add(by[y][x]);
    init(); for(int y=0; y<=Y; y++) add(bx[y][x]);
    init(); for(int y=0; y<=Y; y++) add(bt[y][x]);
    }
  
  // balance(1,1,5); exit(0);
  
  int ret = solve();

  if(0) for(int y=0; y<Y; y++) {
    for(int x=0; x<X; x++) {
      printf("%d", ubt[y][x]);
      }
    printf("\n");
    }

  if(ret == 0)
    printf("Case #%d: IMPOSSIBLE\n", cnum);
  else
    printf("Case #%d: %d\n", cnum, ret);
  }

int main() {

  if(0)
    Tests = 1;
  else if(1)
    err = scanf("%d", &Tests);
  else {
    string Nstr = getLine();
    Tests = atoi(Nstr.c_str());
    }
  
  for(cnum=1; cnum<=Tests; cnum++)
    solveCase();
    
  // finish
  return 0;
  }

// This solution includes hidden routines to solve test cases in separate
// processes in order to make it faster. I will update them to run on a
// cluster if I get one ;)
