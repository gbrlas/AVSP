#include <stdio.h>

using namespace std;
int m, in[10010][2], v;

int calc(int ind, int val) {

    int l0, l1, r0, r1, min=m, flag=0;

    //printf("before  %d : %d\n", ind, in[ind*2][1]);
    if(in[ind*2][1] == -1) {
        if(in[ind*2][0] == 1) {
            l0 = -1;
            l1 = 0;
        }
        else {
            l0 = 0;
            l1 = -1;
        }
    } else {
    //printf("called %d : %d\n", ind, in[ind*2][1]);
        l0 = calc(ind*2, 0);
        l1 = calc(ind*2, 1);
    }

    if(in[ind*2+1][1] == -1) {
        if(in[ind*2+1][0] == 1) {
            r0 = -1;
            r1 = 0;
        }
        else {
            r0 = 0;
            r1 = -1;
        }
    } else {
        r0 = calc(ind*2+1, 0);
        r1 = calc(ind*2+1, 1);
    }

    if( val == 0) {

        if(l0 != -1 && r0 != -1) {
             min = l0 + r0;
             flag = 1;
        }
        if(l0 != -1 && in[ind][0] == 1) {
            if(min > l0)
             min = l0;
            flag = 1;
        } else if(l0 != -1 && in[ind][1] == 1) {
            if(min > l0+1)
             min = l0+1;
            flag = 1;
        }
        if(r0 != -1 && in[ind][0] == 1) {
            if(min > r0)
             min = r0;
            flag = 1;
        } else if(r0 != -1 && in[ind][1] == 1) {
            if(min > r0+1)
             min = r0+1;
            flag = 1;
        }
        //printf(" %d ret %d\n", ind, min);
        if(flag == 0)
            return -1;
        else
            return min;

    } else {

        //printf(" %d ind %d %d gate %d\n", ind, l1, r1, in[ind][1]);
        if(l1 != -1 && r1 != -1) {
             min = l1 + r1;
             flag = 1;
        }
        if(l1 != -1 && in[ind][0] == 0) {
            if(min > l1)
             min = l1;
            flag = 1;
        } else if(l1 != -1 && in[ind][1] == 1) {
            if(min > l1+1)
             min = l1+1;
            flag = 1;
        }
        //printf(" %d ind %d %d : %d \n", ind, l1, r1, min);
        if(r1 != -1 && in[ind][0] == 0) {
            if(min > r1)
             min = r1;
            flag = 1;
        } else if(r1 != -1 && in[ind][1] == 1) {
            if(min > r1+1)
             min = r1+1;
            flag = 1;
        }
        //printf(" %d ret %d\n", ind, min);
        if(flag == 0)
            return -1;
        else
            return min;

    }
}

int main() {

    int cases, cur;

    scanf(" %d", &cases);

    for(int i=0; i<cases; i++) {
        scanf(" %d %d", &m, &v);
        cur=1;
        for(int j=0; j<(m-1)/2; j++) {
            scanf(" %d %d", &in[cur][0], &in[cur][1]);
            cur++;
        }
        for(int j=0; j<(m+1)/2; j++) {
            scanf(" %d", &in[cur][0]);
            in[cur][1] = -1;
            cur++;
        }
        for(int j=0; j<m; j++) {
//            printf(" %d %d\n", in[j+1][1],j+1);
        }

        int val = calc(1, v);
        if(val == -1) 
            printf("Case #%d: IMPOSSIBLE\n", i+1);
        else
            printf("Case #%d: %d\n", i+1, val);

                
    }
}
