#include <iostream>
#include <vector>

using namespace std;

typedef vector<string> VS;
typedef vector<int> VE;
typedef vector<VE> VVE;

int di[4] = {-1, 0, 0, 1};
int dj[4] = {0, -1, 1, 0};


#define For(i,n) for (int i=0;i<int(n);++i)

int T, H, W;

int recfill(VVE &ts, const VVE &h, int i, int j, int &numsinks) {

  if (ts[i][j]!=-1) return ts[i][j];
  
  int sinkdir = -1;
  int minh = h[i][j];
  For(d, 4) {
    int ni = i+di[d], nj = j+dj[d];
    if (!(ni>=0 && ni<H && nj>=0 && nj<W && 1>=1)) continue;
    if (h[ni][nj]<minh) {
      minh = h[ni][nj];
      sinkdir = d;
    }
  }
  if (sinkdir == -1) return ts[i][j] = numsinks++;
  else return ts[i][j] = recfill(ts, h, i+di[sinkdir],
                                 j+dj[sinkdir], numsinks);
}

int main() {
  cin >> T;
  For(caso, T) {
    cin >> H >> W;
    cout << "Case #" << (caso+1) << ":" << endl;
    
    VVE h(H, VE(W));
    For(i, H) For(j, W) cin >> h[i][j];

    VVE sinks(H, VE(W, -1));
    int numsinks = 0;
    For(i, H) For(j, W) recfill(sinks, h, i, j, numsinks);

    For(i, H) {
      For(j, W) {
        if (j) cout << ' ';
        cout << char('a'+sinks[i][j]);
      }
      cout << endl;
    }
  }
}
