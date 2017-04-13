#include  <cstdio>
#include  <cstdlib>
#include  <cstring>

int main(int argc, char *argv[])
{
    int T = 0, cas = 1;

    scanf("%d", &T);
    while (T--){
        int N = 0, sum = 0, min = 0x7fffffff;
        int num = 0, total = 0;
        scanf("%d", &N);
        for (int i = 0; i<N; i++){
            scanf("%d", &num);
            sum ^= num;
            total += num;
            if (num < min){
                min = num;
            }
        }

        printf("Case #%d: ", cas++);
        if (sum != 0){
            printf("NO\n");
        }else{
            printf("%d\n", total - min);
        }
    }
    return 0;
}
