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
#define M 100001
#define foreach(v, c)  for( typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v)
int arr[201][201];
int brr[201][201];
int main() {
	int t, n, m;
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	cin >> t;
	forall(l, 1, t+1){
		cin >> n >> m;
		forall(i, 0, n) {
			forall(j, 0, m) {
				cin >> arr[i][j];
				brr[i][j] = 100;
			}
		}
		
	
		forall(i, 0, n) {
			int ma = *max_element(arr[i], arr[i]+m);
			forall(j, 0, m) {
				if(brr[i][j] > ma)
					brr[i][j] = ma;
			}
		}

		forall(i, 0, m) {
			int ma = -1;
			forall(j, 0, n) 
				ma = max(ma, arr[j][i]);
		
			forall(j, 0, n) {
				if(brr[j][i] > ma)
					brr[j][i] = ma;
			}
		}

		bool flag = 0;
		
		forall(i, 0, n) {
			forall(j, 0, m) {
				// cout<< brr[i][j]  <<" ";
				if(arr[i][j] != brr[i][j])
					flag = 1;
			}
			// cout <<endl;
		}
		
		cout  << "Case #"<<l <<": ";
		if(flag) {
			cout << "NO" <<endl;
		}
		else {
			cout <<"YES" <<endl;
		}
	}
	return 0;
}