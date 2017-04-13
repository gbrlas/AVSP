#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <utility>
#include <cassert>

using namespace std;

typedef long double ld;

struct cmp : public binary_function<pair<pair<int,int>, int>, pair<pair<int,int>, int>, bool> {
	bool operator()(pair<pair<int,int>, int> x, pair<pair<int,int>, int> y) {
		if (x.first.first*y.first.second != x.first.second*y.first.first)
			return x.first.first*y.first.second < x.first.second*y.first.first;
		return x.second < y.second;
	}
};

int n;
int ti[1<<11];
int pr[1<<11];
pair<pair<int,int>, int> arr[1<<11];

int main(){
	int t; cin >> t;
	for (int zz = 1; zz <= t; zz++){
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> ti[i];
		for (int i = 0; i < n; i++)
			cin >> pr[i];
		for (int i = 0; i < n; i++)
			arr[i] = make_pair(make_pair(ti[i],pr[i]),i);
		sort(arr,arr+n,cmp());
		cout << "Case #" << zz << ":";
		for (int i = 0; i < n; i++)
			cout << " " << arr[i].second;
		cout << endl;
	}	
	
	return 0;
}
