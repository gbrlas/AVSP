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

int ps[] = {0, 1, 10, 1e2, 1e3, 1e4, 1e5, 1e6, 1e7};

int num_digits(int n)
{
    int k=0;
    while(n!=0)
    {
        n/=10;
        k++;
    }
    return k;
}

int rotate(int n, int k)
{
    int d = n%10;
    return ps[k] * d + n/10;
}

void solve() 
{
    int A, B;
    in >> A >> B;

    int k = num_digits(B);
    int total = 0;

    for(int i=A; i<=B; ++i)
    {
        
        int rot = i;
        for(int r=0; r<k; ++r)
        {
            rot = rotate(rot, k);
            
            if(rot > i && rot <= B)
            {
                ++total;
              //  cout << " I : " << i;
              //  cout << " H:" << rot << endl;
            }
        }
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

