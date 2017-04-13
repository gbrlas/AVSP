import std.stdio, std.string, std.conv;
import std.algorithm, std.array, std.bigint, std.math, std.range, std.typecons;
import core.stdc.stdlib;

// const string _infile = "R3A.in";
const string _infile = "F:/Data/Downloads/A-small-attempt0.in";
// const string _infile = "F:/Data/Downloads/*-large.in";

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

alias Tuple!(int, "l", int, "p", int, "id") A;

void solve() {
  int N = readInt;
  A[] mp = new A[0];
  int[] L = new int[N], P = new int[N];
  foreach (i; 0..N) L[i] = readInt;
  foreach (i; 0..N) P[i] = readInt;
  foreach (i; 0..N) {
    mp ~= [A(L[i], P[i], i)];
  }
  mp.sort!("a.l*b.p < b.l*a.p")();

  int first = 1;
  foreach (A aa; mp) {
    if (!first) write(" ");
    first = 0;
    writef("%d", aa.id);
  }
  writeln;
}
