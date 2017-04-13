#include<stdio.h>
#define ll long long

int T;
ll N, R;

int main() {
    //freopen("A.Bullseye.txt","r",stdin);
    //freopen("A.Bullseye.out","w",stdout);
    
    scanf("%d",&T);
    for (int t = 0; t < T; t++) {
        scanf("%lld %lld",&R,&N);
        ll W, B, ans;
        W = R*R;
        ans = 0;
        for (int i = 1;  ; i++) {
            if (i%2==0) { //White
                R++;
                W = R*R;
            }
            else { //Black
                R++;
                B = R*R - W;
                if ( N - B >= 0) {
                    N -= B;
                    ans++;
                }
                else break;
            }
        }
        printf("Case #%d: %lld\n", t+1, ans);
    }
    return 0;
}
