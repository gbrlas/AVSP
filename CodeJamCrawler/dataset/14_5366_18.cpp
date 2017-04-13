#include <functional>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <numeric>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <string>
#include <cstdio>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <cmath>
#include <list>
#include <set>
#include <map>
#include <ctime>
#define pb push_back
#define mp make_pair
#define sz(a) (int)(a).size()
#define ms0(x) memset((x),0,sizeof(x))
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define rep(i,m,n) for(int i=(m),_end=(n);i < _end;++i)
#define repe(i,m,n) for(int i=(m), _end =(n);i <= _end;++i)
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
const int INF = (int) 1e9;
const long long INF64 = (long long) 1e18;
const long double eps = 1e-9;
const long double pi = 3.14159265358979323846;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    freopen("B-small-0.in", "r", stdin);
    freopen("B-small-0.out", "w", stdout);
    int T;
    cin>>T;
    rep(i,0,T){
    	int A,B,K;
    	cin>>A>>B>>K;
    	ll re=0;
    	rep(j,0,A){
    		rep(k,0,B){
    			if((j&k)<K) re++;
    		}
    	}
    	cout<<"Case #"<<i+1<<": "<<re<<endl;
    }
	return 0;
}