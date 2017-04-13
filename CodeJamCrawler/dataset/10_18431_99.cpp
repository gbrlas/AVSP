#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
int cal2(int x, int y) {
  do {
    int c = x - y;
    if (c == 0) return x;
    if (c > 0) {
      x %= y;
      if (x == 0) {
        return y;
      }
    }
    else {
      y %= x;
      if (y == 0) {
        return x;
      }
    }
  } while(true);
}

int cal(vector<int>& timelist) {
  vector<int> difflist;
  for (int i = 1; i < timelist.size(); ++i) {
    if (timelist[i] - timelist[i-1] > 0) {
      difflist.push_back(timelist[i] - timelist[i-1]);
    } else if (timelist[i] - timelist[i-1] == 0) {
      continue;
    } else {
      difflist.push_back(timelist[i-1] - timelist[i]);
    }
  }
  for (int i = 1; i < difflist.size(); ++i) {
    difflist[0] = cal2(difflist[0], difflist[i]);
  }
  timelist[0] %= difflist[0];
  int m = timelist[0];
  if (m == 0) {
    return m;
  } else {
    return difflist[0] - m;
  }
}

int main(int argc, char* argv[]) {
  ifstream in(argv[1]);
  int c;
  in >> c;
  for (int i = 0; i < c; ++i) {
    int n;
    in >> n;
    vector<int> timelist;
    for (int j = 0; j < n; ++j) {
      int k;
      in >> k;
      timelist.push_back(k);
    }
    int bi = cal(timelist);
    cout << "Case #" << i+1 << ": " << bi;
    cout << "\n";
  }
  return 0;
}
