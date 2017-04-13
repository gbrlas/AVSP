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

void solveCase(int cnum) {
  int res = 0;
  
  int Flavors = getNum();
  int Custom = getNum();
  
  vector<vi> likedUnmaltedBy;
  vi unmalted;
  vi malted;

  vi isMalted;
  
//printf("a\n"); fflush(stdout);
  
  isMalted.resize(Flavors);
  FOR(x,0,Flavors) isMalted[x] = 0;
  
  likedUnmaltedBy.resize(Flavors);
  unmalted.resize(Custom);
  malted.resize(Custom);
  
  for(int y=0; y<Custom; y++) {
//  printf("y%d\n",y); fflush(stdout);
    malted[y] = -1;
    unmalted[y] = 0;
    vi data = parsevi(getLine());
//  FOR(u,0,Size(data)) printf(" %d", data[u]); printf("\n");
    for(int u=1; u<Size(data); u+=2) {
      data[u]--;
//    printf("(%d,%d)\n", data[u], data[u+1]);
      if(data[u+1] == 1)
        malted[y] = data[u];
      else {
        unmalted[y]++;
        likedUnmaltedBy[data[u]].push_back(y);
        }
      }
//  printf("M%d U%d\n", malted[y], unmalted[y]);
    }
  
//printf("z\n"); fflush(stdout);
  vi zeros;
  FOR(y,0,Custom) if(unmalted[y] == 0) zeros.push_back(y);
  
  int id = 0;
  while(id < Size(zeros)) {
    int y = zeros[id];
//  printf("!y%d\n",y); fflush(stdout);
    if(malted[y] == -1) {
      printf("Case #%d: IMPOSSIBLE\n", cnum+1);
      return;
      }
    isMalted[malted[y]] = 1;
    vi& v(likedUnmaltedBy[malted[y]]);
    FOR(yi,0,Size(v)) {
      int y2 = v[yi];
//    printf("dec %d\n", y2);
      unmalted[y2]--;
      if(unmalted[y2] == 0) zeros.push_back(y2);
      }
    id++;
    }  
  
  printf("Case #%d:", cnum+1);
  FOR(x,0,Flavors) printf(" %d", isMalted[x]);
  printf("\n");
  }

int main() {
  int N;
  string Nstr = getLine();
  N = atoi(Nstr.c_str());
  FOR(cnum,0,N) 
    solveCase(cnum);
  return 0;
  }
