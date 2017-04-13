#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
    private:
        int status;
        int tid;
        int rec[5];//record for X, O, T, .
        vector<string> res;
        int board[5][5];
        bool hasempty;
    public:
        Solution(int ttid)
        {
            tid = ttid;
            status = 3;
            res.clear();
            hasempty = false;
            res.push_back("X won");
            res.push_back("O won");
            res.push_back("Draw");
            res.push_back("Game has not completed");
        }

        void input()
        {
            string tmp;
            for (int t = 0; t < 4; ++t)
            {
                cin>>tmp;
                for (int i = 0; i < tmp.length(); ++i)
                {
                    int ts = 0;
                    switch (tmp[i])
                    {
                        case 'X':
                            ts = 1;
                            break;
                        case 'O':
                            ts = 2;
                            break;
                        case 'T':
                            ts = 3;
                            break;
                        case '.':
                            ts = 4;
                            break;
                        default:
                            ts = 0;
                            break;
                    }
                    board[t][i] = ts;
                }
            }
        }

        void resetrec()
        {
            for (int i = 0; i < 5; ++i)
            {
                rec[i] = 0;
            }
        }

        bool checkstatus()
        {
            if (rec[1] + rec[3] == 4)
            {
                status = 0;
            }
            else if (rec[2] + rec[3] == 4)
            {
                status = 1;
            }
            else
            {
                status = 3;
            }
            if (rec[4] > 0)
            {
                hasempty = true;
            }

            if (status==0 || status==1)
                return true;

            return false;
        }

        void solve()
        {
            int r, c;
            //row index
            for (r = 0; r < 4; ++r)
            {
                resetrec();
                for (c = 0; c < 4; ++c)
                {
                    rec[ board[r][c] ]++;
                }
                if (checkstatus())
                {
                    return;
                }
            }

            //col index
            for (c = 0; c < 4; ++c)
            {
                resetrec();
                for (r = 0; r < 4; ++r)
                {
                    rec[ board[r][c] ]++;
                }
                if (checkstatus())
                {
                    return;
                }
            }

            //left diagonal
            resetrec();
            for (c = 0; c < 4; ++c)
            {
                rec[ board[c][c] ]++;
            }
            if (checkstatus())
            {
                return;
            }
            //right diagonal
            resetrec();
            for (c = 0; c < 4; ++c)
            {
                rec[ board[c][3-c] ]++;
            }
            if (checkstatus())
            {
                return;
            }
        }

        string getres()
        {
            if (status==0 || status==1)
            {
                return res[status];
            }
            else if (hasempty == true)
            {
                return res[3];
            }
            else
            {
                return res[2];
            }
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

