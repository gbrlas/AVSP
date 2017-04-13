#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

class Solution
{
    private:
        int tid;
        int a, b;
        int ans;
    public:
        Solution(int ttid)
        {
            ans = 0;
            tid = ttid;
        }

        void input()
        {
            cin>>a>>b;
        }

        bool isp(int k)
        {
            int tmp;
            vector<int> rec;
            rec.clear();
            while (k > 0)
            {
                tmp = k % 10;
                k = k / 10;
                rec.push_back(tmp);
            }

            int s = rec.size();
            for (int i = 0; i < s/2; ++i)
            {
                if (rec[i] != rec[s-1-i])
                {
                    return false;
                }
            }

            return true;
        }

        void solve()
        {
            for (int i = a; i <= b; ++i)
            {
                if (!isp(i))
                {
                    continue;
                }
                int t = sqrt(i);
                if (t*t != i)
                {
                    continue;
                }
                if (!isp(t))
                {
                    continue;
                }

                ++ans;
            }
        }

        void output()
        {
            cout<<"Case #"<<tid<<": "<<ans<<endl;
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

