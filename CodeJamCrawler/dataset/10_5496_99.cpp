#include <stdio.h>
#include <algorithm>
using namespace std;

#define DIG 200

struct bignum {
  int digit[DIG];
  const int& operator[] (int a) const { return digit[a]; }
  int& operator[] (int a) { return digit[a]; }
  };

void fromstr(bignum& num, char *s) {
  int i = strlen(s);
  for(int k=0; k<DIG; k++) num[k] = 0;
  for(int k=0; k<i; k++) num[k] = s[i-1-k] - '0';
  }

void tostr(bignum& num) {
  int i = 0;
  for(i=DIG-1; i>0; i--) if(num[i]) break;
  for(; i>=0; i--) { printf("%d", num[i]); }
  }

bool isZero(const bignum& b) {
  for(int i=0; i<DIG; i++) if(b[i]) return false;
  return true;
  }

bool hasIt(bignum &qty, bignum& a, int trans) {
  for(int i=DIG-1-trans; i>=0; i--) if(a[i+trans] != qty[i]) return a[i+trans] >= qty[i];
  return true;
  }

void subtract(bignum &qty, bignum& a, int trans) {
  int carry = 0;
//  printf("SUBTRACT.%d ", trans); tostr(qty); printf(" "); tostr(a); printf("\n");
  for(int i=0; i+trans<DIG; i++) {
    a[i+trans] -= qty[i]+carry;
    if(a[i+trans] < 0) { a[i+trans] += 10; carry=1;} else {carry = 0;}
    }
//  printf("  "); tostr(a); printf("\n");
  }
    
void rsubtract(bignum &qty, bignum& a, int trans) {
  int carry = 0;
//  printf("RSBTRACT%d ", trans); tostr(qty); printf(" "); tostr(a); printf("\n");
  for(int i=0; i+trans<DIG; i++) {
    a[i+trans] = qty[i]-a[i+trans]-carry;
    // printf("%d ", a[i+trans]);
    if(a[i+trans] < 0) { a[i+trans] += 10; carry=1; } else {carry = 0;}
    }
//  printf("  "); tostr(a); printf("\n");
  }
    
void takemod(bignum &qty, bignum &a) {
  for(int m=DIG/2; m>=0; m--) 
    while(hasIt(qty, a, m)) 
      subtract(qty, a, m);
  }

void euclid(bignum& a, bignum& b) {
  bignum c;
//  printf("EUCLID "); tostr(a); printf(" * "); tostr(b); printf("\n"); 
  while(!isZero(b)) {
//    printf("E "); tostr(a); printf(" * "); tostr(b); printf("\n"); 
    takemod(b, a);
    swap(a,b);
    } 
//  printf("       "); tostr(a); printf(" * "); tostr(b); printf("\n"); 
  }

char nums[DIG];
  
int main() {
  int T, N, K;
  scanf("%d", &T);
  for(int t=0; t<T; t++) {
    scanf("%d", &N);
    
    scanf("%s", nums);
    bignum base;
    fromstr(base, nums);
    
    bignum vmod;
    for(int d=0; d<DIG; d++) vmod[d] = 0;
    
    for(int n=1; n<N; n++) {
      scanf("%s", nums);
      bignum val;
      fromstr(val, nums);
      
      if(hasIt(base, val, 0)) { subtract(base, val, 0); euclid(vmod, val); }
      else { rsubtract(base, val, 0); euclid(vmod, val); }
      }
//    printf("Case #%d: %s\n", t+1, ((K >> (N-1))&1) ? "ON" : "OFF");
    
    bignum cop = vmod;
    takemod(cop, base);
    
    if(!isZero(base)) rsubtract(vmod, base, 0);
    printf("Case #%d: ", t+1);
    tostr(base);
    printf("\n");
    }                                                             
  return 0;                    
  
  }
  