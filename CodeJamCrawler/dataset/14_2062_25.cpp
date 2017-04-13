#include<stdio.h>
int v[6][6],v2[6][6];
void proc(int t){
    int i,j;
    int s,e;
    scanf("%d",&s);
    for(i=1;i<=4;i++){
        for(j=1;j<=4;j++)scanf("%d",&v[i][j]);
    }
    scanf("%d",&e);
    for(i=1;i<=4;i++){
        for(j=1;j<=4;j++)scanf("%d",&v2[i][j]);
    }
    int ans=0;
    for(i=1;i<=4;i++){
        for(j=1;j<=4;j++){
            if(v[s][i]==v2[e][j]){
                if(ans>0){
                    ans=-1;

                    break;
                }
                if(!ans){
                    ans=v[s][i];
                    break;
                }
            }
        }
    }
    printf("Case #%d: ",t);
    if(!ans){
        printf("Volunteer cheated!\n");
    }
    else if(ans==-1){
        printf("Bad magician!\n");
    }
    else{
        printf("%d\n",ans);
    }
}
int main(){
    int tt;
    scanf("%d",&tt);
    int i;
    for(i=0;i<tt;i++)proc(i+1);
    return 0;
}
