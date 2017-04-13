#include<iostream>
using namespace std;

int n, A, B, C, D, _x0, _y0, mod;

void read(){
  cin >> n >> A >> B >> C >> D >> _x0 >> _y0 >> mod;
}

void work(int cases){
  int cnt[3][3];
  for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
      cnt[i][j] = 0;

  int x = _x0, y = _y0;
  cnt[x%3][y%3]++;
  for(int i=1;i<n;i++){
    x = (1LL*A*x+B)%mod;
    y = (1LL*C*y+D)%mod;
    cnt[x%3][y%3]++;
  }

  long long ans = 0;
  for(int a=0;a<9;a++)
    for(int b=a;b<9;b++)
      for(int c=b;c<9;c++){
        int x1 = a%3, y1 = a/3;
        int x2 = b%3, y2 = b/3;
        int x3 = c%3, y3 = c/3;
        if((x1+x2+x3)%3==0 && (y1+y2+y3)%3==0){
      
          if(x1==x2 && y1==y2){
            if(x2==x3 && y2==y3){
              long long n = cnt[x1][y1];
              ans += n*(n-1)*(n-2)/6;
            }
            else{
              long long n = cnt[x1][y1];
              ans += n*(n-1)/2*cnt[x3][y3];
            }
            continue;
          }

          if(x2==x3 && y2==y3){
            long long n = cnt[x2][y2];
            ans += n*(n-1)/2*cnt[x1][y1];
            continue;
          }

          ans += 1LL*cnt[x1][y1]*cnt[x2][y2]*cnt[x3][y3];
        }
      }

  cout << "Case #" << cases << ": " << ans << endl;
}

int main(){
    int cases;
    cin >> cases;

    for(int i=0;i<cases;i++){
      read();
      work(i+1);
    }
    
}
