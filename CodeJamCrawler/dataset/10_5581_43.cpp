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

int N, cnum;

//Eryx

// !FDI

int board[200][200];

int max4(int a, int b, int c, int d) { return max(max(a,b), max(c,d)); }

void solveCase() {
  int res = 0;

  int R;
  
  FOR(y,0,200) FOR(x,0,200) board[y][x] = 0;
  
  err = scanf("%d", &R);
  
  int X0,Y0,X1,Y1;
  
  if(1) {
    FOR(r,0,R) {
      err = scanf("%d%d%d%d", &X0, &Y0, &X1, &Y1);
    
      for(int x=X0; x<=X1; x++)
      for(int y=Y0; y<=Y1; y++)
        board[y][x] = 1;
      }
    
    if(0) if(cnum == 59)
      FOR(y,1,105) {
        FOR(x,1,105) printf("%d", board[y][x]);
        printf("\n");
        }      

    int rounds = 0;
    
    bool alive = true;
    while(alive) {
      alive = false;
      rounds++;
      
      for(int x=100; x>=1; x--)
      for(int y=100; y>=1; y--) {
        if(board[y-1][x] && board[y][x-1])
          board[y][x] = 1;
        else if(board[y-1][x] || board[y][x-1])
          { }
        else board[y][x] = 0;
        if(board[y][x]) alive = true;
        }
      }
    
    printf("Case #%d: %d\n", cnum, rounds);
    return;
    }
  
  FOR(r,0,R) {
    err = scanf("%d%d%d%d", &X0, &Y0, &X1, &Y1);
    
    for(int x=X0; x<=X1; x++)
    for(int y=Y0; y<=Y1; y++)
      board[y][101-x] = 1;
    
    }

  int maxv = 0;
  FOR(y,1,105) FOR(x,1,105) {
    if(board[y][x] == 1) {
      board[y][x] = max4(1, 1 + board[y][x-1], 1 + board[y-1][x], 1 + board[y-1][x-1]);
      if(board[y][x] > maxv) maxv = board[y][x];
      }
    }
  printf("Case #%d: %d\n", cnum, maxv);
  }

int main() {

  err=scanf("%d", &N);

  for(cnum=1; cnum<=N; cnum++)
    solveCase();
    
  // finish
  return 0;
  }

// This solution includes hidden routines to solve test cases in separate
// processes in order to make it faster. I will update them to run on a
// cluster if I get one ;)
