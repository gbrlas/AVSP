#include <cstdio>
#include <map>
#include <iostream>
using namespace std;
map<char, char> m;
void parseMap (string x, string y) {
	for (int i = 0, n = x.length(); i < n; i++) {
		m[x[i]] = y[i];
	}
}
string deParse (string x) {
	for (int i = 0, n = x.length(); i < n; i++) x[i] = m[x[i]];
	return x;
}
int main () {
	parseMap("ejp mysljylc kd kxveddknmc re jsicpdrysi", "our language is impossible to understand");
	parseMap("rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd", "there are twenty six factorial possibilities");
	parseMap("de kr kd eoya kw aej tysr re ujdr lkgc jvqz", "so it is okay if you want to just give upzq");
	int n;
	cin >> n;
	string x;
	for (int i = 0; i <= n; i++) {
		getline(cin, x);
		if (i != 0) cout << "Case #" << i << ": " << deParse(x) << endl;
	}
	return 0;
}
