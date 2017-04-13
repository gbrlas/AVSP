/* ############################################################################
 * START OF HEADER 
 * ############################################################################
 */
#include<cstdio>
#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cstdlib>
#include<cmath>
#include<cassert>
#include<ctime>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<list>
#include<set>
#include<map>
using namespace std;
 
#define LL long long
#define LD long double

#define sc(x)  scanf("%c",&x) //char
#define si(x)  scanf("%d",&x) //int
#define sf(x)  scanf("%f",&x) //float
#define sl(x)  scanf("%I64d",&x) //int64_
#define sd(x)  scanf("%lf",&x) //double
#define sld(x) scanf("%Lf",&x) //long double
#define slld(x) scanf("%lld",&x) //long long int
#define ss(x)  scanf("%s",x) // string

#define pc(x)  printf("%c",x)
#define pi(x)  printf("%d ",x)
#define pf(x)  printf("%f ",x)
#define pl(x)  printf("%I64d ",x)
#define pd(x)  printf("%lf ",x)
#define pld(x) printf("%Lf ",x)
#define plldn(x) printf("%lldn", x);
#define ps(x) printf("%s", x);

#define pin(x)  printf("%d\n",x)
#define pln(x)  printf("%I64d\n",x)
#define pfn(x)  printf("%f\n",x)
#define pdn(x)  printf("%lf\n",x)
#define pldn(x) printf("%Lf\n",x)
#define plld(x) printf("%lld\n", x);
#define psn(x)  printf("%s\n",x)

#define pn() printf("\n")
#define _p() printf(" ")

#define MODVAL 1000000007

#define FORab(i,a,b) for(int i=a;i<=b;i++)
#define REVab(i,a,b) for(int i=a;i>=b;i--)
#define FORn(i,n) for(i=0;i<n;i++)
#define REVn(i,n) for(int i=n;i>=0;i--)
#define FORSTL(it, a) for(it=a.begin(); it!=a.end(); it++)
#define REVSTL(it, a) for(it=a.end(); it!=a.begin(); it--)

#define MEM(a,v) memset(a,v,sizeof(a))
#define MAX(x,y) (x)>(y)?(x):(y)
#define MIN(x,y) (x)<(y)?(x):(y)
#define pb push_back
#define pob pop_back
#define b() begin()
#define e() end()
#define s() size()
#define cl() clear()
#define fi first
#define se second
#define INF (1000000000)
#define SZ 100000
#define MOD (1<<30)

#define VS vector<string>
#define VI vector<int>
#define VF vector<float>
#define VD vector<double>
#define MII map<int,int>
#define MIS map<int, string>
#define MSI map<string, int> 
#define MSS map<string, string>

#define VSI vector<string>::iterator
#define VII vector<int>:iterator
#define VFI vector<float>::iterator
#define VDI vector<double>::iterator
#define MIII map<int,int>::iterator
#define MISI map<int, string>::iterator
#define MSII map<string, int>::iterator 
#define MSSI map<string, string>::iterator
#define print_array(x,n) for(int i=0; i<n; i++) { cout << x[i] << endl; }
#define TEST int T;scanf("%d",&T);while(T--)
#define CASES int N;scanf("%d",&N);while(N--)

/* ############################################################################
 * END OF HEADER 
 * ############################################################################
*/
#define NO_WIN 0
#define X_WIN -1
#define O_WIN 1

int main() {
  //freopen("in.txt", "r", stdin);
  /* Row counters */
  int rx[4];
  int ro[4];
  int rt[4];
  /* COl counters */
  int cx[4];
  int co[4];
  int ct[4];
  /* Diag */
  vector<char> d1;
  vector<char> d2;
  int T;
  scanf("%d\n", &T);
  int test_num=1;
  while(T--) {
    d1.clear();
    d2.clear();
    memset(rx, 0, 4*sizeof(int));
    memset(ro, 0, 4*sizeof(int));
    memset(rt, 0, 4*sizeof(int));
    memset(cx, 0, 4*sizeof(int));
    memset(co, 0, 4*sizeof(int));
    memset(ct, 0, 4*sizeof(int));
    int tot_valid = 0;
    for(int i=0; i<4; i++) {
      char ip[5];
      scanf("%s\n", ip);
      for(int j=0; j<4; j++) {
        int c = ip[j];;
        if(c == 'X') {
          tot_valid++;
          rx[i]++;
          cx[j]++;
        } else if(c == 'O') {
          tot_valid++;
          ro[i]++;
          co[j]++;
        } else if(c == 'T') {
          tot_valid++;
          rt[i]++;
          ct[j]++;
        }
        if(i==j) {
          /* diag 1 */
          d1.pb(c);
        } else if( j == (3 - i)) {
          /* diag 2 */
          d2.pb(c);
        }
      }
    }
    int wins=NO_WIN;
    /* Row scan */
    for(int i=0; i<4; i++) {
      if(rx[i] + rt[i] == 4) {
        wins = X_WIN;
        break;
      } else if(ro[i] + rt[i] == 4) {
        wins = O_WIN;
        break;
      }
    }
    if(wins == NO_WIN) {
      for(int i=0; i<4; i++) {
        if(cx[i] + ct[i] == 4) {
          wins = X_WIN;
          break;
        } else if(co[i] + ct[i] == 4) {
          wins = O_WIN;
          break;
        }
      }
    }
    if(wins == NO_WIN) {
      /* diag 1 */
      int x, t, o;
      x = t = o = 0;
      for(int i=0; i<4; i++) {
        if(d1[i] == 'X') x++;
        else if(d1[i] == 'O') o++;
        else if(d1[i] == 'T') t++;
      }
      if(x+t == 4) {
        wins = X_WIN;
      } else if(o+t == 4) {
        wins = O_WIN;
      }
    }
    if(wins == NO_WIN) {
      /* diag 1 */
      int x, t, o;
      x = t = o = 0;
      for(int i=0; i<4; i++) {
        if(d2[i] == 'X') x++;
        else if(d2[i] == 'O') o++;
        else if(d2[i] == 'T') t++;
      }
      if(x+t == 4) {
        wins = X_WIN;
      } else if(o+t == 4) {
        wins = O_WIN;
      }
    }
    if(wins == X_WIN) {
      printf("Case #%d: X won\n", test_num++);
    } else if(wins == O_WIN) {
      printf("Case #%d: O won\n", test_num++);
    } else if(tot_valid == 16) {
      printf("Case #%d: Draw\n", test_num++);
    } else {
      printf("Case #%d: Game has not completed\n", test_num++);
    }
  }
}
