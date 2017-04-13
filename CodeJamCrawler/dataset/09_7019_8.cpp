#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <map>
#include <set>
#include <list>
#include <algorithm>
#include <numeric>
#define MAXLEN 100

using namespace std;
int digitV[300];
int existe[300];
int num[MAXLEN];

int main(){
    int T;
    int i,j,k;
    int base;
    char str[MAXLEN];
    int len;
    int s;
    scanf("%d",&T);
    for(k=0;k<T;k++){
        memset(existe,0,sizeof(existe));
        for(i=0;i<300;i++){
            digitV[i]=-1;
        }
        scanf("%s",str);
        len=strlen(str);
        int diff=0;
        for(i=0;i<len;i++){
            if(existe[str[i]]==0){
               existe[str[i]]=1;
               diff++;
            }
        }
        base=diff;
        if(base==1){
            base=2;
        }
       // printf("\nbase %d",base);
        digitV[str[0]]=1;

        int v=0;
        for(i=0;i<len;i++){

            if(digitV[str[i]]!=-1){
                num[i]=digitV[str[i]];
            }
            else{
                if(v==1)
                    v++;
               digitV[str[i]]=v;
               num[i]=v;
               v++;
            }
            if(v>base)
                printf("\nerro");
            //printf("\n %d %c",num[i],str[i]);
        }
        s=0;
        int pot=1;
        //passa o numero para decimal
        for(i=(len-1);i>=0;i--){
            //printf("\n%d %d %d",num[i],pot,s);
            s+=num[i]*pot;
            pot*=base;

        }
        printf("Case #%d: %d\n",k+1,s);
    }
    return 0;
}



