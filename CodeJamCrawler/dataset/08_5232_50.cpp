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

#define P 10007

int countP(int a) {
  if(a == 0) return 0;
  else return (a / P) + countP(a / P);
  }

int factab[P];
int invtab[P];

int pow(int a, int n) {
  exit(5);
  if(n == 0) return 1;
  if(n == 1) return a;
  int k = pow(a, n/2);
  k *= k;
  k %= P;
  if(a&1) { k *= a; k %= P; }
  return k;
  }

int facP(int a) {
  if(a < P)
    return factab[a];
  return (pow(factab[P-1], a/P) * facP(a/P)) % P;
  }

void prep() {
  factab[0] = 1;
  FOR(y,1,P) {
    factab[y] = factab[y-1] * y;
    factab[y] %= P;
    }
  
  FOR(y,1,P) FOR(x,1,P) if((x*y)%P == 1) invtab[y] = x;
  }

int sways(int x, int y) {
  if((x+y) % 3 != 0) return 0;
  if(x < 0) return 0;
  if(y < 0) return 0;

  if(2*x < y) return 0;
  if(2*y < x) return 0;
  
  int N = (x+y) / 3;
  int K = x-N;
  
  if(countP(N) > countP(K) + countP(N-K)) {
    exit(9);
    return 0;
    }
  
  int a = facP(N);
  int b = facP(K);
  int c = facP(N-K);
  b *= c; b %= P;
  a *= invtab[b]; a %= P;
  return a;  
  }

void solveCase(int cnum) {
  int res = 0;
  
  int W, H, R;
  int rx[60], ry[60];
  
  string s;
  s = getLine();
  sscanf(s.c_str(), "%d%d%d", &W, &H, &R);
  
  FOR(r,0,R) {
    s = getLine();
    sscanf(s.c_str(), "%d%d", &rx[r], &ry[r]);
    }
  
  int dp[200][200];
  FOR(y,0,200) FOR(x,0,200) {
    dp[y][x] = 0;
    FOR(r,0,R) if(ry[r] == y && rx[r] == x) {
      goto nextxy;
      }
    if(x >= 2 && y >= 1) dp[y][x] += dp[y-1][x-2];
    if(x >= 1 && y >= 2) dp[y][x] += dp[y-2][x-1];
    if(x == 1 && y == 1) dp[y][x] = 1;
    dp[y][x] %= P;
    nextxy: ;
    }
  
  rx[R] = 1; ry[R] = 1;
  rx[R+1] = W; ry[R+1] = H;
  R += 2;
  
  FOR(it,0,R) FOR(a,0,R) FOR(b,0,a) if(rx[b] > rx[a] || ((rx[b] == rx[a]) && (ry[b] > ry[a]))) {
    swap(rx[a], rx[b]);
    swap(ry[a], ry[b]);
    }
  
  FOR(set,0,1<<R) {
    if(set & 1) if(set & (1<<(R-1))) {
      int rockat = 0;
      int rocks = 0;
      int mul = 1;
      FOR(u,1,R) if(set & (1<<u)) {
//      if(cnum == 74) printf("[%d,%d]-[%d,%d] (%d,%d)\n", rx[rockat], ry[rockat], rx[u], ry[u], rx[u] - rx[rockat], ry[u] - ry[rockat]);
        mul *= sways(rx[u] - rx[rockat], ry[u] - ry[rockat]);
        mul %= P;
        rocks++;
        rockat = u;
        }
      if(rockat != R-1) continue;
      if(rocks&1) res += mul; else res += P-mul;
//    if(cnum == 74) printf("Set: %04x mul: %d\n", set, mul);
      res %= P;
      
      }
    }
  
  if(dp[H][W] != res) {
    printf("Error! (%d)\n", dp[H][W]);
    FOR(u,0,R) printf("%d %d\n", rx[u], ry[u]);
    }

  printf("Case #%d: %d\n", cnum+1, res, W,H,R);
  }

int main() {
  int N;
  prep();
  
/*  FOR(y,0,20) { FOR(x,0,20) {
    printf("%3d", sways(y-10, x-10));} printf("\n");
    }
  return 0; */
  
  string Nstr = getLine();
  N = atoi(Nstr.c_str());
  FOR(cnum,0,N) 
    solveCase(cnum);
  return 0;
  }
