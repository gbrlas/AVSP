// gcj c
#include <iostream>
#include <vector>
#include <string>
#include <memory.h>
using namespace std;

string s[110];
int n ;

int f[505][25];

const string wel = "welcome to code jam";

int pro( string s )
{
    memset(f,0,sizeof(f));
    for( int i = 0; i < s.length(); i++ ) { f[i][0] = 1; };
    for( int i = 1; i <= s.length(); i++ )
    {
         for( int j = 1; j <= 19; j++ )
         {
              f[i][j] += f[i-1][j] ;
              if( s[i-1] == wel[j-1] )
              {
                  f[i][j] += f[i-1][j-1];
              }
              f[i][j] %= 1000;
         }
    }
    return f[s.length()][19];
}

int main()
{
    string tmp;
    freopen("C-small-attempt0.in","r",stdin);
    freopen("c.out","w",stdout);
    scanf("%d\n",&n);
    for( int i = 0; i < n; i++ )
    {
         getline( cin, s[i] );
         int ans = pro(s[i]);
         tmp = "";
         while(ans>0)
         {
               tmp = char( (ans%10) +48)+tmp;
               ans/=10;
         }
         while( tmp.size() < 4 ) tmp = '0' + tmp;
         cout << "Case #" << i+1 << ": " << tmp << endl;
    }        
    return 0;
}
