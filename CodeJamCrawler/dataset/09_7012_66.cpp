#include <stdio.h>
#include <stdlib.h>
#define MAXH 100
#define MAXW 100
#define MAXV 10001
typedef struct{
    int x;
    int y;
    int id;
}Tponto;

Tponto G[MAXH*MAXW][4];
int p[MAXH*MAXW];
int M[MAXW][MAXH];
int link[30];
Tponto lista[MAXW*MAXH];
int q;
int map[MAXW][MAXH];
int T,H,W;

void DFS(int v,int pai){
    int x,y,id,i;
    for(i=0;i<=p[v];i++){
        x=G[v][i].x;
        y=G[v][i].y;
        id=G[v][i].id;
        map[x][y]=pai;
        DFS(id,pai);
    }
}
int menor(int x,int y){
    int m=MAXV;
    if(x-1>=0 && M[x-1][y]<m)
        m=M[x-1][y];
    if(x+1<H && M[x+1][y]<m)
        m=M[x+1][y];
    if(y-1>=0 && M[x][y-1]<m)
        m=M[x][y-1];
    if(y+1<W && M[x][y+1]<m)
        m=M[x][y+1];
    return m;
}
int main(){


    int i,j;

    int k;
    int marq;
    scanf("%d",&T);
    for(k=0;k<T;k++){

        scanf("%d%d",&H,&W);
        for(i=0;i<H;i++){
            for(j=0;j<W;j++)
                scanf("%d",&M[i][j]);
        }
        //localiza pias,
        for(i=0; i<H;i++)
            for(j=0;j<W;j++)
            map[i][j]=0;
        for(i=0;i<H*W;i++)
            p[i]=-1;

        q=-1;
        marq=1;
        for(i=0;i<H;i++){
            for(j=0;j<W;j++){
                int count=0;
                if((i-1)>=0){
                    if(M[i-1][j]>=M[i][j])
                        count++;
                }
                else
                    count++;
                 if((i+1)<H){
                    if(M[i+1][j]>=M[i][j])
                        count++;
                }
                else
                    count++;
                 if((j-1)>=0){
                    if(M[i][j-1]>=M[i][j])
                        count++;
                }
                else
                    count++;
                 if((j+1)<W){
                    if(M[i][j+1]>=M[i][j])
                        count++;
                }
                else
                    count++;
                if(count==4){
                    Tponto aux;
                    map[i][j]=marq++;
                    aux.id=i*W+j;
                    aux.x=i;
                    aux.y=j;

                    lista[++q]=aux;
                  //printf("\n in %d %d %d",i,j,map[i][j]);
                }
            }
        }
        //montar o grafo
        for(i=0;i<H;i++){
            for(j=0;j<W;j++){
                int key;
                int m=menor(i,j);
                if(map[i][j]!=0)
                    continue;
                if(i-1>=0 && M[i-1][j]==m){
                   key=(i-1)*W+j;
                   G[key][++p[key]].id=i*W+j;
                    G[key][p[key]].x=i;
                    G[key][p[key]].y=j;
       //       printf("\nnorte");
            }
            else if(j-1>=0 && M[i][j-1]==m){
                 key=(i)*W+j-1;
                   G[key][++p[key]].id=i*W+j;
                G[key][p[key]].x=i;
                    G[key][p[key]].y=j;
            }

            else if(j+1<W && M[i][j+1]==m){
                key=(i)*W+j+1;
                   G[key][++p[key]].id=i*W+j;
                G[key][p[key]].x=i;
                    G[key][p[key]].y=j;
            }
            else if(i+1<H && M[i+1][j]==m){
                key=(i+1)*W+j;
                   G[key][++p[key]].id=i*W+j;
                G[key][p[key]].x=i;
                    G[key][p[key]].y=j;
            }
            }
        }
        for(i=0;i<=q;i++){
            int x,y;
            x=lista[i].x;
            y=lista[i].y;

            DFS(lista[i].id,map[x][y]);
        }
        //exibir

        printf("Case #%d:\n",k+1);
        memset(link,0,sizeof(link));
        int x=0;
        for(i=0;i<H;i++){
            if(link[map[i][0]]==0)
                    link[map[i][0]]=++x;
            printf("%c",link[map[i][0]]+'a'-1);
            for(j=1;j<W;j++){
                if(link[map[i][j]]==0)
                    link[map[i][j]]=++x;
                printf(" %c",link[map[i][j]]+'a'-1);
            }
            printf("\n");
        }
        }
}




