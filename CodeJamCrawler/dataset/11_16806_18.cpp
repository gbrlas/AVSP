#include <stdio.h>
#include <string.h>


bool place_red(bool **m,char** in, int row,int col){
    if(m[row][col]&&m[row][col+1]&&m[row+1][col]&&m[row+1][col+1]){
        m[row][col]=m[row][col+1]=m[row+1][col]=m[row+1][col+1]=false;
        in[row][col]='/';
        in[row+1][col]='\\';
        in[row][col+1]='\\';
        in[row+1][col+1]='/';
        return true;
    }
    return false;
}

int main(){
    freopen("input","rt",stdin);
    freopen("out","wt",stdout);

    int cases;
    scanf("%d",&cases);

    for(int iCase=0;iCase<cases;++iCase){
        int w,h;
        scanf("%d %d",&h,&w);

        char **input = new char*[h];
        bool **m = new bool*[h];
        int bt=0;

        bool imposs = false;
        for(int i=0;i<h;i++){
            m[i] = new bool[w];
            input[i] = new char[w];
            scanf("%s",input[i]);

            int rb = 0;
            for(int j=0;j<w;j++){
                bool t;
                t = m[i][j] = input[i][j] == '#';
                if(t) rb+=1,bt+=1;
            }
            if(rb%2) imposs = true;
        }
        printf("Case #%d:\n",iCase+1);
        if(imposs){
            puts("Impossible");
            continue;
        }

        int k=0;
        bool above = false;
        bool ok = true;
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if(m[i][j]){
                    if(i<h-1 && place_red(m,input,i,j)) ++j;
                }
            }
        }
        for(int i=0;i<h&&ok;i++)
            for(int j=0;j<w;j++)
                if(m[i][j]){ok = false; imposs = true; break;}

        if(imposs)
            puts("Impossible");
        else{
            for(int i=0;i<h;i++){
                printf("%s\n",input[i]);
            }
        }
    }
    return 0;
}
