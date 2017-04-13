#include <iostream>
#include <vector>
#include <fstream>
#include <cstring>
#include <cmath>
using namespace std;

int perm3(int n)
{
    return n*(n-1)*(n-2)/6;
}

int main()
{
    ifstream fin("A.in");
    ofstream fout("A.out");
    int ncas;
    fin >> ncas;
    for(int cas = 0; cas < ncas; cas++)
    {
            double n, M ,A, B, C, D, x0, y0;
            fin >> n >> A >> B >> C>> D >> x0 >> y0 >> M;
            int mod3[3][3];
            for (int j = 0; j < 3; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    mod3[j][k] = 0;
                };
            };
            double x = x0;
            double y = y0;
            mod3[int(fmod(x,3))][int (fmod(y,3))] = 1;
            for (int j = 0; j < n-1; j++)
            {
                x = fmod((A * x + B), M);
                y = fmod((C * y + D), M);
                mod3[int(fmod(x,3))][int(fmod(y,3))] += 1;
            };
            int sum = 0;
           /* for (int j = 0; j < 3; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    fout << mod3[j][k] << endl;
                };
            };*/
            
            for (int j = 0; j < 3; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    sum += perm3(mod3[j][k]);
                };
            };
            
            sum += mod3[0][0]*mod3[1][1]*mod3[2][2];
            sum += mod3[0][0]*mod3[1][2]*mod3[2][1];
            sum += mod3[0][0]*mod3[1][0]*mod3[2][0];
            sum += mod3[0][1]*mod3[1][2]*mod3[2][0];
            sum += mod3[0][1]*mod3[1][1]*mod3[2][1];
            sum += mod3[0][1]*mod3[1][0]*mod3[2][2];
            sum += mod3[0][2]*mod3[1][2]*mod3[2][2];
            sum += mod3[0][2]*mod3[1][1]*mod3[2][0];
            sum += mod3[0][2]*mod3[1][0]*mod3[2][1];
            sum += mod3[0][2]*mod3[0][0]*mod3[0][1];
            sum += mod3[1][2]*mod3[1][0]*mod3[1][1];
            sum += mod3[2][2]*mod3[2][0]*mod3[2][1];
            
            fout << "Case #" << cas + 1 << ": " << sum <<endl;
    }
    return 0;
}
    
