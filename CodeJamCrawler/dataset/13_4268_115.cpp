#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <climits>
#include <cctype>
#include <cmath>

using namespace std;

#define ill long long int
#define pii pair<int,int>
#define pb(x) push_back(x)
#define forall(i,a,n) for(int i=(a); i < (n); i++)
#define forev(i, a, n) for(int i = (a); i >= (n); i--)
#define fill(i,a) memset(i, a, sizeof(i))
#define V(x) vector<x>
#define vii vector<int>
#define sii set<int>
#define sz(a) a.size()
#define prnt(n) printf("%d\n", n)

#define M  100001
#define foreach(v, c)  for( typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v)


map<int, int> m;
int main()
{
	int t, k;
	bool o, x, dot;
	vector<string> v;

	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	cin >> t;
	forall(l, 1, t+1){
		v.clear();
		v.resize(4);
		forall(i, 0, 4) {
			cin >> v[i];
		}
		x = o = dot = 0;
		forall(i, 0, 4) {
			m.clear();
			forall(j, 0, 4) {
				m[v[i][j]]++;
			}
			if(m['X'] == 4 || (m['X'] == 3 && m['T'] == 1))
				x = 1;
			if(m['O'] == 4 || (m['O'] == 3 && m['T'] == 1))
				o = 1;
		}

		forall(i, 0, 4) {
			m.clear();
			forall(j, 0, 4) {
				m[v[j][i]]++;
			}

			if(m['X'] == 4 || (m['X'] == 3 && m['T'] == 1))
				x = 1;
			if(m['O'] == 4 || (m['O'] == 3 && m['T'] == 1))
				o = 1;
		}

		k = 0;
		m.clear();
		forall(i, 0, 4) {
			
			m[v[i][k]]++;
			// cout << v[i][k] << " ";
			if(m['X'] == 4 || (m['X'] == 3 && m['T'] == 1))
				x = 1;
			if(m['O'] == 4 || (m['O'] == 3 && m['T'] == 1))
				o = 1;	
			k++;
		}
		// cout << m['X'] <<" " << m['O'] <<endl;
		k = 3;
		m.clear();
		forall(i, 0, 4) {
			
			m[v[i][k]]++;
			// cout << v[i][k] << " ";
			if(m['X'] == 4 || (m['X'] == 3 && m['T'] == 1))
				x = 1;
			if(m['O'] == 4 || (m['O'] == 3 && m['T'] == 1))
				o = 1;	
			k--;
		}
		// cout << m['X'] <<" " << m['O'] <<endl;
		m.clear();
		forall(i, 0, 4) {
			forall(j, 0, 4) {
				m[v[i][j]]++;
			}
		}
		if(m['.'] >0) dot= 1;

		// cout<<o <<" " << x <<" " << dot <<endl;
		cout << "Case #"<<l<<": ";
		if(o) {
			cout <<"O won" <<endl;
		}
		else if(x) {
			cout <<"X won" <<endl;			
		}
		else if(dot) {
			cout <<"Game has not completed" <<endl;
		}
		else {
			cout << "Draw" <<endl;
		}
	}
}