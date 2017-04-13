#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;
int n, m;
const int N = 105;

string D[N];
string L;
char gus[N];
bool visD[N];
bool visLe[N * 2];
bool posable[N * 2];
string ans;
int ansc = -1;

void deal(string tmp)
{
    int count = 0;
    memset(visD, false, sizeof(visD));
    memset(visLe, false, sizeof(visLe));
    memset(posable, false, sizeof(posable));
    for (int i = 0; i < tmp.size(); ++i) gus[i] = ' ';

    for (int i = 0; i < n; ++i)
    {
        if ( tmp.size() != D[i].size() ) visD[i] = true;
        else
        {
            for (int j = 0; j < D[i].size(); ++j) posable[ D[i][j] ] = true;
        }
    }
    for (int i = 0; i < tmp.size(); ++i) visLe[ tmp[i] ] = true;

    for (int i = 0; i < L.size(); ++i)
    {
        if ( posable[ L[i] ] )
        {
            if ( visLe[ L[i] ] )
            {
                for ( int j = 0; j < tmp.size(); ++j) if ( tmp[j] == L[i] )
                {
                    gus[j] = L[i];
                }
                for (int j = 0; j < n; ++j) if ( !visD[j] )
                {
                    int k = 0;
                    for (k = 0; k < D[j].size(); ++k)
                    {
                        if ( gus[k] != ' ' && gus[k] != D[j][k] ||(  D[j][k] == L[i] && gus[k] == ' ') ) break;
                    }
                    if ( k != D[j].size()) visD[j] = true;
                }
            }
            else
            {
                count++;
                for (int j = 0; j < n; ++j) if ( !visD[j] )
                {
                    int k = 0;
                    for (k = 0; k < D[j].size(); ++k)
                    {
                        if ( D[j][k] == L[i] ) break;
                    }
                    if ( k != D[j].size()) visD[j] = true;
                }
            }
            memset(posable, false, sizeof(posable));
            for (int j = 0; j < n; ++j) if ( !visD[j] )
            {
                for (int k = 0; k < D[j].size(); ++k) posable[ D[j][k] ] = true;
            }
        }
    }
    if ( count > ansc )
    {
        ansc = count;
        ans = tmp;
    }
}

int main()
{
    freopen("B.in", "r", stdin);
    freopen("B.out", "w", stdout);
    int cases;
    scanf("%d", &cases);
    int step = 1;
    while (cases--)
    {
        cout << "Case #" << step++ << ":" ;
        cin >> n >> m;
        for (int i = 0; i < n; ++i)
        {
            cin >> D[i];
        }
        for (int i = 0; i < m; ++i)
        {
            cin >> L;
            ans = "";
            ansc = -1;
            for (int j = 0; j < n; ++j)
            {
                string tmp = D[j];
                deal(tmp);
            }
            cout << " " << ans;
        }
        cout << endl;
    }
    return 0;
}
