#include <iostream>

using namespace std;

#define N 101

int m, n;

int h[N][N];

bool state[N][N];
char s[N][N];

int dir[4][2] = { { -1, 0},{ 0, -1},{0,1},{1,0} };

bool check( int x, int y, int xx, int yy ){
     int min = h[x][y];
     int pos;
     
//     cout<<x<<" "<<y<<" "<<xx<<" "<<yy<<endl;
     
     for( int i = 0; i < 4; i++ ){
          int x1 = x + dir[i][0];
          int y1 = y + dir[i][1];
          
//          cout<<x1<<" "<<y1<<" "<<min<<endl;
          
          if( x1 >= 0 && x1 < m && y1 >= 0 && y1 < n ){
              
              if( h[x1][y1] < min ){
                  min = h[x1][y1];
                  pos = i;
              }
          }
     }

     if( min < h[x][y] ){
         int x1 = x + dir[pos][0];
         int y1 = y + dir[pos][1];
//         cout<<x1<<" "<<y1<<endl;
         if( x1 == xx && y1 == yy ){
             return true;
         }
     }
     return false;
}

void dfs( int x, int y ){
     
     int min = h[x][y];
     int pos;
     
//     cout<<x<<" "<<y<<endl;
     
     for( int i = 0; i < 4; i++ ){
          int x1 = x + dir[i][0];
          int y1 = y + dir[i][1];
          
          if( x1 >= 0 && x1 < m && y1 >= 0 && y1 < n ){
              
              if( h[x1][y1] < min ){
                  min = h[x1][y1];
                  pos = i;
              }
          }
     }
     
     if( min < h[x][y] ){
         
         int x1 = x + dir[pos][0];
         int y1 = y + dir[pos][1];
         
         if( state[x1][y1] == false ){
             
             state[x1][y1] = true;
             s[x1][y1] = s[x][y];
             
             dfs( x1, y1 );
         }
     }
     
     for( int i = 0; i < 4; i++ ){
          int x1 = x + dir[i][0];
          int y1 = y + dir[i][1];
          
          if( x1 >= 0 && x1 < m && y1 >= 0 && y1 < n ){
              
              if( check( x1, y1, x, y ) == true ){
                  if( state[x1][y1] == false ){
             
                      state[x1][y1] = true;
                      s[x1][y1] = s[x][y];
                     
                      dfs( x1, y1 );
                  }
              }
          }
     }
}
     
     
         
int main(){
    
    int Testcase;
    
    freopen("B-small-attempt2.in","r",stdin);
    freopen("B-small.out","w",stdout);
    
    scanf("%d", &Testcase );
    
    for( int testcase = 1; testcase <= Testcase; testcase++ ){
         scanf("%d%d", &m, &n );
         
         for( int i = 0; i < m; i++ ){
              for( int j = 0; j < n; j++ ){
                   scanf("%d", &( h[i][j] ) );
              }
         }
         
         for( int i = 0; i < m; i++ ){
              for( int j = 0; j < n; j++ ){
                   state[i][j] = false;
              }
         }
         
         char ch = 'a';
         
         for( int i = 0; i < m ;i++ ){
              for( int j = 0; j  < n; j++ ){
                   if( state[i][j] == false ){
                       s[i][j] = ch;
                       state[i][j] = true;
                       dfs( i, j );
//                       cout<<endl<<endl;
                       ch++;
                   }
              }
         }
         
         printf("Case #%d:\n", testcase );
         
         for( int i = 0; i < m; i++ ){
              for( int j = 0; j < n; j++ ){
                   printf("%c ",s[i][j]);
              }
              printf("\n");
         }
         
    }
    
    return 0;
}
         
         
    
