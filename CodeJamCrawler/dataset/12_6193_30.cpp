import std.stdio, std.string, std.conv;
import std.algorithm, std.array, std.bigint, std.math, std.range, std.typecons;
import core.stdc.stdlib;

// const string _infile = "R3D.in";
const string _infile = "F:/Data/Downloads/D-small-attempt0.in";
// const string _infile = "F:/Data/Downloads/D-large.in";

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


void main(string[] args) {
  int testCase = readInt;
  for (int testId = 1; testId <= testCase; ++testId) {
    write("Case #", testId, ": ");
    solve();
  }
}


// Code from here

void solve() {
  int[int] mp;
  mp['o'] = '0';
  mp['i'] = '1';
  mp['e'] = '3';
  mp['a'] = '4';
  mp['s'] = '5';
  mp['t'] = '7';
  mp['b'] = '8';
  mp['g'] = '9';

  int K = readInt;
  string s = readToken;
  int N = s.length;
  int[][] g = new int[][](128, 128);
  foreach (i; 0..N-1) {
    int a = cast(int)s[i], b = cast(int)s[i+1];
    g[a][b]=1;
    if (a in mp) g[mp[a]][b] = 1;
    if (b in mp) g[a][mp[b]] = 1;
    if (a in mp && b in mp) g[mp[a]][mp[b]] = 1;
  }

  int[] din = new int[128];
  int[] dout = new int[128];
  int M = 0;
  foreach (i; 0..128)
  foreach (j; 0..128) if (g[i][j]) {
    din[i]++;
    dout[j]++;
    M++;
  }

  int res = 1<<28;
  foreach (start; 0..128)
  foreach (end; 0..128) {
    dout[start]++;
    din[end]++;

    int tmp = 0;
    foreach (i; 0..128) {
      int add = (dout[i] - din[i]);
      if (add < 0) add = -add;
      tmp += add;
    }
    res = min(res, tmp/2+M);

    // revert
    dout[start]--;
    din[end]--;
  }
  writeln(res+1);
}

