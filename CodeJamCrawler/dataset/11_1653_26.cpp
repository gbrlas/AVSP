#include <set>
#include <map>
#include <cmath>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <utility>
#include <iostream>
#include <algorithm>
#define LL long long
#define pi 3.1415926535897932384626433 
#define sqr(a) ((a)*(a))

using namespace std;

const int MSpeed = 400;

int X, S, R, T, N;
int L[505];
double w[201010], C, Ans;
double Candy[101010], Tsq[1010];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
    freopen("b.out", "w", stdout);
#endif
    int TT;
    cin >> TT;
    for (int t = 1; t <= TT; t ++)
    {
        cout << "Case #" << t << ": ";
        cin >> X >> S >> R >> T >> N;
        R -= S;
        memset(L, 0, sizeof(L));
/*
        for (int i = 1; i <= x; i ++)
            w[i] = 0;
        */
        L[S] = X;
        for (int i = 1; i <= N; i ++) 
        {
            int st, en, weight;
	        cin >> st >> en >> weight;
            L[S] -= en - st; L[weight + S] += en - st;
        }
/*        sort(w + 1, w + 1 + x);
        double Ans = 0;
        for (int i = 1; i <= min(x, v); i ++)
            Ans += 1.0 / (w[i] + t), cout << w[i] + t << endl;
*/
        C = T;

/*        for (int i = min(x, v) + 1; i <= x; i ++)
            Ans += 1.0 / (w[i] + s), cout << w[i] + s << endl; */

        Ans = 0;
        for (int i = 0; i <= MSpeed; i ++) 
            if (L[i]) 
            {
                double twb = (double) L[i] / double(i + R);
                /*
                for (int lp = i + 1; lp <= MSpeed; lp ++)
                    twb -= L[j] / double(j);
                Ans *= C;
                */
                if (twb <= C) 
                    Ans += twb, C -= twb;
                else 
                {
                    double D = (double) L[i] - double(i + R) * C;
                    /*
                    Ans += L[i] / double(C);
                    */
                    Ans += D / double(i) + C;
                    for (int lp = i + 1; lp <= MSpeed; lp ++)
                        Ans += double(L[lp]) / double(lp);
                    break;
                }
            }
        printf("%.9lf\n", Ans);
    }
    return 0;
}

