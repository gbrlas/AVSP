#include <map>
#include <vector>
#include <iostream>
#include <cassert>

using namespace std;

typedef map<int, string> MIS;

typedef vector<MIS> VMIS;
typedef vector<VMIS> VVMIS;

typedef vector<char> VC;
typedef vector<VC> VVC;

bool sign(char c) {
  return c=='+' or c=='-';
}

int di2[16] = {2, 1, 1, 0, -1, -1, -2, -1, -1,  0,  1,  1, 0,  0, 0,  0};
int dj2[16] = {0, 1, 1, 2,  1,  1,  0, -1, -1, -2, -1, -1, 0,  0, 0,  0};
int di[16] =  {1, 1, 0, 0,  0, -1, -1, -1,  0,  0,  0,  1, 1, -1, 0,  0};
int dj[16] =  {0, 0, 1, 1,  1,  0,  0,  0, -1, -1, -1,  0, 0,  0, 1, -1};



#define For(i,n) for(int i=0;i<(n);++i)
#define Foreach(it,m) for(typeof((m).begin()) it = (m).begin(); it!=(m).end();++it)

void pas(int W, const VVC &S, VVMIS &R, map<int, string> &best) {
  VVMIS R2(W, VMIS(W));
  For(i, W) For(j, W) {
    if (not sign(S[i][j])) {
      For(k, 16) {
	int i2 = i+di2[k];
	int j2 = j+dj2[k];
	int i1 = i+di[k];
	int j1 = j+dj[k];
	if (i2<0 or j2<0 or i2>W-1 or j2>W-1 or
	    i1<0 or j1<0 or i1>W-1 or j1>W-1) {
	  continue;
	}
	char sgn = S[i1][j1];
	string add = string(1, sgn)
	  +string(1, S[i][j]);
	int numadd = S[i][j]-'0';
	if (sgn=='-') numadd *= -1;

	Foreach(it, R[i2][j2]) {
	  int num = it->first + numadd;
	  bool existe = R2[i][j].find(num)!=R2[i][j].end(); 
	  if (existe and R2[i][j][num]<it->second+add) continue;
	  R2[i][j][num] = it->second+add;
	}
      }
    }
  }
  map<int,string> newbest;
  
  For(i, W) For(j, W) {
    Foreach(it, R2[i][j]) {
      if (best.find(it->first)!=best.end()) continue;
      if (newbest.find(it->first)==newbest.end() or
	  newbest[it->first]>it->second) newbest[it->first] = it->second;
    }
  }
  Foreach(it, newbest) {
    assert(best.find(it->first)==best.end());
    best[it->first] = it->second;
  }
  R = R2;
}

void debug(map<int, string> &best) {
  Foreach(it, best) {
    cout << it->first << " " << it->second << endl;
  }
}

int main() {
  int T;
  cin >> T;
  For(caso, T) {
    int W, Q;
    cin >> W >> Q;
    VVC S(W, VC(W));
    VVMIS R(W, VMIS(W));
    map<int, string> best;

    For(i, W) For(j, W) cin >> S[i][j];
    For(i, W) For(j, W) {
      if (not sign(S[i][j])) {
	R[i][j][S[i][j]-'0'] = string(1, S[i][j]);
	best[S[i][j]-'0'] = R[i][j][S[i][j]-'0'];
      }
    }

    cout << "Case #" << (caso+1) << ":" << endl;
    For(i, Q) {

      //      debug(best);

      int q;
      cin >> q;

      while (best.find(q)==best.end()) {
	pas(W, S, R, best);
      }
      cout << best[q] << endl;
    }
  }
}
