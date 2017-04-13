#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<set>
using namespace std;
int cs;
int n,A,B;
char str[10];
int pow10[10];
const int mxn = (int)2e6 + 10;
int done[mxn];
int main() {
    pow10[0] = 1;
    for(int i=1;i<10;i++) pow10[i] = pow10[i-1] * 10;
    int runs;
    cin >> runs;
    
    while( runs-- ) {
           memset( done , 0 , sizeof done );
           cin >> A >> B;
           int length = sprintf( str , "%d" , A );
           int ans = 0;
           for(int i=A;i<=B;i++) {
               n = i;
               int L = length;
               int pow1 = 1;
               while( n / pow10[pow1] > 0 ) {
                      int q = n / pow10[pow1];
                      int r = n % pow10[pow1];
                      L--;
                      pow1++;
                      int val = r * pow10[L] + q;
                      if( val >= A && val <= B && val != i && sprintf( str ,"%d" , val ) == length && sprintf( str ,"%d" , q ) == L ) {
                          if( val > i )
                          done[i]++;
                      }
               }
           }
           ans = 0;
           for(int i=A;i<=B;i++) ans += done[i];
           printf("Case #%d: %d\n",++cs,ans);
    }
    return 0;
}
