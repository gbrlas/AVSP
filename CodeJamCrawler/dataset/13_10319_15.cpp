#include<iostream>
#include<queue>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<string>
#include<cstring>
#include<map>
#include<numeric>
#include<sstream>
#include<cmath>
using namespace std;
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).end,(v).begin
#define pb push_back
#define f(i,x,y) for(int i=x;i<y;i++)
#define FOR(it,A) for(typeof A.begin() it = A.begin();it!=A.end();it++)
#define sqr(x) (x)*(x)
#define mp make_pair
#define clr(x,y) memset(x,y,sizeof x)
typedef pair<long,long> pii;
typedef long long ll;
typedef long double ld;
#define  mod 1000002013LL

pii Topi[3333]; 
int top = 0;
void pr(vector <pii> v){
	f(i,0,v.size())cout<<v[i].first<<" "<<v[i].second<<endl;
	cout<<endl;
}
bool com(pii A, pii B) {
	if(A.first!=B.first)	return A.first<B.first;
	return A.second>B.second;
}


int main(){
	int cases,o,e,p,n,m;
	cin>>cases;
	f(t,1,cases+1){
		//cout<<n<<" "<<m<<endl;
		cin >> n >> m;
		vector<pii> todos;
		ll inicio = 0, fin = 0;
		f(i,0,m) {
			cin>>o>>e>>p;
			todos.pb(pii(o,p));
			todos.pb(pii(e,-p));
			inicio += sqr(e-o) * p % mod;
		}
		sort(all(todos), com);
		top = 1;
		//cout<<todos.size()<<endl;
		//pr();
		f(i,0,todos.size()) {
			if (todos[i].second > 0) {
				Topi[top++] = todos[i];
			} else {
				while(Topi[top-1].second+ todos[i].second <= 0) {
					fin += sqr(todos[i].first - Topi[top-1].first) * Topi[top-1].second % mod;
					todos[i].second += Topi[top-1].second;
					top--;
					if (todos[i].second == 0) break;
				}
				Topi[top-1].second += todos[i].second;
				fin += sqr(todos[i].first - Topi[top-1].first) * -todos[i].second % mod;
			}
		}
		inicio %= mod;
		fin %= mod;
		ll res = fin - inicio + mod;
		if (res&1) res += mod;
		res/=2;
		res %= mod;

		cout<<"Case #"<<t<<": ";
		cout << res << endl;

	//poner re
	}
	return 0;

}

/*

	3
6 2
1 3 1
3 6 1
6 2
1 3 2
4 6 1
10 2
1 7 2
6 9 1*/

