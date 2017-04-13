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
#define INF INT_MAX
#define gc getchar_unlocked
#define M  100001
#define foreach(v, c)  for( typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v)

vector<int> palin;
bool isPalin(ill num) {
	stringstream ss;
	string s;
	ss <<num;
	ss >> s;
	int j = s.size()-1;
	forall(i, 0, s.size()) {
		if(s[i] != s[j])
			return false;
		j--;
	}
	return true;
}
int main()
{
	forall(i, 1, 10000001) {
		if(isPalin(i) && isPalin((long long)i*i)) {
			palin.pb((long long)i*i);
		}
	}
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	int t, a, b;
	cin>> t;
	forall(i, 1, t+1){
		cin >> a >> b;
		cout <<"Case #"<<i <<": ";
		cout<<upper_bound(palin.begin(), palin.end(), b) - lower_bound(palin.begin(), palin.end(), a)<<endl;
	}
}