#include <cstdio>
#include <cstring>

int main(){

    //freopen("C-small-attempt0.in","r",stdin);
   // freopen("C-small-attempt0.out","w",stdout);

    int T,Cas = 1;
    scanf("%d",&T);
    while(T--){
        int a,b;
        scanf("%d%d",&a,&b);
        int sum = 0;
        for(int i = a; i <= b; i++)
            for(int j = a; j < i; j++){
                char s1[10],s2[10],s3[20];
                sprintf(s1,"%d",i);
                sprintf(s2,"%d",j);
                if(strlen(s1)!=strlen(s2)) continue;
                strcpy(s3,s2);
                strcat(s3,s2);
                for(int i = 0; i < strlen(s3)-strlen(s1); i++){
                    int k = 0;
                    for(int j = i; j < i+strlen(s1); j++)
                        s2[k++] = s3[j];
                    s2[k] = 0;
                    if(strcmp(s1,s2)==0){
                        sum++;
                        break;
                    }
                }
            }
        printf("Case #%d: %d\n",Cas++,sum);
    }
}
