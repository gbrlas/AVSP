#include<stdio.h>
#include<string.h>

#define SE_NUMBER 120
#define Q_NUMBER 1200
int main(void) {
    FILE* out=fopen("e:/ctd/gcjam/aout","w");
    int i,j,k,n,s,q,switchnum,num,final;
    char se[SE_NUMBER][110],query[Q_NUMBER][110];
    int flag[SE_NUMBER];
    memset(flag,0,SE_NUMBER);
    scanf("%d",&n);
    for(i=0;i<n;i++) {
        switchnum=0;
        num=0;
        for(j=0;j<s;j++)
            flag[j]=0;
        scanf("%d",&s);
        getchar();
        for(j=0;j<s;j++) {
            gets(se[j]);
        }
        scanf("%d",&q);
        getchar();
        for(j=0;j<q;j++) {
            gets(query[j]);
            for(k=0;k<s;k++) {
                if(strcmp(query[j],se[k])==0) {
                    flag[k]=1;
                    break;
                }
            }
            final=k;
            num=0;
            for(k=0;k<s;k++) {
                num+=flag[k];
            }
            if(num==s) {
                switchnum++;
                for(k=0;k<s;k++) {
                    flag[k]=0;
                }
                flag[final]=1;
            }
        }
        fprintf(out,"Case #%d: %d\n",i+1,switchnum);
    }
    system("pause");
    return 0;
}
