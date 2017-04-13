#include<stdio.h>
#include<string.h>

#define maxn 1000

int di[4][2]={
    -1,0,
    0,-1,
    0,1,
    1,0
};

int p[maxn][maxn];

bool checked[maxn][maxn];

int color[maxn][maxn],cn;

int i,j,n,m;

int make(int a,int b){
    if(!checked[a][b])return color[a][b];
    checked[a][b]=0;
    int aa,bb,i,ansi=-1,ans=p[a][b],sun;
    for(i=0;i<4;i++){
        aa=a+di[i][0];bb=b+di[i][1];
        if(p[aa][bb]>=0){
            if(p[aa][bb]<ans){
                ans=p[aa][bb];ansi=i;
            }
        }
    }
    if(ansi==-1){
        sun=cn++;
    }else {
        aa=a+di[ansi][0];bb=b+di[ansi][1];
        sun=make(aa,bb);
    }
    color[a][b]=sun;
    return sun;

}

int main(){
    int ii,nn;
    scanf("%d",&nn);
    for(ii=1;ii<=nn;ii++){
        printf("Case #%d:\n",ii);
        scanf("%d %d",&n,&m);
        memset(checked,0,sizeof(checked));
        memset(p,-1,sizeof(p));
        for(i=1;i<=n;i++)for(j=1;j<=m;j++){
                scanf("%d",&p[i][j]);
                checked[i][j]=1;
            }
        cn=0;
        for(i=1;i<=n;i++)for(j=1;j<=m;j++)if(checked[i][j]){
                    make(i,j);
            }
        for(i=1;i<=n;i++){
            for(j=1;j<m;j++)printf("%c ",color[i][j]+'a');
            printf("%c\n",color[i][j]+'a');
        }
    }
    return 0;
}
