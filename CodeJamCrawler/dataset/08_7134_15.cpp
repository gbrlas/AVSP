#include<stdio.h>
#include<vector>

using namespace std;
#define sz(X) (int(X.size()))
#define ll long long
int main(){
   vector<ll> X;
   vector<ll> Y;
   ll n,a,b,c,d,x0,y0,m;
   ll x,y;
   ll test;
   scanf("%lld",&test);
   for(ll i = 0;i < test;i++){
      scanf("%lld %lld %lld %lld %lld %lld %lld %lld",&n,&a,&b,&c,&d,&x0,&y0,&m);
      X.clear();
      Y.clear();
      X.push_back(x0);
      Y.push_back(y0);
      x = x0;
      y = y0;
      for(ll j = 0;j < n-1;j++){
         x = (a * x + b) % m;
         y = (c * y + d) % m;
         X.push_back(x);
         Y.push_back(y);
      }
      ll count = 0;
      for(ll j = 0;j < sz(X);j++){
         for(ll k = j+1;k < sz(X);k++){
            for(ll l = k+1;l < sz(X);l++){
               if((X[j] + X[k] + X[l])%3 != 0)continue;
               if((Y[j] + Y[k] + Y[l])%3 != 0)continue;
               count++;
            }
         }
      }
      printf("Case #%lld: %lld\n",i+1,count);
   }
   return 0;
}
