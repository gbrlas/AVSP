#include <cstdio>
#include <iostream>

#define MAX 102

using namespace std;

bool solve(int tc)
{
    int a[MAX][MAX];
    int row[MAX], col[MAX];
    int n, m;
    int i, j;

    cin >> n >> m;
    for(i=0; i<n; i++)
        for(j=0; j<m; j++)
            cin>>a[i][j];

    for(i=0; i<n; i++)
    {
        row[i] = 0;
        for(j=0; j<m; j++)
            if(a[i][j] > row[i])
                row[i] = a[i][j];
    }

    for(j=0; j<m; j++)
    {
        col[j] = 0;
        for(i=0; i<n; i++)
            if(a[i][j] > col[j])
                col[j] = a[i][j];
    }


    for(i=0; i<n; i++)
        for(j=0; j<m; j++)
            if(a[i][j] < row[i] && a[i][j] < col[j])
                return  false;

    return true;
}


int main()
{
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("op.out", "w", stdout);

    int t;
    cin>>t;
    for(int tc=1; tc<=t; tc++)
    {
        if(solve(tc))
            cout << "Case #" << tc << ": YES" << endl;
        else
            cout << "Case #" << tc << ": NO" << endl;
    }

    return 0;
}
