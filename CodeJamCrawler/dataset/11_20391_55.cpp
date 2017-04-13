#include <iostream>
#include <queue>
#include <string>
#include <memory.h>
#include <stdio.h>
using namespace std;

string g[128];
double wp[128];
double owp[128];
double oowp[128];
int n;

void solve()
{
    memset(wp, 0, sizeof(wp));
    memset(owp, 0, sizeof(owp));
    memset(oowp, 0, sizeof(oowp));
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> g[i];
    }
    for(int i = 0; i < n; i++)
    {
        int cnt = 0;
        int gc = 0;
        for(int j = 0; j < n; j++)
        {
            if(g[i][j] != '.')
                cnt++;
            if(g[i][j] == '1')
                gc++;
        }
        if(cnt > 0)
            wp[i] = (gc + 0.0) / (cnt + 0.0);
    }
    for(int i = 0; i < n; i++)
    {
        int cnt = 0;
        for(int j = 0; j < n; j++)
        {
            if(g[i][j] != '.')
            {
                cnt++;
                int cnt2 = 0;
                int gc = 0;
                for(int k = 0; k < n; k++)
                {
                    if(k != i)
                    {
                        if(g[j][k] != '.')
                            cnt2++;
                        if(g[j][k] == '1')
                            gc++;
                    }
                }
                if(cnt2 > 0)
                    owp[i] += (gc + 0.0) / (cnt2 + 0.0);
            }
        }
        if(cnt > 0)
            owp[i] /= cnt;
    }
    for(int i = 0; i < n; i++)
    {
        int cnt = 0;
        for(int j = 0; j < n; j++)
        {
            if(g[i][j] != '.')
            {
                cnt++;
                oowp[i] += owp[j];
            }
        }
        if(cnt > 0)
            oowp[i] /= cnt;
    }
    for(int i = 0; i < n; i++)
    {
        printf("\n%.7lf", 0.25 * wp[i] + 0.50 * owp[i] + 0.25 * oowp[i]);
    }
}

int main()
{
    freopen("/home/bellnox/input.txt", "r", stdin);
    freopen("/home/bellnox/output.txt", "w", stdout);
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        cout << "Case #" << (i + 1) << ": ";
        solve();
        cout << endl;
    }
    return 0;
}