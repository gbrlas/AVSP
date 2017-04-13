#include <stdio.h>
int main(){
    const char *jam="welcome to code jam";
    int i, j;
    int N, s[19], len, c;
    char input[501];
    scanf("%d ", &N);
    for(i=1;i<=N;i++)
    {
        for(j=0;j<19;j++)
            s[j]=0;
        while((c=getchar())!='\n' && c!=EOF)
        {
            for(j=18;j>0;j--)
                if(jam[j]==c)
                    s[j]=(s[j]+s[j-1])%10000;
            if(jam[0]==c)
                s[j]+=1;
        }
        printf("Case #%d: %04d\n", i, s[18]);
    }
}
