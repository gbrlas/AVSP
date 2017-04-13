#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

ifstream fin("date.in");
ofstream fout("date.out");
vector<double> b, f;
int main()
{
    int T, k, i, j, N;
    double pf, x;
   fin >> T;
   for(k = 1; k <= T; k++)
    {
        fin >> N;
        for(i = 1; i <= N; i++)
        {
           fin >> x;
           f.push_back(x);
        }
        for(i = 1; i <= N; i++)
        {
           fin >> x;
           b.push_back(x);
        }
        sort(f.begin(), f.end());
        sort(b.begin(), b.end());
        pf = 0;
        j = N - 1;
        for(i = N-1;i >= 0; i--)
            if(f[j] > b[i]){pf++; j--;}
        fout<<"Case #"<<k<<": "<<pf<<" ";
        pf = 0;
        j = N - 1;
        for(i = N -1; i >= 0; i--)
            if(b[j] < f[i]) pf++;
                else j--;
        fout<<pf<<"\n";
        f.clear();
        b.clear();
    }
    return 0;
}
