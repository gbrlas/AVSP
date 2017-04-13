#include <cstdio>
#include <algorithm>

using namespace std;
#define N 10001

int tests;
int n;

int d[N];
int l[N];
int b[N];
int dist;

int main(){

    scanf("%d", &tests);

    for(int z = 0; z < tests; z++){
        scanf("%d", &n);

        for(int j = 0; j < n; j++){
            scanf("%d %d", d + j, l + j);
            b[j] = 0;
        }

        scanf("%d", &dist);

        b[0] = d[0];
        d[n] = dist;
        b[n] = -1;

        for(int i = 0; i < n; i++){
            for(int j = i + 1; j <= n; j++){
                if(d[i] + b[i] >= d[j]){
                    b[j] = max(b[j], min(d[j] - d[i], l[j]));
                }
            }
        }

        if(b[n] == -1){
            printf("Case #%d: NO\n", z + 1);
        } else {
            printf("Case #%d: YES\n", z + 1);
        }
    }

    return 0;
}
