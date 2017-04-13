#include<iostream>
#include<fstream>
#include<vector>
#include<queue>
#include<cmath>
#include<string>
#include<algorithm>
#include<sstream>
using namespace std;

int main()
{
    ifstream fin("A.in");
    ofstream fout("A.out");
    int T;
    fin >> T;
    for (int casenum = 1; casenum <= T; casenum++)
    {
        int N;
        fin >> N;
        char grid[N][N];
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                fin >> grid[i][j];
        vector<int> last;
        int ans = 0, la;
        for (int i = 0; i < N; i++)
        {
            la = 0;
            for (int j = N-1; j >= 0; j--)
            {
                if (grid[i][j] == '1')
                {
                    la = j;
                    break;
                }
            }
            last.push_back(la);
        }

        for (int i = 0; i < N - 1; i++)
        {
            int j = 0;
            while (last[j] > i)
                j++;
            last.erase(last.begin() + j);
            ans += j;
        }
        fout << "Case #" << casenum << ": " << ans << endl; 
    }
    return 0;   
}
