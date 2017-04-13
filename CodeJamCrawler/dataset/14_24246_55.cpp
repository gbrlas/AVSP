#include <cstdio>
#include <string>
#include <algorithm>
#define Local

using namespace std;

int main()
{
#ifdef Local
    freopen("D-large.in", "r", stdin);
    freopen("out2.txt", "w", stdout);
#endif // Local

    int t, n;
    float arrA[1001], arrB[1001];
    scanf("%d", &t);

    for(int ca = 1; ca <= t; ca++){
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%f", arrA+i);
        for(int i = 0; i < n; i++)
            scanf("%f", arrB+i);

        sort(arrA, arrA+n);
        sort(arrB, arrB+n);

        int ta = n-1, tb1 = 0, tb2 = n-1, ans1 = 0, ans2 = 0;
        while(ta >= 0){
            if(arrA[ta] > arrB[tb2]){
                ans1++;
                ta--;
                tb1++;
            }else{
                ta--;
                tb2--;
            }
        }

        ta = 0;
        tb1 = 0;
        tb2 = n-1;
        while(ta < n){
            if(arrA[ta] < arrB[tb1]){
                ta++;
                tb2--;
            }else{
                ans2++;
                ta++;
                tb1++;
            }
        }
        printf("Case #%d: %d %d\n", ca, ans2, ans1);
    }
    return 0;
}
