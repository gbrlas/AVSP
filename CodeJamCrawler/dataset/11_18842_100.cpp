#include  <cstdio>
#include  <cstdlib>
#include  <cstring>
#include  <cmath>

typedef struct node{
    int rob;
    int idx;
}node,*NODE;

node task[256];

int main(int argc, char *argv[])
{
    int T  = 0, N = 0, cas = 1;

    scanf("%d", &T);
    while (T--){
        scanf("%d", &N);

        for (int i = 0; i<N; i++){
            char buf[16];
            scanf("%s %d", buf, &task[i].idx);
            if (buf[0] == 'O'){
                task[i].rob = 0;
            }else{
                task[i].rob = 1;
            }
        }

        int now = 0, Op = 1, Bp = 1, Ot = 0, Bt = 0;
        for (int i = 0; i<N; i++){
            if (task[i].rob == 0){
                int consum = abs(task[i].idx - Op);
                int ava = now - Ot;
                if (ava < consum){
                    now += consum - ava;
                }
                now++;
                Ot = now;
                Op = task[i].idx;
            }else{
                int consum = abs(task[i].idx - Bp);
                int ava = now - Bt;
                if (ava < consum){
                    now += consum - ava;
                }
                now++;
                Bt = now;
                Bp = task[i].idx;
            }
        }

        printf("Case #%d: %d\n", cas++, now);
    }

    return 0;
}
