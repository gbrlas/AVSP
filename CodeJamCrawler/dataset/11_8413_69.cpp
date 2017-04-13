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

int N, Y, X, GS;

int gf[20000][2];
int knf[20000], knt[20000];
int deg[20000];
int bro[20000];

int doq[20000], qb, qe;

int enc(int x, int y) {
  while(x<0) x+=X;
  while(y<0) y+=Y;
  x %= X;
  y %= Y;
  return x + y * X;
  }

bool deb = false;

void disp() { 
  for(int i=0; i<GS; i++) printf("%d(%d) ", deg[i], bro[i]);
  printf("\n");
  }

int check() {

  if(deb) {printf("GS=%d\n", GS);
  for(int i=0; i<GS; i++) printf("%d %d %d\n", i, gf[i][0], gf[i][1]);
  //exit(1);
  }
  
  for(int i=0; i<GS; i++) deg[i] = 0, knf[i] = 0, knt[i] = 0, bro[i] = 0;
  for(int i=0; i<GS; i++) for(int j=0; j<2; j++) 
    deg[gf[i][j]]++, bro[gf[i][j]] ^= i;

  for(int i=0; i<GS; i++) if(deg[i] == 0) return 0;
  
  int res = 1;
  
#define P 1000003
  
  qb=0; qe=0;
  for(int i=0; i<GS; i++) if(deg[i] == 1) doq[qe++] = i;
  
  int scod = 0;
  
  while(scod < GS) {

    while(qb < qe) {
      
      int id = doq[qb++];
      deg[id] = 0;
      int fro = bro[id]; bro[id] = 0; knf[fro] = 1;
      int id2 = gf[fro][0] ^ gf[fro][1] ^ id;
      deg[id2]--;
      bro[id2] ^= fro; 
      if(deg[id2] == 0) return 0;
      if(deg[id2] == 1) doq[qe++] = id2;
      if(deb) printf("e1 %d (%d)\n", id, fro);
      if(deb) disp();
      }
    
    if(deg[scod] == 2) {
      res *= 2;
      res %= P;
      
      if(deb) printf("e2 %d\n", scod);

      for(int t=0; t<GS; t++) if((gf[t][0] == scod || gf[t][1] == scod) && knf[t] == 0) {
        int at = scod;
        int atf = t;
        do {
          if(deb) printf("%d -> %d\n", at, atf);
          deg[at] = 0; // bro[at] = 0;
          knf[atf] = 1;
          atf = bro[at] ^ atf;
          at = gf[atf][0] ^ gf[atf][1] ^ at;
          } while(at != scod);
        if(deb) disp();
        break;
        }
      }
    
    scod++;
    }

  return res;
  }

int slv(int at) {
  if(at == GS) return 1;
  int sum = 0;
  for(int j=0; j<2; j++)
    if(deg[gf[at][j]]) {
      deg[gf[at][j]] = 0;
      sum += slv(at+1);
      deg[gf[at][j]] = 1;
      }
  return sum;
  }

int solverec() {
  for(int i=0; i<GS; i++) deg[i] = 1;
  return slv(0);
  }

void solveCase() {
  int res = 0;

  scanf("%d%d", &Y, &X);
  
  for(int y=0; y<Y; y++) {
    char buf[200];
    scanf("%s", buf);
    
    for(int x=0; x<X; x++) switch(buf[x]) {
      case '-': 
        gf[enc(x,y)][0] =  enc(x+1, y);
        gf[enc(x,y)][1] =  enc(x-1, y);
        break;
      case '|':
        gf[enc(x,y)][0] =  enc(x, y-1);
        gf[enc(x,y)][1] =  enc(x, y+1);
        break;
      case '/':
        gf[enc(x,y)][0] =  enc(x+1, y-1);
        gf[enc(x,y)][1] =  enc(x-1, y+1);
        break;
      case '\\':
        gf[enc(x,y)][0] =  enc(x+1, y+1);
        gf[enc(x,y)][1] =  enc(x-1, y-1);
        break;
      }
    }
  
  GS = X*Y;
  // printf("GS = %d %d,%d\n", GS, X, Y);
  
  // proceed
  
  fprintf(stderr, "%d\n", cnum);
  
  if(0) if(check() != solverec()) {
    printf("VS %d %d %d\n", GS, check(), solverec());
    deb = true;
    check();
    exit(1);
    }
  
  printf("Case #%d: %d\n", cnum, check());
  // printf("Case #%d: %d\n", cnum, solverec());
  // exit(1);
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
