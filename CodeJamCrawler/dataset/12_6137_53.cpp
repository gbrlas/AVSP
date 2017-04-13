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

alias Tuple!(int, "a", int, "b") Pair;

void solve() {
  int N = readInt;
  Pair[] pp = new Pair[N];
  foreach (i; 0..N) {
    pp[i].a = readInt; pp[i].b = readInt;
  }
  sort!((Pair x, Pair y) { return x.b < y.b; })(pp);
  int[] picked = new int[N];
  int thre = 0, turn = 0, rest = N;

  for (; ; ) {
AGAIN:
    if (rest == 0) {
      writeln(turn);
      break;
    }
    foreach (i; 0..N) {
      if (pp[i].b <= thre && picked[i] <= 1) {
        thre += 2-picked[i];
        picked[i] = 2;
        rest--;
        turn++;
       goto AGAIN;
      }
    }
    for (int i=N-1; i>=0; --i) {
      if (pp[i].a <= thre && picked[i] <= 0) {
        thre++;
        picked[i] = 1;
        turn++;
        goto AGAIN;
      }
    }

    writeln("Too Bad");
    break;
  }
}

/*
void solve() {
  int N = readInt;
  Pair[] pp = new Pair[2*N];

  foreach (i; 0..N) {
    int lv1 = readInt, lv2 = readInt;
    pp[2*i+0] = Pair(lv1, 1, i);
    pp[2*i+1] = Pair(lv2, 2, i);
  }
  pp.sort;

  int curr = 0, thre = 0, rest = N, turn = 0;
  Pair[] q = new Pair[0];
  int[] finished = new int[N];

  for (; rest>0; ) {
    for (; curr<2*N && pp[curr].a <= thre; curr++) {
      q = q ~ [pp[curr]];
    }
    sort!((Pair x, Pair y) { return x.b > y.b; })(q);
    writeln("#", thre, "  ", rest, "  ", q);
    if (q.length == 0) {
      turn = -1;
      break;
    }

    int idx = q[0].idx;
    if (q[0].b == 2) {
      if (finished[idx] == 1) {
        thre += 1;
      } else {
        thre += 2;
      }
      finished[idx] = 2;
      rest--;
      turn++;
      q = q[1..$];
    } else if (q[0].b == 1) {
      if (finished[idx] == 0) {
        finished[idx] = 1;
        thre += 1;
        turn++;
      }
      q = q[1..$];
    }
  }
  if (turn == -1) {
    writeln("Too Bad");
  } else {
    writeln(turn);
  }
}
*/
