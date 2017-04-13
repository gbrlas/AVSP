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
//#define MAXTO(k,a,b,init,x)  FOLD0(k,a,b,init,R##k >?= (x))
#define MINTO(k,a,b,init,x)  FOLD0(k,a,b,init,R##k <?= (x))
#define QXOR(k,a,b,x) FOLD0(k,a,b,(typeof(x)) (0), R##k ^= x)
#define QAND(k,a,b,x) FOLD0(k,a,b,(typeof(x)) (-1), R##k &= x)
#define QOR(k,a,b,x) FOLD0(k,a,b,(typeof(x)) (-1), R##k |= x)
#define FOLD1(k,a,b,init,act) CLC(LET(k, a); LET(R##k, init); for(++k; k LS (b); ++k) act, R##k)
//#define MAX(k,a,b,x) FOLD1(k,a,b,x, R##k >?= (x))
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

int N;

#define MAX 13000

int qty[MAX];

int qreq[MAX], qmay[MAX];


bool solve(int len) {
  for(int u=0; u<MAX; u++) qreq[u] = qty[u], qmay[u] = 0;
  // for(int u=0; u<20; u++) printf("%d ", qreq[u]); printf("\n");
  
  for(int v=0; v<MAX; v++) while(qreq[v]) {
    int wl = v;
    while(qmay[wl-1]) {wl--; qmay[wl]--; }
    int wr = v;
    while(wr-wl < len) {
      if(qreq[wr]) qreq[wr]--;
      else if(qmay[wr]) qmay[wr]--;
      else return false;
      wr++;
      }
    while(qreq[wr]) { qreq[wr]--; qmay[wr]++; wr++; }
    // printf("%d-%d\n", wl, wr);
    }
  return true;
  }

bool solved = false;

void solverec(int len, int pos) {
  while(qty[pos] == 0 && pos < MAX) pos++;
  if(pos == MAX) {
    solved = true;
    return;
    }
  int opos = pos;
  while(qty[opos]) {
    qty[opos]--;
    opos++;
    if(opos-pos >= len) solverec(len, pos);
    }
  while(opos > pos) { opos--; qty[opos]++; }
  }

void solveCase() {
  int res = 0;

  scanf("%d", &N);
  for(int i=0; i<MAX; i++) qty[i] = 0;
  for(int i=0; i<N; i++) { 
    int K;
    scanf("%d", &K);
    qty[K]++;
    }
  
  int best = 1;
  for(int i=1; i<=MAX; i++) if(solve(i)) best = i; else break;
  
  int b2 = 1;
  for(int i=1; i<=20; i++) {
    solved = false;
    solverec(i, 0);
    if(solved) b2 = i;
    }
  
  if(0) if(best != b2) {
    for(int i=0; i<MAX; i++) if(qty[i]) printf("%dx%d ", qty[i], i);
    printf("\n");
    printf("best=%d b2=%d\n", best, b2);
    }

  best = b2;
  if(N == 0) best = 0;
  
  // proceed
  
  printf("Case #%d: %d\n", cnum, best);
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
