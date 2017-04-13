import std.stdio;
import std.string;
import std.algorithm;
import std.typecons;
import std.bigint;
import std.conv;
import std.math;
import std.random;
import std.exception;
import std.bitmanip;

void init(int test) {
	writef("Case #%s: ", test);
}
bool less(int a, int b) {
	return a < b;
}
bool great(int a, int b) {
	return a > b;
}

void solve(int test) {
	int n;
	readf(" %s", &n);
	int[] a = new int[n];
	foreach (i; 0 .. n) {
		readf(" %s", &a[i]);
	}
	
	int mx = -1;
	foreach (int x; a) mx = max(mx, x);

	int ans = int.max;
	foreach (i; 0 .. n) {
		if (a[i] == mx) {
			int[] c = a[0 .. i] ~ a[i + 1 .. n];
			int m = n - 1;
			for (int mask = 0; mask < (1 << m); mask++) {
				BitArray b;
				b.init([mask], m);
				int cnt = calcInv!less(b);
				int[] z;
				int[] o;
				foreach (j; 0 .. m) {
					if ((i > j && b[j]) ||
						(j >= i && !b[j])) {
						
						++cnt;
					}
					if (b[j]) {
						o ~= c[j];
					} else {
						z ~= c[j];
					}
				}
				cnt += calcInv!less(z);
				cnt += calcInv!great(o);
				ans = min(ans, cnt);
			}
			break;
		}
	}
	
	writeln(ans);
}

int calcInv(alias pred, T)(T a) {
	int ans = 0;
	for (int i = 0; i < a.length; i++) {
		for (int j = i + 1; j < a.length; j++) {
			if (pred(a[j], a[i])) ans++;
		}
	}
	
	return ans;
}

int calc(int[] a, int pos) {
	return calcInv!less(a[0 .. pos]) + calcInv!great(a[pos + 1 .. $]);
}

void main() {
    string name = "B-small";
    string path = "";

    stdin = File(path ~ name ~ ".in", "r");
    stdout = File(path ~ name ~ ".out", "w");

    int testCases;
    readf(" %s", &testCases);

    foreach(testCase; 1..testCases + 1) {
		init(testCase);
		solve(testCase);
    }
}
