#include<cstdio>
#include<cstring>
#define MAX 100

int main(){
    int mark[MAX],T,n;
    FILE *fp = fopen("out.txt","w");
    scanf("%d",&T);
    for (int k=1; k<=T; k++){
        scanf("%d",&n);
        int a;
        memset(mark,0,sizeof(mark));
        for (int i=0; i<4; i++)
            for (int j=0; j<4; j++){
                scanf("%d",&a);
                if (i==n-1)
                    mark[a] = 1;
            }
        scanf("%d",&n);
        int cnt = 0,res;
        for (int i=0; i<4; i++)
            for (int j = 0; j<4; j++){
                scanf("%d",&a);
                if (i==n-1&&mark[a]){
                    cnt++;
                    res = a;
                }
            }
        if (!cnt)
            fprintf(fp,"Case #%d: Volunteer cheated!\n",k);
        else if (cnt==1)
            fprintf(fp,"Case #%d: %d\n",k,res);
        else
            fprintf(fp,"Case #%d: Bad magician!\n",k);
    }
    return 0;
}




