#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

const int maxn = 10;

char M[maxn][maxn];

int main(){
    //freopen("A-small-attempt1","r",stdin);
    freopen("outans","w",stdout);
    int kase = 0,t,T,O,X,none,tag,winner;
    scanf("%d",&t);
    while(t--){
        tag = winner = 0; kase++;
        getchar();
        for(int i = 0;i < 4;i++)
            gets(M[i]);

        for(int i = 0;i < 4;i++){
            T = X = O = none = 0;
            for(int j = 0;j < 4;j++){
                if(M[i][j] == 'O') O++;
                else if(M[i][j] == 'X') X++;
                else if(M[i][j] == 'T') T++;
                else none++;
            }
            if(none) { tag = 1; continue; }
            else if((O == 3 && T == 1) || O == 4) winner = 1;
            else if((X == 3 && T == 1) || X == 4) winner = 2;
        }
        for(int i = 0;i < 4;i++){
            T = X = O = none = 0;
            for(int j = 0;j < 4;j++){
                if(M[j][i] == 'O') O++;
                else if(M[j][i] == 'X') X++;
                else if(M[j][i] == 'T') T++;
                else none++;
            }
            if(none) { tag = 1; continue; }
            else if((O == 3 && T == 1) || O == 4) winner = 1;
            else if((X == 3 && T == 1) || X == 4) winner = 2;
        }

        T = X = O = none = 0;
        for(int i = 0;i < 4;i++){
            if(M[i][i] == 'O') O++;
            else if(M[i][i] == 'X') X++;
            else if(M[i][i] == 'T') T++;
            else none++;
        }
        if((O == 3 && T == 1) || O == 4) winner = 1;
        else if((X == 3 && T == 1) || X == 4) winner = 2;

        T = X = O = none = 0;
        for(int i = 0;i < 4;i++){
            if(M[i][3-i] == 'O') O++;
            else if(M[i][3-i] == 'X') X++;
            else if(M[i][3-i] == 'T') T++;
            else none++;
        }
        if((O == 3 && T == 1) || O == 4) winner = 1;
        else if((X == 3 && T == 1) || X == 4) winner = 2;

        if(!winner && !tag) printf("Case #%d: Draw\n",kase);
        else if(!winner && tag) printf("Case #%d: Game has not completed\n",kase);
        else if(winner == 1) printf("Case #%d: O won\n",kase);
        else printf("Case #%d: X won\n",kase);
    }
    return 0;
}
