#include <stdio.h>
#include <string.h>
#define ll long long int
#define MAXP 15
ll pot[MAXP];
char buff[100];
ll A,B;

void init_pot(){
  int i;
  pot[0] = 1;

  for(i = 1; i < MAXP; i++)
    pot[i] = pot[i - 1] * 10;

}


bool is_pal(ll x){
  int i,sz;  
  bool r;  
  sprintf(buff,"%lld",x);
  sz = strlen(buff);
  for(i = 0; i < sz/2; i++)
    if(buff[i] != buff[sz - i - 1])
      return false;
 // printf("IS_PAL: %s %d\n",buff,r);
  return true;
}

ll exp(ll n, ll k, ll v){
   ll i;
   ll p = n - k - 1;
   ll r = 0;
   ll x;
   
   
   x = v * v;
 //  printf("%lld %lld %lld\n",n, k, v); 
   if(x >= A && x <= B && x != 0)    
      r += is_pal(v*v);
   
   if(k > p )
     return r;

   for(i = 1; i <= 9; i++){
    ll vv = v + pot[k]*i;
    if(k != p){
      vv += pot[p]*i;          
    }
    r += exp(n, k + 1, vv);
   }
   return r; 
}

int main(){
  init_pot();
  ll i,j,k;

  ll T;
  scanf("%lld",&T);
  
  for(k = 0; k < T; k++){
    scanf("%lld %lld",&A, &B);
    ll ans = 0;    
    for(i = 1; i <= 3; i++)
      ans += exp(i, 0, 0);
    printf("Case #%lld: %lld\n",k+1, ans);  
  }
  
  return 0;
}

