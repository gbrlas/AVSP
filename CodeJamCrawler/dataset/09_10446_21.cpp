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
    ifstream fin("D.in");
    FILE * fout;
      fout = fopen("D.out", "w");
    int C;
    fin >> C;
    for (int casenum = 1; casenum <= C; casenum++)
    {
        int N;
        double ans;
        fin >> N;
        int x[N], y[N], R[N];
        for (int i = 0; i < N; i++)
            fin >> x[i] >> y[i] >> R[i];

        if (N == 1)
           ans = R[0];
        else if (N == 2)
        {
             ans = max(R[0], R[1]);
        }
        else
        {
            ans = 1e8;
            int p[3];
            for (int i = 0; i < 3; i++)
                p[i] = i;
                        

            do
            {
                double d2;
                double d = sqrt((x[p[1]] - x[p[2]])*(x[p[1]] - x[p[2]]) + (y[p[1]] - y[p[2]])*(y[p[1]] - y[p[2]]));

                if (d + R[p[1]] <  R[p[2]])
                   d2 = R[p[2]];
                else if (d + R[p[2]] < R[p[1]])
                   d2 = R[p[1]];
                else
                    d2 = (d + R[p[1]] + R[p[2]])/2;

                d2 = max(d2, (double)R[p[0]]);
                ans = min(ans, d2);
                                                                
            } while (next_permutation(p, p + 3));
        }
        //fout << "Case #" << casenum << ": " << ans << endl; 
        
        fprintf(fout, "Case #%d: %.6f\n", casenum, ans);
    }
    return 0;   
}
