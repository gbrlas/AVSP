import std.stdio, std.string, std.conv;
import std.algorithm, std.array, std.bigint, std.math, std.range, std.typecons;
import core.stdc.stdlib;

// const string _infile = "2012R2/B.in";
const string _infile = "F:/Data/Downloads/B-small-attempt0.in";

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
    write("Case #", testId, ":");
    solve();
  }
}

alias Tuple!(int, "r", int, "id") Rad;

void solve() {
  int N = readInt, W = readInt, H = readInt;
  Rad[] rads = new Rad[N];
  foreach (i; 0..N) {
    rads[i].r = readInt;
    rads[i].id = i;
  }
  sort!("a>b")(rads);

  creal[] res = new creal[N];
  
  // greedy?
  int[] posx = new int[0], posy = new int[0];
  int currx = 0;
  bool det = false;
  int cnt = 0;
  foreach (Rad rad; rads) {
    const int m = posx.length;
    if (!det) {
      int nextx = currx + rad.r*2;
      if (m >= 1 && nextx > W) {
        det = true;
      } else {
        res[rad.id] = ((m == 0 ? 0 : rad.r)+currx)+0*1i;
        posx ~= [currx];
        posy ~= rad.r;
        currx = nextx;
      }
    }
    
    if (det) {
      assert(m >= 1);
      int i = cnt % m;
      
      res[rad.id] = ((i == 0 ? 0 : rad.r)+posx[i])+(posy[i]+rad.r)*1i;
      posy[i] += rad.r*2;
    }
    cnt++;
  }
  
  // output
  foreach (i; 0..N) {
    writef(" %.1f %.1f", res[i].re, res[i].im);
        assert(res[i].im <= H+1e-9);
        assert(res[i].re <= W+1e-9);
  }
  writeln("");
}