#include  <cstdio>
#include  <cstdlib>
#include  <cstring>
#include  <cmath>

char comb[256][256] = {{0}};
char opps[256][256] = {{0}};

int main(int argc, char *argv[])
{
    int T = 0, cas = 1;
    scanf("%d", &T);

    while (T--){
        int C = 0, D = 0,N = 0;
        char buff[32];
        memset(comb, 0, sizeof(comb));
        memset(opps, 0, sizeof(opps));

        scanf("%d", &C);
        for (int i = 0; i<C; i++){
            scanf("%s", buff);
            comb[buff[0]][buff[1]] = comb[buff[1]][buff[0]] = buff[2];
        }

        scanf("%d", &D);
        for (int i = 0; i<D; i++){
            scanf("%s", buff);
            opps[buff[0]][buff[1]] = opps[buff[1]][buff[0]] = 1;
        }

        scanf("%d", &N);
        char stack[1024] = {0};
        char seq[1024] = {0};
        int top = 0;

        scanf("%s", seq);

        for (int i = 0; i<N; i++){
            stack[top] = seq[i];
            if (top>=1 && comb[stack[top]][stack[top-1]] != 0){
                stack[top-1] = comb[stack[top]][stack[top-1]];
            }else{
                top++;
            }

            for (int i = 0; i<top-1; i++){
                if (opps[stack[i]][stack[top-1]] != 0){
                    top = 0;
                    break;
                }
            }
        }

        if (top == 0){
            printf("Case #%d: []\n", cas++);
        }else{
            printf("Case #%d: [", cas++);
            printf("%c", stack[0]);
            for (int i = 1; i<top; i++){
                printf(", %c", stack[i]);
            }
            printf("]\n");
        }
    }
    return 0;
}
