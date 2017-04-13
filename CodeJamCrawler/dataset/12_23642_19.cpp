#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#include<iostream>
#include<sstream>
#include<set>
#include<cctype>
#include<cassert>
using namespace std;

#ifdef ONLINE_JUDGE

#define assert(x)
#define dbg(x)
#define trace()

#else

#define dbg(x) do { cout << "DEBUG, line " << __LINE__ << " (" << __func__ << "), " << #x << ": " << x << endl; } while(0)
#define trace() do { cout << "TRACE, line " << __LINE__ << " (" << __func__ << ")" << endl; } while(0)

#endif

const int M = 2000006;
const int N = 205;
const int INF = 10*M;

int m, //money
	f, //delivery fee
	n; //meals

int bestpr[M];
typedef pair<int,int>pii;
typedef long long LL;

void normalize(vector<pii>&meals){
	vector<pii>help = meals;
	sort(help.begin(), help.end());
	int siz = unique(help.begin(), help.end()) - help.begin();
	while(help.size()>siz) help.pop_back();

	meals.clear();
	for(int i=0; i<help.size(); i++){
		bool good = true;
		for(int j=0; j<help.size(); j++) if(i!=j) {
			assert(help[i].first!=help[j].first || help[i].second!=help[j].second);
			if(help[j].first>=help[i].first){ //at least this many days
				if(help[j].second<=help[i].second) { //better price
					good = false;
				}
			}
		}
		if(good) meals.push_back(help[i]);
	}
	sort(meals.begin(), meals.end());
}

int algo(LL k, const vector<pii>&meals){
	LL cash = m - k*f;
	int s = meals.size();
	int res = 0;
	int prev = 0;
	for(int i=0; i<s; i++){
		int mx = min(cash/meals[i].second, k*(meals[i].first-prev));
		if(mx==0) break;
		res+=mx;
		cash -= mx*meals[i].second;
		prev = meals[i].first;
	}
	return res;
}

void solve(){
	vector<pair<int,int> >meals; // (days, price)
	scanf("%d %d %d", &m, &f, &n);

	for(int i=0; i<=m; i++) bestpr[i] = INF;

	for(int i=0; i<n; i++){
		int t,price;
		scanf("%d %d", &price, &t); t++;
		meals.push_back(make_pair(t,price));
	}
	normalize(meals);
	//printf("normalized:\n");
	//for(int i=0; i<meals.size(); i++) printf("%d %d\n",meals[i].first, meals[i].second);
	for(int i=0; i+1<meals.size(); i++) assert(meals[i].first < meals[i+1].first);
	for(int i=0; i+1<meals.size(); i++) assert(meals[i].second < meals[i+1].second);

	int res = 0;
	for(int k = 1; k*f<=m; k++){
		//if(k%1000==0) printf("%d\n",k);
		res = max(res, algo(k, meals));
	}
	printf("%d\n",res);
}

int main(){
	int t;
	scanf("%d",&t);
	for(int tc=1; tc<=t; tc++){
		printf("Case #%d: ", tc);
		solve();
	}
}
