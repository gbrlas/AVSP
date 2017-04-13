#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

typedef struct node{
    int stop;
    long long plus;
}node, *NODE;

typedef struct stk{
    int stop;
    long long num;
}stk, *STK;

node evt[4096];
int evt_cnt = 0;

stk stack[4096];
int top = 0;
long long MOD = 1000002013;

bool operator < (const node &a, const node &b){
    if (a.stop != b. stop){
        return a.stop < b.stop;
    }else{
        return a.plus > b.plus;
    }
}

long long calc(long long start, long long end, long long p, long long N){
    long long P = (p % MOD);
    long long X = (end - start);
    long long res = (((X * N)%MOD - ((X%MOD) * ((X-1)%MOD))%MOD * 500001007 % MOD) % MOD + MOD) %MOD;
    res = (res * P) % MOD;
    return res;
}

int main()
{
    int T = 0;
    long long cost = 0, reduce = 0, p = 0;
    int N = 0, M = 0;

    cin >> T;
    for (int cas = 1; cas <= T; cas++){
        cin >> N >> M;
        evt_cnt = top = 0;
        cost = reduce = 0;

        for (int i = 0; i < M; i++){
            long long start = 0, end = 0;
            cin >> start >> end >> p;
            cost = (cost + calc(start, end, p, N)) % MOD;

            evt[evt_cnt].stop = start;
            evt[evt_cnt].plus = p;
            evt_cnt++;

            evt[evt_cnt].stop = end;
            evt[evt_cnt].plus = 0 - p;
            evt_cnt++;
        }

        sort(evt, evt + evt_cnt);

        top = 0;
        for (int i = 0; i<evt_cnt; i++){
            if (evt[i].plus > 0){
                stack[top].stop = evt[i].stop;
                stack[top].num = evt[i].plus;
                top++;
            }else{
                long long ext = 0 - evt[i].plus;
                while (ext > 0){
                    long long p = stack[top-1].num;
                    long long start = stack[top-1].stop;
                    long long end = evt[i].stop;
                    if (p > ext){
                        stack[top-1].num -= ext;
                        p = ext;
                        ext = 0;
                    }else{
                        ext -= p;
                        top--;
                    }
                    reduce = (reduce + calc(start, end, p, N)) % MOD;
                }
            }
        }
        long long res = ((cost - reduce) % MOD + MOD)%MOD;
        cout << "Case #" << cas << ": " << res << endl;
    }
    return 0;
}
