#include <cstdio>
#include <memory.h>
using namespace std;
int main(){
    int t;
    int a[100];
    int b[5][5];
    int c1,c2;
    scanf("%d",&t);
    for (int cases = 1; cases <= t; cases++){
        memset(a,0,sizeof(a));
        scanf("%d",&c1);
        for (int i = 1; i <= 4; i++){
            for (int j = 1; j <= 4; j++)
                scanf("%d",&b[i][j]);
        }
        for (int i = 1; i <=4; i++){
            a[b[c1][i]] ++;
        }
        scanf("%d",&c2);
        for(int i = 1;i <=4; i++)
            for (int j = 1; j <= 4; j++)
                scanf("%d",&b[i][j]);

        for(int i =1; i <= 4; i++){
            a[b[c2][i]] ++;
        }
        int k = 0;
        int ans = 0;
        for (int i = 1; i <= 16; i++){
            if (a[i] == 2){
                k++;
                ans = i;
            }
        }
        printf("Case #%d: ",cases);
        if ( k == 0){
            printf("Volunteer cheated!\n");
        }else
            if (k > 1){
                printf("Bad magician!\n");
            }
            else {
                printf("%d\n",ans);
            }
    }
    return 0;
}
