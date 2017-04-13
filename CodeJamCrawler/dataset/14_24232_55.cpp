#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#define LOCAL
using namespace std;
int main()
{
#ifdef LOCAL
    freopen("A-small-attempt2.in", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif // LOCAL

   int t, r1, r2;
   int arrA[4][4], arrB[4][4];
   scanf("%d", &t);

   for(int c = 1; c <= t; c++){

    scanf("%d", &r1);
    for(int j = 0; j < 4; j++){
        for(int k =0; k < 4; k++)
            scanf("%d", &arrA[j][k]);
    }
    scanf("%d", &r2);
    for(int j = 0; j < 4; j++){
        for(int k =0; k <4 ; k++){
            scanf("%d", &arrB[j][k]);
        }
    }

    r1--;
    r2--;
    int count = 0, ans;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(arrA[r1][i] == arrB[r2][j]){
                count++;
                ans = arrA[r1][i];
            }
        }
    }

    if(count == 1){
        printf("Case #%d: %d\n", c, ans);
    }else if(count > 1){
        printf("Case #%d: Bad magician!\n", c);
    }else{
        printf("Case #%d: Volunteer cheated!\n", c);
    }
   }
   return 0;
}
