using namespace std;
#include<algorithm>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<bitset>

#include<climits>
#include<cstring>
#include<cstdio>
#include<cmath>

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

#define MPI acos(-1)
#define fr(i,j,n) for(int i=j;i<n;++i)
#define FR(i,n) fr(i,0,n)
#define foreach(x,v) for(typeof (v).begin() x = (v).begin(); x!= (v).end(); x++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define RI(x) scanf("%d",&x)
#define DRI(x) int x;RI(x)
#define RII(x,y) scanf("%d%d",&x,&y)
#define DRII(x,y) int x,y;RII(x,y)
#define PI(x) printf("%d ",x)
#define PIS(x) printf("%d\n",x)
#define D(x) cout<< #x " = "<<(x)<<endl
#define Dd(x) printf("#x = %lf\n", x)
#define Dbg if(1)
#define PB push_back
#define MK make_pair
#define F first
#define S second

typedef long long ll;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<char> vc;

int MAXN=1000;

vll good;

bool is_pal(string s){
  for(int i=0,j=s.size()-1;i<s.size()/2;i++,j--)
    if(s[i]!=s[j]) return false;

  return true;
}

int main(){
  for(ll p=1;p*p<=MAXN;p++){
    ll t = p*p;
    if( is_pal(toStr(t)) && is_pal(toStr(p)) ) good.PB(t);
  }

  int T;
  cin >> T;
  FR(x,T){
    int res = 0, a , b;
    cin >> a >> b;
    FR(i,good.size()) if(good[i]>=a && good[i]<=b) res++;
    cout << "Case #" << x+1 << ": " << res << endl;
  }
}

