#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

template<class T> inline void checkmin(T &a,T b){if(b<a) a=b;}
template<class T> inline void checkmax(T &a,T b){if(b>a) a=b;}
template<class T> inline T gcd(T a,T b){return a==0?b:gcd(b%a,a);}
template<class T> inline int countbit(T n){return n==0?0:(1+countbit(n&(n-1)));}
template<class T> inline void pout(T A[],int n){cout<<"{";for (int i=0;i<n;i++)cout<<A[i]<<", ";cout<<"}\n";}
template<class T> inline void pout(vector<T> A,int n=-1){if (n==-1) n=A.size();cout<<"{";for (int i=0;i<n;i++)cout<<A[i]<<", ";cout<<"}\n";}

#define REP(i,n) for(i=0;i<(n);++i)
#define FOR(i,cs,h) for(i=(cs);i<=(h);++i)
#define FORD(i,h,cs) for(i=(h);i>=(cs);--i)
#define FORIT(a,aa) for(a=aa.begin();a!=aa.end();++a)
#define split(str) {vs.clear();istringstream sss(str);while(sss>>(str))vs.push_back(str);}
#define Sz(s) int((s).size())
#define All(s) (s).begin(),(s).end()
#define Fill(s,v) memset(s,v,sizeof(s))

typedef long long LL;
typedef long double LD;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef vector<LL> VLL;
typedef vector<LD> VLD;

int main(){
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A.out", "w", stdout);

	int t, T;
	int i;
	cin>>T;

	int longestLen[10000], l[10000], d[10000], D, N;

	REP(t, T){
		cout<<"Case #"<<t+1<<": ";

		Fill(longestLen, 0);

		cin>>N;
		REP(i, N){
			cin>>d[i]>>l[i];
		}
		cin>>D;

		bool ret = false;
		stack<PII> st;
		// start swing
		st.push(make_pair(0, 0));
		while(!st.empty() && !ret){
			int v = st.top().first;
			int p = st.top().second;
			st.pop();

			int len = abs(d[v] - p);

			if(len <= longestLen[v]) continue;
			longestLen[v] = len;

			int range = d[v] + len;
			if(D <= range){
				ret = true;
				break;
			}

			int* vP = lower_bound(d, d+N, p);
			for(int vS = vP - d; vS < N && d[vS] <= range; vS++){
				if(d[vS] < p) continue;
				int nextP;
				if(d[vS] - d[v] > 0){
					nextP = d[vS] - l[vS];
					if(nextP < d[v]) nextP = d[v];
				}
				else{
					nextP = d[vS] + l[vS];
					if(nextP > d[v]) nextP = d[v];
				}

				len = abs(d[vS] - nextP);
				if(len <= longestLen[vS]) continue;
				st.push(make_pair(vS, nextP));
			}
		}

		if(ret){
			cout<<"YES";
		}
		else{
			cout<<"NO";
		}
		cout<<endl;
	}
	return 0;
}



