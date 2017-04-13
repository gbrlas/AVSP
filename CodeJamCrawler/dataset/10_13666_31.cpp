#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <set>
#include <queue>
#include <vector>
#include <map>
#include <stack>
#include <list>
#include <numeric>

#define pii pair<int,int>
#define FOR(i,n) for (int i = 1, _n = n; i <= _n; i++)
#define FOD(i,n) for (int i = n; i >= 0; i--)
#define MAXINT 1000000000

using namespace std;

int tc, r,x1,x2,y1,y2,my,mx;
int A[305][305], B[305][305];

bool dead(){
    for (int i = 0; i <= my; i++) for (int j = 0; j <= mx; j++) if (A[i][j] != 0) return false;
    return true;
}

void sim(){
    for (int i = 1; i <= my; i++) for (int j = 1; j <= mx; j++){
        B[i][j] = A[i][j];
        if (A[i][j] == 1){
            if (A[i-1][j] == 0 && A[i][j-1] == 0) B[i][j] = 0;
        }else{
            if (A[i-1][j] == 1 && A[i][j-1] == 1) B[i][j] = 1;
        }
    }
    for (int i = 1; i <= my; i++) for (int j = 1; j <= mx; j++) A[i][j] = B[i][j];
}

int main(){
    freopen("C-small-attempt3.in","r",stdin);
    //freopen("input2.txt","r",stdin);
    scanf("%d ",&tc);
    for (int TC = 1; TC <= tc; TC++){
        printf("Case #%d: ",TC);
        scanf("%d ",&r);
        if (r == 0){
            printf("0\n"); continue;
        }
        my = mx = 0;
        memset(A, 0, sizeof A);
        while (r--){
            scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
            for (int i = y1; i <= y2; i++) for (int j = x1; j <= x2; j++) A[i][j] = 1;
            my = max(my, y2+2); mx = max(mx, x2+2);
        }
        int T = 0;
        while (true){
            if (dead()) break;
            sim();
            /*for (int i = 0; i <= my; i++){
                for (int j = 0; j <= mx; j++) printf("%d ",A[i][j]);
                printf("\n");
            }
            printf("B\n");
            for (int i = 0; i <= my; i++){
                for (int j = 0; j <= mx; j++) printf("%d ",B[i][j]);
                printf("\n");
            }
            printf("\n");*/
            T++;
        }
        printf("%d\n",T);
    }
    return 0;
}
