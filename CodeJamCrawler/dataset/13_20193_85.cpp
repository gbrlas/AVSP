#include <iostream>
#include <cstring>
#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> num;

char buf[100];
bool valid(long long i) {
	sprintf(buf, "%lld", i);
	int len = strlen(buf);
	bool ok = true;
	for (int j = 0, k = len - 1; j < k; ++j, --k) {
		if (buf[j] != buf[k]) {
			ok = false;
			break;
		}
	}
	return ok;
}

int main()
{
	for (long long i = 1; i <= 1e7; ++i) {
		if (valid(i) && valid(i * i)) {
			num.push_back(i * i);
		}
	}
	//for_each(num.begin(), num.end(), [] (long long v) {cout << v << endl;});
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; ++t) {
		long long a, b;
		scanf("%lld%lld", &a, &b);
		auto it = lower_bound(num.begin(), num.end(), a);
		auto it2 = upper_bound(num.begin(), num.end(), b);
		printf("Case #%d: %d\n", t, it2 - it);
	}
	return 0;
}
