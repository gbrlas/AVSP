#include <string>
#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <cstdio>
#include <utility>
#include <cctype>
#include <queue>
#include <deque>
#include <cstring>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstring>

using namespace std;

#define X first
#define INF 1000000000
#define Y second
#define For(A,B) for(int A=0;A<B.size();++A)
#define ll long long
#define ld long double
#define PB push_back
#define sz size()
#define eps 0.0000001 
#define V second
#define P first

int main() {
	//freopen("in.txt", "r", stdin);
	freopen("C-small-attempt.in", "r", stdin);
	freopen("C-small-attempt.out", "w", stdout);
	int t;
	scanf("%d",&t);
	for(int tt=0;tt<t;++tt){
		int n,l,h;
		cin >> n >> l >> h;
		vector<int> m(n);
		for(int i=0;i<n;++i){
			cin >> m[i];
		}
		sort(m.begin(),m.end());
		bool fl=true;
		int res=0;
		for(int i=l;i<=h;++i){
			fl = true;
			for(int j=0;j<m.size() && fl;++j){
				if ( i % m[j] !=0 && m[j] % i !=0) fl = false;
			}
			if (fl){
				res=i;
				break;
			}
		}
		cout << "Case #"<< tt+1 << ": ";
		if(fl){
			cout << res << endl;
		} else {
			cout << "NO" << endl;	
		}
	}
	return 0;

	return 0;
}