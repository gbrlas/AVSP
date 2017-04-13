#include <cstdio>
#include <cstring>

const char c[] = "welcome to code jam";
int dp[20][10000],m,n;
char d[10000];

int main(){
    scanf("%d", &m);
    scanf("%c", &d);
    for (int k=1; k<=m; k++){
        gets(d);
        n = -1;
        while (d[++n]);
        for (int i=0; i<n; i++)
        {
           if (i==0) dp[0][i] = 0; else dp[0][i] = dp[0][i-1]; 
           if (d[i] == 'w') dp[0][i]++; 
        }
        for (int j=1; j<19; j++)
             dp[j][0] = 0;
        for (int i=1; i<n; i++)
            for (int j=1; j<19; j++)
            {
                dp[j][i] = dp[j][i-1];
                if (d[i] == c[j]) dp[j][i] = (dp[j][i] + dp[j-1][i-1])%10000;
            }
        printf("Case #%d: %04d\n", k, dp[18][n-1]);
    }        
    return 0;    
}
