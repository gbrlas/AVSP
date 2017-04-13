#include<stdio.h>
#include<string.h>

typedef long long int lld;

lld gcd(lld a,lld b){
  if(a<0)
    return gcd(-a,b);
  if(b<0)
    return gcd(a,-b);
  if(a>b)
    return gcd(b,a);
  if(a==0)
    return b;
  return gcd(b%a,a);
}

lld PG,PD,N;

int i,j,n,m;

bool check(){
  if(PD==0){
    return PG!=100;
  }
  if(PG==100){
    return PD==100;
  }
  if(PG==0){
    return PD==0;
  }
  lld a=100/gcd(100,PD);
  lld b=(PD-PG);
  lld c=gcd(PG,100-PG);
  lld d=c/gcd(b,c);
  lld e=gcd(a,d);
  lld k=gcd(a,e);
  //  printf("%lld %lld %lld %lld\n",a,b,c,d);
  a/=k;e/=k;
  k=gcd(d,e);
  e/=k;d/=k;
  return a*d<=N;
}

int main(){
  int ii,nn;
  scanf("%d",&nn);
  for(ii=1;ii<=nn;ii++){
    printf("Case #%d: ",ii);
    scanf("%lld %lld %lld",&N,&PD,&PG);
    if(check()){
      printf("Possible\n");
    }      

    else{
      printf("Broken\n");
    }
  }
  return 0;
}
