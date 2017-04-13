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
	int m, n;
	readf(" %s %s", &m, &n);
	readln;
	string[] b = new string[m];
	foreach (i; 0 .. m) {
		b[i] = readln().chomp;
	}
	
	
	auto sets = new int[][](n);

	int[int[]] mem;
	int countTrie(immutable (int[]) a, int d) {
		if (d == 0 && ((a in mem) !is null)) return mem[a];
		if (a == []) return 0;
		int res = 1;
		for (char c = 'A'; c <= 'Z'; c++) {
			res += countTrie(array(a.filter!(s => b[s].length > d
											 && b[s][d] == c)), d + 1);
		}
		if (d == 0) {
			mem[a] = res;
		}
		return res;
	}

	int ans = int.min;
	int curCnt = 0;
	int cnt = 0;
	void check() {
		if (ans < cnt) {
			ans = cnt;
			curCnt = 1;
		} else if (ans == cnt) {
			++curCnt;
		}
	}

	void rec(int pos) {
		if (pos == m) {
			check();
			return;
		}
		
		foreach (set; 0 .. n) {
			int d = countTrie(sets[set].idup, 0);
			cnt -= d;
			sets[set] ~= pos;
			int v = countTrie(sets[set].idup, 0);
			cnt += v;
			rec(pos + 1);
			--sets[set].length;
			cnt -= v;
			cnt += d;
		}
	}
	
	rec(0);
	writeln(ans, " ", curCnt);
}

void main() {
    string name = "D-small";
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
