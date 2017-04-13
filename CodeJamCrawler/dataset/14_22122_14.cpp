#include<cstdio>
#include<cstring>
#include <stdio.h>
using namespace std;

main(){
    int t,tmp=1;
    //freopen("F:\\A-small-attempt5.in","r", stdin);
    //freopen("F:\\OUTPUTA.txt", "w", stdout);
    scanf("%d",&t);
    while(t--){
        int n;
        int g[10][10],flag[20];
        memset(flag,0,sizeof(flag));
        for(int k=0;k<2;k++){
            scanf("%d",&n);
            //printf("%d\n",n);
            for(int i=0;i<4;i++){
                for(int j=0;j<4;j++){
                    scanf("%d",&g[i][j]);
                    //printf("%d ",g[i][j]);
                }
                //printf("\n");
            }
            for(int i=0;i<4;i++){
                flag[g[n-1][i]]++;
            }
        }
        int n2=0,ans=0;
        for(int i=1;i<=16;i++){
            if(flag[i]==2){
                n2++;
                ans=i;
            }
        }
        if(n2==1){
            printf("Case #%d: %d\n",tmp++,ans);
        }
        if(n2>1){
            printf("Case #%d: Bad magician!\n",tmp++);
        }
        if(n2==0){
            printf("Case #%d: Volunteer cheated!\n",tmp++);
        }
    }
}
