import std.stdio, std.string, std.conv;
import std.algorithm, std.array, std.bigint, std.math, std.range, std.typecons;
import core.stdc.stdlib;

string readToken() {
  static string[] tokens;
  static int tokenId = 0;
  for (; tokenId == tokens.length; ) {
    if (stdin.eof) exit(0);
    tokens = readln.split, tokenId = 0;
  }
  return tokens[tokenId++];
}
int readInt() { return to!int(readToken); }
long readLong() { return to!long(readToken); }


// Code from here

void main(string[] args) {
  int testCase = readInt;
  for (int testId = 1; testId <= testCase; ++testId) {
    write("Case #", testId, ": ");
    solve();
  }
}

void solve() {
  int N = readInt, M = readInt;
  real[] prob = new real[N];
  foreach (int i; 0..N) prob[i] = to!real(readToken);
  // give up
  real res = 1+M+1;
  // backspace+enter
  real pp = 1.0;
  for (int i=0; i<=N; ++i) {
    res = min(res, N-i+(pp*(M-i+1)+(1.0-pp)*(M-i+1+M+1)));
    if (i < N) pp *= prob[i];
  }
  writef("%.18f\n", res);
}
