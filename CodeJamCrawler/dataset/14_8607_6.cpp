#include<bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(0); cin.tie(0);

#define foreach(it, x) for(typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define all(x) x.begin(),x.end()
#define D(x) cout << #x " = " << (x) << endl;

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

int dx[8] = {-1,-1,-1,0,1,1, 1, 0};
int dy[8] = {-1, 0, 1,1,1,0,-1,-1};

int main(){__
  int n;
  cin >> n;
  int T = 1;
  for(int i=0; i<n; ++i){
    int a;
    cin >> a;
    a--;
    int mat1[4][4];
    set<int> st;
    for(int x=0; x<4; ++x)
      for(int y=0; y<4; ++y){
        cin >> mat1[x][y];
        if(x==a){
          st.insert(mat1[x][y]);
        }
      }

    int b;
    cin >> b;
    b--;
    int mat2[4][4];
    int c = 0;
    int ans = 0;
    for(int x=0; x<4; ++x)
      for(int y=0; y<4; ++y){
        cin >> mat2[x][y];
        if(x==b){
          if( st.count(mat2[x][y]) ){
            ans = mat2[x][y];
            c++;
          }
        }
      }
/*
    foreach(x,st)
      cout << *x << " ";
    cout << endl;
    D(c);
    D(ans);
    */
    if(c == 1){
      cout << "Case #" << T << ": " << ans << endl;
    }
    else if(!c){
      cout << "Case #" << T << ": " << "Volunteer cheated!" << endl;
    }
    else{
      cout << "Case #" << T << ": " << "Bad magician!" << endl;
    }
    T++;

  }
  return 0;
}
