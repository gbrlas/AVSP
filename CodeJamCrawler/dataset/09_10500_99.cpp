#include <stdio.h>
#include <string.h>

int f[600][60];
char str[600];
char ori[]="welcome to code jam";
int loc[30][60];
int num[30];
int m,len;
int kase;

int main()
{
    freopen("C-large.in","r",stdin);
    freopen("C-large.out","w",stdout);
    m=strlen(ori);
    for (int i=0;i<m;i++) {
        if (ori[i]==' ') loc[26][num[26]++]=i;
        else loc[ori[i]-'a'][num[ori[i]-'a']++]=i;
    }
    scanf("%d\n",&kase);
    for (int i=0;i<kase;i++) {
        gets(str);
        len=strlen(str);
        memset(f,0,sizeof(f));
        for (int j=0;j<len;j++) if (str[j]=='m') f[j][m-1]=1;
        for (int j=len-1;j>=0;j--) {
            if (str[j]==' ') str[j]='a'+26;
            for (int k=0;k<num[str[j]-'a'];k++) {
                for (int l=j+1;l<len;l++) {
                    f[j][loc[str[j]-'a'][k]]+=f[l][loc[str[j]-'a'][k]+1];
                    f[j][loc[str[j]-'a'][k]]%=10000;
                }
            }
        }
        int sum=0;
        for (int j=0;j<len;j++) sum=(sum+f[j][0])%10000;
        printf("Case #%d: %04d\n",i+1,sum);
    }
    return 0;
}
