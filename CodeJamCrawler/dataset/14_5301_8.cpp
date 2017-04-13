#include<cstdio>
int gcd(int a, int b){
    if(b == 0){
        return a;
    }
    return gcd(b, a%b);
}
int main(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int cases, _case=1;
    long long p,q;
    int ans, tmp, t;
    scanf("%d", &cases);
    while(cases--){
        scanf("%lld/%lld", &p, &q);
        tmp = gcd(p, q);
        p /= tmp;
        q /=tmp;
        ans = 0;
        tmp = 0;
        t = q;
        while(t > 1){
            if(t%2==1){
                break;
            }else{
                t/=2;
                tmp++;
            }
        }
        if(t!=1){
            printf("Case #%d: impossible\n", _case++);
        }else{
        while(p < q){
            if(2*p>=q){
                ans++;
                break;
            }
            else{
                p = p*2;
                ans++;
            }
        }
            printf("Case #%d: %d\n", _case++, ans);
        }
    }
    return 0;
}
