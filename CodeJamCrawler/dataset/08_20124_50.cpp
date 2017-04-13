#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int i,j,t,n,m,l;
string a[2000], b[2000];
int dp[1001][101];
char s[2000];

void solve()
{
     for (i = 0; i < n; i++)
         for (j = 0;j < m; j++)
         {
             dp[j][i] = 1000000;
         }
             
             
         for (i = 0; i < n; i++)
             if (a[i] == b[0]) dp[0][i] = 1000000; else dp[0][i] = 0;
             
             
             for (i = 1; i < m; i++)
             {
                 for (j = 0; j < n; j++)
                 {
                     if (b[i] == a[j])
                     {
                             for (l = 0; l < n; l++)
                             {
                                 if (l != j)
                                 {
                                       dp[i][l] = min(dp[i][l] , dp[i-1][j] + 1);
                                 }
                             } 
                     } else
                     {
                             for (l = 0; l < n; l++)
                             {
                                 if (l != j)
                                 {
                                       dp[i][l] = min(dp[i][l] , dp[i-1][j] + 1);
                                 } else
                                   dp[i][l] = min(dp[i][l] , dp[i-1][j]);
                             } 
                     }
                 }
             }
             
             int ans = 1000000;
             for (i = 0; i < n; i++)
             {
                 if (dp[m-1][i] < ans) ans = dp[m-1][i];
             }
             
             if (m == 0) cout<<0<<endl; else
             cout<<ans<<endl;
             
}

int main()
{   
    freopen("c:/input.txt","r",stdin);
    freopen("c:/output.txt","w",stdout);
    cin>>t;
    
    for (int tt = 0; tt < t; tt++)
    {
        cin>>n;
        gets(s);
        for (i = 0; i < n; i++)
        {
            gets(s);
            a[i] = s;
        }
        
        cin>>m;
        gets(s);
        for (i = 0; i < m; i++)
        {
            gets(s);
            b[i] = s;
        }
        
        cout<<"Case #"<<tt+1<<": ";
        solve();
    }  
    return 0;
}
