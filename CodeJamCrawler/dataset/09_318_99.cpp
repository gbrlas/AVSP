#include<iostream>
using namespace std;

const int maxl=500+2,maxs=19;
int test;
int f[maxl][maxs];
char a[maxl],s[maxs];

int main()
{
    scanf("%d\n",&test);
    strcpy(s,"welcome to code jam");
    
    for (int t=1;t<=test;t++)
    {
        gets(a);
        
        int ans=0;
        memset(f,0,sizeof(f)); 
        for (int i=0;i<strlen(a);i++)
        for (int j=0;j<maxs;j++)
        if (a[i]==s[j])
        {
            if (j==0) f[i][j]=1; else
            for (int k=0;k<i;k++) f[i][j]=(f[i][j]+f[k][j-1])%10000;
            if (j==maxs-1) ans=(ans+f[i][j])%10000;
        }

        printf("Case #%d: ",t);
        if (ans<1000) printf("0");
        if (ans<100) printf("0");
        if (ans<10) printf("0");
        printf("%d\n",ans);
    }
}
