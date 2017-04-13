#include <iostream>
using namespace std;

char ch[1000];
int f[20];
int main(void)
{
    FILE *fin, *fout;
    int t;
    
    freopen("C-large.in", "r",stdin);
    freopen("C-large.out", "w",stdout); 
    scanf("%d", &t);
    getchar();
    for (int ca=1; ca<=t; ca++)
    {
        gets(ch);
        memset(f, 0, sizeof(f));
        for (int i=0; i<strlen(ch); i++)
        {
            switch (ch[i])
            {
                case 'w': f[1]++; break;
                case 'e': f[2]+=f[1], f[7]+=f[6], f[15]+=f[14]; break;
                case 'l': f[3]+=f[2]; break;
                case 'c': f[4]+=f[3], f[12]+=f[11]; break;
                case 'o': f[5]+=f[4], f[10]+=f[9], f[13]+=f[12]; break;
                case 'm': f[6]+=f[5], f[19]+=f[18]; break;
                case ' ': f[8]+=f[7], f[11]+=f[10], f[16]+=f[15]; break;
                case 't': f[9]+=f[8]; break;
                case 'd': f[14]+=f[13]; break;
                case 'j': f[17]+=f[16]; break;
                case 'a': f[18]+=f[17]; break;
            }
            for (int j=1; j<=19; j++)
            {
                f[j]%=10000;
            }
        }
        printf("Case #%d: %04d\n", ca, f[19]);
        
    }
    //system("pause");
    return 0;
}
