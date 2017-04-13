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

int st[110][110];

int main(){
    ios_base::sync_with_stdio(false);
    freopen("A-small-1.in", "r", stdin);
    freopen("A-small-1.out", "w", stdout);
    int T,N;
    cin>>T;
    int ok;
    rep(i,0,T){
    	memset(st,0,sizeof(st));
        string test;
        vector<string> use;
        vector<int> idx;
        rep(j,0,2){
            use.pb("");
            idx.pb(0);
        }
        cin>>N;
        rep(j,0,N){
            cin>>test;
            rep(k,0,test.length()){
                if(k==0){
                    use[j]+=test[k];
                    st[j][idx[j]]=1;
                }else{
                    if(test[k]==test[k-1]){
                        st[j][idx[j]]++;
                    }else{
                        use[j]+=test[k];
                        idx[j]++;
                        st[j][idx[j]]=1;
                    }
                }
            }
        }
        ok=1;
        ll re;
        // cout<<use[0]<<endl;
        // cout<<use[1]<<endl;
        // cout<<idx[0]<<endl;
        // cout<<idx[1]<<endl;
        if(use[0]!=use[1]){
            ok=0;
        }else{
            re=0;
            rep(j,0,use[0].length()){
                re+=fabs(st[0][j]-st[1][j]);
                // cout<<st[0][j]<<" "<<st[1][j]<<endl;
            }
        }
    	cout<<"Case #"<<i+1<<": ";
    	if(!ok){
    		cout<<"Fegla Won"<<endl;
    	}else{
    		cout<<re<<endl;	
    	}
    	
    }
	return 0;
}
