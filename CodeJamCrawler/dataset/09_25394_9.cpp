#include <iostream>

using namespace std;

#define M 569670
#define N 10000000

int mark[N];
int base[N];

int res[M][10];

int a[10], cnt;

int main(){
    
    freopen( "A-small-attempt0.in", "r", stdin );
    freopen( "A-small.out", "w", stdout );
    
    memset( res, 0, sizeof( res ) );
    for( int n = 2; n < M; n++ ){
         
         bool flag = true;
//         cout<<"n="<<n<<endl;
         for( int b = 2; b <= 10; b++ ){
              
              int tmp = n;
              bool f = false;
//              cout<<"b="<<b<<endl;
              while( 1 ){
                     int ans = 0;
                     while( tmp > 0 ){
                            ans += ( tmp % b ) * ( tmp % b );
                            tmp /= b;
                     }
//                     cout<<"ans="<<ans<<endl;
                     if( ans == 1 ){
                         f = true;
                         break;
                     }
                     else if( mark[ans] == n && base[ans] == b ){
                          break;
                     }
                     else{
                          mark[ans] = n;
                          base[ans] = b;
                          tmp = ans;
                     }
              }
              
              if( f == false ){
                  res[n][b] = 0;
              }
              else{
                   res[n][b] = 1;
              }
         }
    }
    
    int Testcase;
/*    
    for( int i = 2; i < 10; i++ ){
         for( int b = 2; b < 10; b++ ){
              cout<<res[i][b]<<" ";
         }
         cout<<endl;
    }
*/    
    scanf( "%d", &Testcase );
    getchar();
    
    char s[10000];
    
    for( int testcase = 1; testcase <= Testcase; testcase++ ){
         gets( s );
         cnt = 0;
//         cout<<s<<endl;
         int len = strlen( s );
         for( int i = 0; i < len; ){
              if( s[i] >= '0' && s[i] <= '9' ){
                  a[cnt] = 0;
                  int j;
                  for( j = i; j < len && s[j] >= '0' && s[j] <= '9'; j++ ){
                       a[cnt] = 10 * a[cnt] + s[j] - '0';
                  }
//                  cout<<a[cnt]<<endl;
                  cnt++;
                  i = j;
              }
              else{
                   i++;
              }
         }
/*         
         for( int i = 0; i < cnt; i++ ){
              cout<<a[i]<<" ";
         }
         cout<<endl;
*/         
         int ans;
         
         for( int i = 2; i < M; i++ ){
              bool flag = true;
              for( int j = 0; j < cnt; j++ ){
                   if( res[i][a[j]] == 0 ){
                       flag = false;
                   }
              }
              if( flag == true ){
                  ans = i;
                  break;
              }
         }
         
         printf( "Case #%d: %d\n", testcase, ans );
    }

    return 0;
}
                     
