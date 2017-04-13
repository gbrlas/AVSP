#include <iostream>
#include <queue>

using namespace std;

int N, M;
int g[100][100];
int b[100][100];

bool check()
{
    priority_queue<int, vector<int>, greater<int>> rows[100];
    priority_queue<int, vector<int>, greater<int>> cols[100];
    int max_in_row[100];
    int max_in_col[100];

    memset(max_in_row, 0xFF, sizeof(max_in_row));
    memset(max_in_col, 0xFF, sizeof(max_in_col));

    for (int n = 0; n < N; ++n)
    {
        for (int m = 0; m < M; ++m)
        {
            rows[n].push(g[n][m]);
            cols[m].push(g[n][m]);

            if (g[n][m] > max_in_row[n])
                max_in_row[n] = g[n][m];
            if (g[n][m] > max_in_col[m])
                max_in_col[m] = g[n][m];
        }
    }

    memset(b, 0, sizeof(b));

    for (;;)
    {
        int min_row = -1;
        for (int n = 0; n < N; ++n)
        {
            if (!rows[n].empty() &&
                (min_row == -1 || rows[min_row].top() > rows[n].top()))
            {
                min_row = n;
            }
        }
        if (min_row == -1)
        {
            return true;
        }

        int minh = rows[min_row].top();
        bool found = false;
        for (int m = 0; m < M; ++m)
        {
            if (b[min_row][m] || g[min_row][m] != minh)
                continue;
            if (max_in_row[min_row] == minh)
            {
                found = true;
                b[min_row][m] = true;
                rows[min_row].pop();
            }
            if (max_in_col[m] == minh)
            {
                for (int n = 0; n < N; ++n)
                {
                    if (!b[n][m])
                    {
                        found = true;
                        b[n][m] = true;
                        cols[m].pop();
                        rows[n].pop();
                    }
                }
            }
        }
        if (!found)
        {
            return false;
        }
    }
}

void main()
{
    int T = 0;
    cin >> T;
    for (int t = 1; t <= T; ++t)
    {
        cin >> N >> M;
        for (int n = 0; n < N; ++n)
            for (int m = 0; m < M; ++m)
                cin >> g[n][m];

        cout << "Case #" << t << ": "
             << (check() ? "YES" : "NO") << endl;
    }
}
