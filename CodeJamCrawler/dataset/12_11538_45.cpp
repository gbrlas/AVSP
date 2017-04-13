#include <sstream>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

ifstream in;
ofstream out;

int scores[100];

void solve() 
{
    int N, S, t;
    in >> N >> S >> t;

    for(int i=0; i<N; ++i)
        in >> scores[i];

    int total = 0;

    for(int i=0; i<N; ++i)
    {
        int normmax = (scores[i] + 2) / 3;

        //cout << scores[i] << " : " << normmax << endl;
        
        if(normmax >= t)
        {
            total++;
            //cout << "PASS" << endl;
            continue;
        }

        if(normmax + 1 < t)
            continue;

        if(t < 2)
            continue;

        if(scores[i] % 3 == 1)
            continue;

        if(S == 0)
            continue;

        //cout << "PASS 2" << endl;
        S--, total++;
    }

    out << total;

}

int main(int argc, char* argv[])
{
    string of = argv[1];
    of = of.substr(0, of.find('.')) + ".out";

    in.open(argv[1]);
    out.open(of);

    int T; in >> T;
    in.get();
    for(int i=1; i<=T; ++i)
    {
        out << "Case #" << i << ": ";
        solve();
        out << endl;
    }

    out.close();
    in.close();
    system("pause");
}