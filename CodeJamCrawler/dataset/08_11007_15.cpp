#include <iostream>
#include <vector>
#include <map>

using namespace std;
#define ALL(C) (C).begin(), (C).end()
#define RALL(C) (C).rbegin(), (C).rend()
#define FOR(i,n) for(int i=0; i<(n); ++i)

typedef vector<int> vi;

int main()
{
int n; cin>>n;

FOR(_i,n) {
	int p,k,l; cin>>p>>k>>l;
	vi freq(l);
	FOR(i,l) cin>>freq[i];
	sort(RALL(freq));
	map<int,int> used;
	used[1] = k;
	long long res=0;
	int imposible = 0;
	FOR(i,l) {
		int count = used.begin()->first;
		int keys = used.begin()->second;
		res += freq[i] * count;
		--keys;
		if (keys == 0) {
			used.erase(used.find(count));
		} else {
			--used[count];
		}
		++used[count+1];
	}
	printf("Case #%d: %d\n", _i+1,res);
}
}
