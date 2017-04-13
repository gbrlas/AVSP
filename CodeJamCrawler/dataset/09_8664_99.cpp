#include<stdio.h>
#include<string.h>
#define div 10000

char s[]=" welcome to code jam";

char ss[1000];

int p[30];

int i,j;

int main(){
    int ii,nn;
    scanf("%d",&nn);
    gets(ss);
    for(ii=1;ii<=nn;ii++){
        printf("Case #%d: ",ii);
        memset(p,0,sizeof(p));
        p[0]=1;

        gets(ss);
        for(i=0;ss[i];i++){
            for(j=19;j;j--)if(s[j]==ss[i]){
                    p[j]+=p[j-1];
                    p[j]%=div;
                }
        }
        printf("%04d\n",p[19]);
    }
    return 0;
}
