#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<complex>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<cctype>
using namespace std;



int main()
{
    ifstream fin("A.in");
    ofstream fout("A.out");
    int N;
    int numx[9];
    long long n, A, B, C, D, x0, y0, M, X, Y, ans;
    fin >> N;
    
    for (int casenum = 1; casenum <= N; casenum++)
    {
        for (int j = 0; j < 9; j++)
        {
            numx[j] = 0;
        }
        fout << "Case #" << casenum << ": ";
        fin >> n >> A >> B >> C >> D >> x0 >> y0 >> M;
        X = x0;
        Y = y0;
        numx[3*(X%3)+ Y%3]++;
        //numy[Y%3]++;
        for (int i = 1; i < n; i++)
        {
            X = (A*X + B) % M;
            Y = (C*Y + D) % M;
            //cout << X << ' ' << Y << endl;
            numx[3*(X%3)+ Y%3]++;
            //numx[X%3]++;
            //numy[Y%3]++;
        }
        //cout << endl;
        ans = 0;
        for (int k = 0; k < 9; k++)
        {
            if (numx[k] >= 3)
                ans += numx[k]*(numx[k]-1)*(numx[k]-2)/6;
        }

        for (int i = 0; i < 3; i++)
        {
            ans += numx[i*3]*numx[i*3+1]*numx[i*3+2];
            ans += numx[i]*numx[i+3]*numx[i+6];
        }
        //fout << ans << endl;
        ans += numx[0]*numx[4]*numx[8];
        ans += numx[0]*numx[5]*numx[7];
        ans += numx[1]*numx[3]*numx[8];
        ans += numx[1]*numx[5]*numx[6];
        ans += numx[2]*numx[3]*numx[7];
        ans += numx[2]*numx[4]*numx[6];
        fout << ans << endl;
    }
}
