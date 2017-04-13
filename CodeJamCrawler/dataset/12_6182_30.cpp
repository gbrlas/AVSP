import std.stdio, std.string, std.conv;
import std.algorithm, std.array, std.bigint, std.math, std.range, std.typecons;
import core.stdc.stdlib;

// const string _infile = "R3B.in";
const string _infile = "F:/Data/Downloads/B-small-attempt0.in";
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

struct UF {
  int[] data;
  void init(int size) {
    data = new int [size];
    foreach (i; 0..size) data[i] = -1;
  }
  int root(int x) {
    return (data[x]<0) ? x : (data[x]=root(data[x])); }
  bool find(int x,int y) { return root(x) == root(y); }
  void uni(int x,int y) {
    x=root(x); y=root(y);
    if (x!=y) {
      if (data[x]<data[y]) swap(x,y);
      data[x] += data[y]; data[y] = x;
    }
  }
};

alias Tuple!(int, "x", int, "y") P;

void solve() {
  int S=readInt, N=readInt;
  P[] pos = new P [N];
  foreach (i; 0..N) {
    pos[i].x = readInt-1;
    pos[i].y = readInt-1;
  }

  int[6] dx = [-1, -1, 0, 0, 1, 1];
  int[6] dy = [-1, 0, -1, 1, 0, 1];

  // solve each!!
  int ringTime = N, forkTime = N, bridgeTime = N;

  // util
  int pd(P p) { return p.y*S*2+p.x; }
  int range(P p) {
    int x = p.x, y = p.y;
    if (x<0 || y<0 || x>S*2-2 || y>S*2-2 || x-y>S-1 || y-x>S-1) return -1; // outside
    int t0 = (x==0);
    int t1 = (y==0);
    int t2 = (x==S*2-2);
    int t3 = (y==S*2-2);
    int t4 = (x-y==S-1);
    int t5 = (y-x==S-1);
    if (t0+t1+t2+t3+t4+t5 >= 2) return 6;
    if (t0) return 0;
    if (t1) return 1;
    if (t2) return 2;
    if (t3) return 3;
    if (t4) return 4;
    if (t5) return 5;
    return 999;
  }

  // ring-case
  UF uf;
  bool[][] field;

  uf.init(4*S*S+1);
  field = new bool[][](2*S, 2*S);
  const int outer = 4*S*S;

  foreach (int i; 0..N) field[pos[i].x][pos[i].y] = true;
  foreach (int x; 0..2*S)
  foreach (int y; 0..2*S) {
    P p = P(x, y);
    int kind = range(p);
    if (kind == -1 || field[p.x][p.y]) continue;
    foreach (int r; 0..6) {
      P np = P(p.x+dx[r], p.y+dy[r]);
      if (range(np) == -1 || field[np.x][np.y]) continue;
      // writeln("!",pd(np), " ", pd(p));
      uf.uni(pd(np), pd(p));
    }
    if (kind <= 6) {
      uf.uni(pd(p), outer);
    }
  }

  // remove them one by one
  // writeln("re");
  for (int i=N-1; i>=0; --i) {
    P p = pos[i];
    field[p.x][p.y] = false;

    foreach (int r; 0..6) {
      P np = P(p.x+dx[r], p.y+dy[r]);
      if (range(np) == -1 || field[np.x][np.y]) continue;
      int nkind = range(np);
      if (!uf.find(pd(np), outer)) ringTime = i;

      uf.uni(pd(np), pd(p));
    }
    int kind = range(p);
    if (kind <= 6) uf.uni(pd(p), outer);

    if (!uf.find(pd(p), outer)) ringTime = i;
  }

  // fork&bridge
  uf.init(4*S*S);
  field = new bool[][](2*S, 2*S);

  P[6] cornerPos = [P(0,0), P(0,S-1), P(S-1,S*2-2), P(S*2-2, S*2-2), P(S*2-2, S-1), P(S-1, 0)];
  P[][] edgePos = new P[][](6, 0);

  foreach (int i; 0..N) {
    P p = pos[i];
    field[p.x][p.y] = true;
    foreach (int r; 0..6) {
      P np = P(p.x+dx[r], p.y+dy[r]);
      if (range(np) == -1 || !field[np.x][np.y]) continue;
      uf.uni(pd(np), pd(p));
    }
    // fork
    int kind = range(p);
    if (kind <= 5) {
      edgePos[kind] ~= [p];
    }
    int cnt = 0;
    foreach (int k; 0..6) {
      foreach (P edge; edgePos[k]) {
        if (uf.find(pd(edge), pd(p))) { cnt++; break; }
      }
      if (cnt >= 3) {
        forkTime = min(forkTime, i);
        break;
      }
    }

    // bridge
    foreach (k1; 0..6)
    foreach (k2; 0..k1) {
      if (uf.find(pd(cornerPos[k1]), pd(cornerPos[k2]))) {
         // writeln("!", cornerPos[k1], " ", cornerPos[k2]);
        bridgeTime = min(bridgeTime, i);
        break;
      }
    }
  }


  // output the value
  int opt = min(ringTime, forkTime, bridgeTime);
  if (opt == N) writeln("none");
  else {
    string[] res = new string[0];
    if (bridgeTime == opt) res ~= ["bridge"];
    if (forkTime == opt) res ~= ["fork"];
    if (ringTime == opt) res ~= ["ring"];
    foreach (i; 0..res.length) {
      if (i) write("-");
      write(res[i]);
    }
    writeln(" in move ", opt+1);
  }
}
