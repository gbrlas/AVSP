#include<stdio.h>
#include<string.h>
void solve();
int main(){
    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);
    int t,i;
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        printf("Case #%d: ",i);
        solve();
    }
    return 0;
}
char a[5][5];
int o[10],x[10];
void solve(){
     int i,j,flag,winner;
     memset(a,0,sizeof(a));
     memset(o,0,sizeof(o));
     memset(x,0,sizeof(x));
     flag=0;winner=0;
     for(i=0;i<4;i++)scanf("%s",a[i]);
     for(i=0;i<4&&!winner;i++)
         for(j=0;j<4&&!winner;j++){
             if(a[i][j]=='.'){flag=1;continue;}
             if(a[i][j]=='O'||a[i][j]=='T'){
                 if(++o[i]==4)winner=1;
                 if(++o[j+4]==4)winner=1;
                 if(i==j)if(++o[8]==4)winner=1;
                 if(i+j==3)if(++o[9]==4)winner=1;
             }
             if(a[i][j]=='X'||a[i][j]=='T'){
                 if(++x[i]==4)winner=2;
                 if(++x[j+4]==4)winner=2;
                 if(i==j)if(++x[8]==4)winner=2;
                 if(i+j==3)if(++x[9]==4)winner=2;
             }
         }
     if(winner==1)printf("O won\n");
     else if(winner==2)printf("X won\n");
     else if(flag)printf("Game has not completed\n");
     else printf("Draw\n");
}
