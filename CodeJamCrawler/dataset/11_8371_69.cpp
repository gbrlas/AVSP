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

int W, L, U, G;

int lx[2000], ly[2000], ux[2000], uy[2000];

ld mix(ld x, ld x1, ld y1, ld x2, ld y2) {
  return y1 + (y2-y1) * ((x-x1) / (x2-x1));
  }

ld cuttrap(ld oa, ld h1, ld h2) {
  ld xmi = 0;
  ld xma = 1;
  
  for(int i=0; i<100; i++) {
    ld x = (xmi+xma) / 2;
    ld ar = x * (h1 + (h2-h1) * x/2);
    if(ar > oa) xma = x;
    else xmi = x;
    }
  
  return xmi;
  }

void solveCase() {
  int res = 0;

  scanf("%d%d%d%d", &W, &L, &U, &G);
  
  for(int i=0; i<L; i++) scanf("%d%d", &lx[i], &ly[i]);
  for(int i=0; i<U; i++) scanf("%d%d", &ux[i], &uy[i]);
  
  ld hei[2000];
  
  int ch = 0;
  
  for(int i=0; i<W; i++) {
    hei[i] = mix(i, ux[ch], uy[ch], ux[ch+1], uy[ch+1]);
    if(ux[ch+1] == i) ch++;
    }

  hei[W] = uy[ch+1];
  
  ch = 0;

  for(int i=0; i<W; i++) {
    hei[i] -= mix(i, lx[ch], ly[ch], lx[ch+1], ly[ch+1]);
    if(lx[ch+1] == i) ch++;
    }
  
  hei[W] -= ly[ch+1];
  
  ld area = 0;
  for(int i=1; i<W; i++) area += hei[i];
  area += hei[0]/2;
  area += hei[W]/2;
  
  int gid = 1;
  
  ld asf = 0;

  printf("Case #%d: \n", cnum);
  
  for(int i=0; i<W; i++) {
    ld bon = (hei[i] + hei[i+1]) / 2;
    while(asf + bon >= (area*gid)/G) {
      printf("%12.10Lf\n", i + cuttrap( (area*gid)/G-asf, hei[i], hei[i+1]));
      gid++; if(gid == G) return;
      }
    asf += bon;
    }
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
