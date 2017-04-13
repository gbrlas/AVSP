#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

int main()
{
    ofstream fout ("out.txt");
    ifstream fin ("C-small-attempt3.in");
    int T, t = 1;
    fin >> T;
    while(T--)
    {
        long long R, K, N, tmp, ans = 0, i, j, n;
        queue<long long> q;
        fin >> R >> K >> N;
        for(i = 0; i < N; i++)
        {
            fin >> tmp;
            q.push(tmp);
        }
        i = R;
        while(i--)
        {
            for(j = q.front(), n = 0; j <= K && n < N; j += q.front(), n++)
            {
                tmp = q.front();
                q.pop();
                q.push(tmp);
            }
            j -= q.front();
            ans += j;
        }
                
        fout << "Case #" << t++ << ": " << ans << endl;
    }
    return 0;
}
