#include  <cstdio>
#include  <cstdlib>
#include  <cstring>

int main(int argc, char *argv[])
{
    int T = 0, cas = 1;
    
    scanf("%d", &T);
    while (T--){
        int N = 0;
        scanf("%d", &N);

        double res = 0.0;
        for (int i = 0; i<N; i++){
            int x = 0;
            scanf("%d", &x);
            if (x != i+1){
                res += 1.0000000;
            }
        }

        printf("Case #%d: %.6lf\n", cas++, res);
    }
    return 0;
}
