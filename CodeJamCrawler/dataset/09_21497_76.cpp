#include <iostream>
#include <vector>
#include <stack>
#include <map>

using namespace std;

class point {
public:
  int x, y;
  point (int a, int b):x(a), y(b) {}
  bool operator== (const point &other) const {
    return (x==other.x)&&(y ==other.y);
  }
  bool operator!= (const point &other) const {
    return !(*this==other);
  }
  bool operator< (const point &other) const {
    if (x < other.x)
      return true;
    else if (x == other.x && y < other.y)
      return true;
    return false;
  }
};

const point non_point (-1,-1);

point down_to (point cur, int H, int W, vector<vector<int> > &M) {
  vector<point> v_p;

  if (cur.x > 0) {
    point temp (cur.x-1, cur.y);
    v_p.push_back (temp);
  }
  if (cur.y > 0) {
    point temp (cur.x, cur.y-1);
    v_p.push_back (temp);
  }
  if (cur.y < W-1) {
    point temp (cur.x, cur.y+1);
    v_p.push_back (temp);
  }
  if (cur.x < H-1) {
    point temp (cur.x+1, cur.y);
    v_p.push_back (temp);
  }

  int small = -1, low = M[cur.x][cur.y];
  for (int i = 0; i < v_p.size (); ++i) {
    if (M[v_p[i].x][v_p[i].y] < low) {
      low = M[v_p[i].x][v_p[i].y];
      small = i;
    }
  }
  if (small == -1)
    return non_point;
  return v_p[small];
}

void do_test (int no) {
  int H, W;
  cin >> H >> W;
  vector<vector<int> > M;
  for (int i = 0; i < H; ++i) {
    vector<int> temp;
    for (int j = 0; j < W; ++j) {
      int temp1;
      cin >> temp1;
      temp.push_back (temp1);
    }
    M.push_back (temp);
  }

  vector<point> temp_ (W, non_point);
  vector<vector<point> > final (H, temp_);

  for (int i = 0; i < H; ++i)
    for (int j = 0; j < W; ++j) {
      if (final[i][j] == non_point) {
        point p (i, j);
        stack <point> s;
        s.push (p);
        p = down_to (p, H, W, M);
        while (p != non_point) {
          s.push (p);
          p = down_to (p, H, W, M);
        }

        point t = s.top ();
        while (!s.empty ()) {
          point cur = s.top ();
          final[cur.x][cur.y] = t;
          s.pop ();
        }
      }
    }

  cout << "Case #" << no << ":" << endl;

  map<point, int> T;
  int cur_small = 0;
  for (int i = 0; i < H; ++i)
    for (int j = 0; j < W; ++j) {
      point p = final[i][j];
      if (T.find(p) == T.end ()) {
        T[p] = cur_small;
        ++cur_small;
      }
      cout << (char)('a'+T[p]);
      if (j != W-1)
        cout << ' ';
      else
        cout << endl;
    }
}

int main () {
  int T;
  cin >> T;
  for (int i = 1; i <= T; ++i)
    do_test (i);
  return 0;
}
