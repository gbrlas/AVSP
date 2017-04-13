#include <algorithm>
#include <iostream>
#include <complex>
#include <numeric>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <map>
#include <set>

#include <gmpxx.h>

using namespace std;

#define all(a)      (a).begin(),(a).end()
#define sz(a)       int((a).size())
#define FOR(i,a,b)  for(int i=a;i<b;++i)
#define REP(i,n)    FOR(i,0,n)
#define UN(v)       sort(all(v)),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)     memset(a,b,sizeof a)
#define pb          push_back
#define X           first
#define Y           second

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef complex<double> point;

int n;
mpz_class t[1024];

void Solve(){
    cin >> n;
    REP (i, n) cin >> t[i];
    mpz_class y, T;
    REP (i, n - 1)
		mpz_gcd(T.get_mpz_t(), T.get_mpz_t(), mpz_class(t[i + 1] - t[i]).get_mpz_t());	
	REP (i, n) 
		y = max(y, mpz_class((T - (t[i] % T)) % T));
	cout << y << endl;
}

int main(){
    freopen("x.in","r",stdin);
    freopen("x.out","w",stdout);
    int a=0,b;
    for(cin>>b;a++<b;Solve())printf("Case #%d: ",a);
    return 0;
}
