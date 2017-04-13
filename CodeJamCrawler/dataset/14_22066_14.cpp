#include <stdio.h>
#include <cstring>

using namespace std;

int r[20];

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int T;
    scanf("%d", &T);
    int n,m;
    int ans;
    int up;
    int cnt = 1;
    while(T--){
        scanf("%d", &n);
        memset(r, 0, sizeof(r));
        int tmp;
        for(int i = 0; i < 16; i++){
            scanf("%d", &tmp);
            if(i / 4 + 1 == n) r[tmp] = 1;
        }
        ans = 0;
        scanf("%d", &m);
        for(int i = 0; i < 16; i++){
            scanf("%d", &tmp);
            if(i / 4 + 1 == m && r[tmp] == 1){
                ans++;
                up = tmp;
            }
        }
        printf("Case #%d: ", cnt++);
        if(ans == 1) printf("%d\n", up);
        else if(ans == 0) printf("Volunteer cheated!\n");
        else printf("Bad magician!\n");
    }
    return 0;
}
