import std.stdio;
import std.string;
import std.algorithm;
import std.typecons;
import std.bigint;
import std.conv;
import std.math;
import std.random;
import std.range;
import std.exception;
import std.bitmanip;
import std.functional;

void init(int test) {
	writef("Case #%s: ", test);
}

void solve(int test) {
	int n;
	readf(" %s", &n);
	int[] a = new int[n];
	foreach (i; 0 .. n) {
		readf(" %s", &a[i]);
	}
	
	int[] p = new int[n];
	foreach (i; 0 .. n) {
		p[i] = i;
	}
	sort!((i, j) => a[i] < a[j])(p);
	
	bool[] used = new bool[n];
	int ans = 0;
	foreach (i; p) {
		used[i] = true;
		int cntL = 0;
		for (int j = i - 1; j >= 0; --j) {
			if (!used[j]) ++cntL;
		}
		int cntR = 0;
		for (int j = i + 1; j < n; j++) {
			if (!used[j]) ++cntR;
		}
		ans += min(cntL, cntR);
	}
	writeln(ans);
}

void main() {
    string name = "B-large";
    string path = "";

    stdin = File(path ~ name ~ ".in", "r");
    stdout = File(path ~ name ~ ".out", "w");

    int testCases;
    readf(" %s", &testCases);

    foreach(testCase; 1..testCases + 1) {
		init(testCase);
		stderr.writeln("Solving: ", testCase);
		solve(testCase);
    }
}
