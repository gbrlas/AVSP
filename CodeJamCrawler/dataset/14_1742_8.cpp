#include<stdio.h>
int main(){
    freopen("B-small-attempt0.in", "r",stdin);
    freopen("out.txt", "w", stdout);
    int t;
    scanf("%d", &t);
    for(int tt=1; tt<=t; tt++){
    int a, b, i, j, k, cc=0;
    scanf("%d %d %d", &a, &b, &k);
    for(i=0; i<a; i++){
        for(j=0; j<b; j++){
            if((i&j)<k)cc++;
        }
    }
    printf("Case #%d: %d\n",tt, cc);
    }
    return 0;
}
