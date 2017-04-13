#include <iostream>
#include <cstdio>
using namespace std;

char map[50][50];

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int tt,r,c;
    char empty[10];
    scanf("%d",&tt);
    for (int t=1;t<=tt;t++){
        scanf("%d%d",&r,&c);
        gets(empty);
        for (int i=0;i<r;i++){
            for (int j=0;j<c;j++) scanf("%c",&map[i][j]);
            gets(empty);
        }
        bool flag=true;
        int temp;
        for (int i=0;i<r-1;i++)
            for (int j=0;j<c-1;j++)
                if (flag){
                    temp=0;
                    if (map[i][j]=='#'){
                        if (map[i+1][j]=='#') temp++;
                        if (map[i][j+1]=='#') temp++;
                        if (map[i+1][j+1]=='#') temp++;
                        if (temp>0&&temp!=3) flag=false;
                        else if (temp==3){
                            map[i][j]='/';
                            map[i+1][j]='\\';
                            map[i][j+1]='\\';
                            map[i+1][j+1]='/';
                        }
                    }
                }

        printf("Case #%d:\n",t);

        if (!flag){
            printf("Impossible\n");
        }
        else{
            bool fv=false;
            for (int i=0;i<r;i++)
                for (int j=0;j<c;j++)
                    if (map[i][j]=='#'&&!fv){printf("Impossible\n");fv=true;}
            if (!fv)
            for (int i=0;i<r;i++){
                for (int j=0;j<c;j++) printf("%c",map[i][j]);
                printf("\n");
            }
        }
    }
    return 0;
}
