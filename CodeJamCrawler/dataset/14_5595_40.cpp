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

void solve(int test) {
	int n, x;
	readf(" %s %s", &n, &x);
	int[] a = new int[n];
	foreach (i; 0 .. n) {
		readf(" %s", &a[i]);
	}
	
	sort(a);
	
	int l = 0;
	int r = n - 1;
	
	int ans = 0;
	while (l < r) {
		if (a[r] + a[l] <= x) {
			++ans;
			++l;
			--r;
		} else {
			++ans;
			--r;
		}
	}
	
	if (l == r) {
		++ans;
	}
	
	writeln(ans);
}

void main() {
    string name = "A-small";
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
