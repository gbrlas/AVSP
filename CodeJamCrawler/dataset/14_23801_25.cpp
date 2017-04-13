#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <iostream>
#include <stack>
#include <set>
using namespace std;
typedef long long LL;
const int maxn = 100 + 5;
const int mod = 1000000000 + 7;

int matrix1[maxn][maxn];
int matrix2[maxn][maxn];

int main(){
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("out", "w", stdout);
    int t,kase = 0;
    scanf("%d",&t);
    while(t--){
        kase++;
        int row1,row2;
        scanf("%d",&row1);
        for(int i = 1;i <= 4;i++){
            for(int j = 1;j <= 4;j++){
                scanf("%d",&matrix1[i][j]);
            }
        }

        scanf("%d",&row2);
        for(int i = 1;i <= 4;i++){
            for(int j = 1;j <= 4;j++){
                scanf("%d",&matrix2[i][j]);
            }
        }
        vector<int> v;
        for(int i = 1;i <= 4;i++){
            for(int j = 1;j <= 4;j++){
                if(matrix1[row1][i] == matrix2[row2][j]){
                    v.push_back(matrix1[row1][i]);
                }
            }
        }
        printf("Case #%d: ",kase);
        if(v.size() == 0){
            printf("Volunteer cheated!\n");
        }
        else if(v.size() == 1){
            printf("%d\n",v[0]);
        }
        else{
            printf("Bad magician!\n");
        }
    }
    return 0;
}





