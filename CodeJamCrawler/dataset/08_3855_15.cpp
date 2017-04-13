#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long LL;

#define FOR(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define REP(i,n) for(int i=0;i<(int)(n);++i)
#define SIZE(t) ((int)((t).size()))

ifstream cin("C-small-attempt0.in");
ofstream cout("C-small-attempt0.out");

int a[13][1050];

int oneBit(int n)
{
    int r = 0;
    REP(i, 10)
        if (n & (1 << i))
            ++r;
    return r;
}

bool isValid(int m, int n)
{
    REP(i, 10) REP (j, 10)
        if ((n & (1 << i)) && (m & (1 << j) && abs(i - j) == 1))
            return false;
    return true;
}


bool isValid(int mask, const string & s)
{
    REP(i, SIZE(s))
    {
        if ((1 << i) & mask && (s[i] == 'x'))
        {
            return false;
        }
        if (i > 0 && ((1 << i) & mask) && ((1 << (i-1)) & mask))
        {
            return false;
        }
    }
}

int main()
{

    int testNum = 0;
    cin >> testNum;
    for(int test = 1; test <= testNum; ++test)
    {
        int result = 0;
        int n, m;
        cin >> n >> m;
        memset(a, 0, sizeof(a));
        vector<string > vs;
        string s;
        REP(i, n) 
        {
            cin >> s;
            vs.push_back(s);
        }

        REP(i, n)
        {
            REP(k, 1 << m)
            {
                if (isValid(k, vs[i]))
                {
                    REP(l, 1 << m)
                    {
                        if (isValid(k, l))
                        {
                            int num = a[i][l] + oneBit(k);
                            if (num > a[i + 1][k])
                                a[i + 1][k] = num;
                        }
                    }
                }
            }
        }

        int maxNum = 0;
        REP (k, 1 << m)
            if (a[n][k] > maxNum)
                maxNum = a[n][k];


        cout << "Case #" << test <<": " << maxNum <<endl;
    }
    return 0;
}