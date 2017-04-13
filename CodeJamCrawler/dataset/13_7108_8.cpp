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
#define D(x) cout<< #x " = "<<(x)<<endl
#define PB push_back
#define MK make_pair
#define N 2000

typedef long long ll;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair <int,int> pii;
typedef pair <double,double> pdd;

bool check(char c){
	string vowels = "aeiou";
	FR(i,5) if(c==vowels[i]) return true;
	return false;
}


ll f(string s, int n){
	ll ans = 0;
	FR(i,s.size()){
		ll mmax = 0;
		FR(j,s.size()){
			ll c = 0;
			fr(k,i,j+1){
				if( !check(s[k]) ) c++;
				else c = 0;
				mmax = c > mmax ? c : mmax;
			}
//			D(i);D(j);D(mmax);
			if(mmax>=n) {
//				fr(k,i,j+1) cout << s[k];
//				cout << endl;
				ans++;
			}
		}
	}
	return ans;
}


int main(){
	int T,n,tc=0;
	string s;
	cin >> T;
	while(T--){
		cin >> s >> n;
		cout << "Case #"<< ++tc << ": " << f(s,n) << endl;
	}

	return 0;
}
