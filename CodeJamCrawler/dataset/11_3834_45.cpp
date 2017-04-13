#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
const int MXN = 126;

char a[MXN];
int x[MXN];
long long t[MXN];
long long ans;
int m;

void search (int k, long long s) {
	if (k >= m) {
		long long t = (long long)(sqrt (s) + 1e-8);
		if (t * t == s) {
			ans = s;
			//cout << s << endl;
		}
		return;
	}
	search (k + 1, s + t[x[k]]);
	search (k + 1, s);
}
void output (long long s) {
	if (s <= 1)
		cout << s;
	else {
		output (s / 2);
		cout << s % 2;
	}
}

int main () {
    freopen ("D-small-attempt0.in", "r", stdin);
    freopen ("out.txt", "w", stdout);
    int cn;
    scanf ("%d", &cn);
    for (int ci = 0; ci < cn; ci ++) {
		scanf ("%s", a);
		int n = strlen (a);
		for (int i = 0; i < n / 2; i++) 
			swap (a[i], a[n - i - 1]);
		m = 0;
		t[0] = 1;
		for (int i = 1; i <= 60; i++)
			t[i] = t[i - 1] * 2;
		long long s = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] == '?') {
				x[m] = i;
				m ++;
			} else
				s += t[i] * (a[i] - '0');
		}
		//cout << s << endl;
		search (0, s);
        printf ("Case #%d: ", ci + 1);
        output (ans);
        cout << endl;
    }
    return 0;
}
