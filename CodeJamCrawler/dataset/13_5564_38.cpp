#include <stdio.h>
#include <cmath>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#define mod  1000007
using namespace std;
#define ull unsigned long long
#define ill long long int
#define pii pair<int,int>
#define pb(x) push_back(x)
#define F(i,a,n) for(i=(a);i<(n);++i)
#define FD(i,a,n) for(i=(a);i>=(n);--i)
#define FE(it,x) for(it=x.begin();it!=x.end();++it)
#define V(x) vector<x>
#define S(x) scanf("%d",&x)
#define S1(x) scanf("%lld",&x)
#define M(x,i) memset(x,i,sizeof(x))

int dp[101][101][2][2][101];
int aa[] = {0, 0, 1, -1};
int bb[] = {1, -1, 0, 0};
string pp;
int f1,f2;
int x,y,flag;
int cc (int x)
{
    if (x < 0) {
        return 1;
    }
    return 0;
}
string result;
int f (int sx, int sy, int ff1, int ff2, int moves, string ss)
{
    if (flag == 1) {
        return 10000;
    }
    if (sx == x && sy == y && ff1 == f1 && ff2 == f2) {
        result = ss;
        flag = 1;
        return 0;
    }
    int &result = dp[sx][sy][ff1][ff2][moves];
    if (result != -1) {
        return result;
    }
    if (ff1 == 1) {
        sx = sx * (-1);
    }
    if (ff2 == 1) {
        sy = sy * (-1);
    }

    result = 10000;
    int i,px,py;
    F (i, 0, 4) {
        px = sx + (moves+1)*aa[i];
        py = sy + (moves+1)*bb[i];
        if (abs(px) > 100 || abs(py) > 100) {
            continue;
        }
        if (flag == 1) {
            return 10000;
        }
        result = min (result, 1 + f (abs (px), abs (py), cc (px), cc (py), moves+1, ss + pp[i]));
    }
    return result;
}


int main()
{
    pp ="NSEW";
    int t;
    freopen("iii.in","r",stdin);
    freopen ("output.txt", "w", stdout);
    S (t);
    int ii = 1;
    while (t--) {
        memset (dp, -1, sizeof(dp));
        S (x);  S (y);
        if (x < 0) {
            f1 = 1;
        } else {
            f1 = 0;
        }
        if (y < 0) {
            f2 = 1;
        } else {
            f2 = 0;
        }
        flag = 0;
        x = abs (x);    y = abs (y);
        int k = 1 + f (0, 0, 0, 0, 0, "");
        cout << "Case #" << ii << ": ";
        ii++;
        cout << result << endl;
    }


    return 0;
}
