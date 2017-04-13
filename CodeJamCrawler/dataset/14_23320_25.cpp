#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <iomanip>
#include <stdio.h>
#include <string>
#include <queue>
#include <cmath>
#include <stack>
#include <map>
#include <set>
#define eps 1e-7
#define M 1000100
//#define LL __int64
#define LL long long
#define INF 0x3fffffff
#define PI 3.1415926535898
#define MOD 1000000007

using namespace std;

const int maxn = 22;
int vis[maxn];

int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
    int T;
    cin >>T;
    for(int t = 1; t <= T; t++)
    {
        memset(vis, 0 , sizeof(vis));
        int n, m;
        int x;
        cin >>n;
        for(int i = 1; i <= 4; i++)
        {
            for(int j = 1; j <= 4; j++)
            {
                cin >>x;
                if(n == i)
                    vis[x] = 1;
            }
        }
        int cnt = 0;
        cin >>m;
        int xx;
        for(int i = 1; i <= 4; i++)
        {
            for(int j = 1; j <= 4; j++)
            {
                cin >>x;
                if(i == m)
                {
                    if(vis[x])
                    {
                        cnt++;
                        xx = x;
                    }
                }
            }
        }
        cout<<"Case #"<<t<<": ";
        if(cnt == 0)
            cout<<"Volunteer cheated!"<<endl;
        else if(cnt == 1)
            cout<<xx<<endl;
        else
            cout<<"Bad magician!"<<endl;
    }
    return 0;
}
