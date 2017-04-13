#include <iostream>

using namespace std;

#define M 5001
#define N 16
#define Len 75001

int m, n, len;

char s[M][N];
char tmp[Len];

bool check( int k ){
     
     int i = 0;
     int j = 0;
     bool flag = true;
     
//     cout<<tmp<<" "<<s[k]<<endl;
//     cout<<"n="<<n<<endl;
//     cout<<"len="<<len<<endl;

     for( ; i < n; i++ ){
          if( j >= len ){
              flag = false;
              break;
          }
          else{
               if( tmp[j] != '(' ){
                   if( tmp[j] != s[k][i] ){
                       flag = false;
                       break;
                   }
                   else{
                        j++;
                   }
               }
               else{
                    int f = false;
//                    cout<<"i="<<i<<" "<<flag<<endl;
                    for( j++; j < len && tmp[j] != ')'; j++ ){
                         if( tmp[j] == s[k][i] ){
                             f = true;
                         }
                    }
//                    cout<<"f="<<f<<endl;
                    if( f == false ){
                        flag = false;
                        break;
                    }
                    else{
                         j++;
                    }
//                    cout<<"j="<<j<<" "<<tmp[j]<<" "<<endl;
               }
          }
     }
     return flag;
}

int main(){
    
    int q;
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    
    scanf("%d%d%d",&n, &m, &q );
    
    for( int i = 0; i < m; i++ ){
         scanf("%s",s[i] );
    }
    
    for( int i = 1; i <= q; i++ ){
         scanf("%s", tmp );
         int ans = 0;
         len = strlen( tmp );
         for( int j = 0; j < m; j++ ){
              if( check( j ) == true ){
                  ans++;
              }
         }
         printf("Case #%d: %d\n", i, ans );
    }
//    while(1);
    return 0;
}
    
    
