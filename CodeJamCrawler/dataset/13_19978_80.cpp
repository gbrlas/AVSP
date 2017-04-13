#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

class Solution
{
    private:
        int board[105][105];
        int recC[105];
        int recR[105];
        int n, m;
        int tid;
        int status;
        string res[2];
    public:
        Solution(int ttid)
        {
            tid = ttid;
            res[0] = "YES";
            res[1] = "NO";
        }

        void input()
        {
            cin>>n>>m;
            for (int r = 0; r < n; ++r)
            {
                recR[r] = -1;
            }
            for (int c = 0; c < m; ++c)
            {
                recC[c] = -1;
            }

            for (int r = 0; r < n; ++r)
            {
                for (int c = 0; c < m; ++c)
                {
                    cin>>board[r][c];
                    if (board[r][c] > recR[r])
                    {
                        recR[r] = board[r][c];
                    }
                    if (board[r][c] > recC[c])
                    {
                        recC[c] = board[r][c];
                    }
                }
            }
        }
        
        void solve()
        {
            for (int r = 0; r < n; ++r)
            {
                for (int c = 0; c < m; ++c)
                {
                    if (board[r][c]!=recR[r] && board[r][c]!=recC[c])
                    {
                        status = 1;
                        return;
                    }
                }
            }

            status = 0;
        }

        string getres()
        {
            return res[status];
        }

        void output()
        {
            cout<<"Case #"<<tid<<": "<<getres()<<endl;
        }
};

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int T;
    Solution *sl;
    cin>>T;
    for (int tid = 1; tid <= T; ++tid)
    {
        sl = new Solution(tid); 
        sl->input();
        sl->solve();
        sl->output();
    }

    return 0;
}

