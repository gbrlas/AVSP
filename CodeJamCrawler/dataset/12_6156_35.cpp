import std.stdio, std.string, std.conv;
import std.algorithm, std.array, std.bigint, std.math, std.range, std.typecons;
import core.stdc.stdlib;

// const string _infile = "2012R2/A.in";
// const string _infile = "F:/Data/Downloads/A-small-attempt0.in";
const string _infile = "F:/Data/Downloads/A-large.in";

string readToken() {
  static string[] tokens;
  static int tokenId = 0;

  static bool first = true;
  static File file;  
  if (first) file = File(_infile, "r");
  first = false;

  for (; tokenId == tokens.length; ) {
    if (file.eof) exit(0);
    tokens = file.readln.split, tokenId = 0;
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
  int N = readInt;
  auto pos = new int[N+1], len = new int [N+1];
  foreach (i; 0..N) {
    pos[i] = readInt;
    len[i] = readInt;
  }
  pos[N] = readInt;
  len[N] = 0;
  
  auto best = new int[N+1];
  foreach (i; 0..N+1) best[i] = -1;
  best[0] = pos[0];
  
  foreach (i; 0..N) {
    foreach (j; i+1..N+1) {
      if (pos[j] <= pos[i]+best[i]) best[j] = max(best[j], min(len[j], pos[j]-pos[i]));
    }
  }

  writeln(best[N] >= 0 ? "YES" : "NO");
}