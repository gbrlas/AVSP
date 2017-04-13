#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>

#define LL long long

using namespace std;

inline string add(string a, string b) {
	unsigned mak = max(a.length(), b.length());
	while (a.length() < mak)
		a = "0" + a;
	while (b.length() < mak)
		b = "0" + b;
	
	string ret = "";
	for (unsigned i = 0; i < mak; ++i) {
		if ((a[i] == '1' && b[i] == '0') || (a[i] == '0' && b[i] == '1'))
			ret = ret + '1';
		else
			ret = ret + '0';
	}
	return ret;
}

inline string convert(LL x) {
	string ret = "";
	while (x > 0) {
		ret = (char) ((x % 2) + 48) + ret;
		x /= 2;
	}
	return ret;
}

int N, M;
LL isi[1010];

int main () {
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		bool ok = true;
		LL nilai = 0;
		string res = "";
		scanf("%d", &M);
		for (int j = 0; j < M; ++j) {
			scanf("%lld", &isi[j]);
			res = add(res, convert(isi[j]));
		}
		int n = res.length();
		sort(isi, isi + M);
		for (int j = 1; j < M; ++j)
			nilai += isi[j];
		for (int j = 0; j < n && ok; ++j)
			if (res[j] != '0')
				ok = false;
		printf("Case #%d: ", i + 1);
		if (ok)
			printf("%lld\n", nilai);
		else
			puts("NO");
	}
}
