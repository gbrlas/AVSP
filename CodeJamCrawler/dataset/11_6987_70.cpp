#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int t,n;
char r;
int b;

int main()
{
    ifstream fin("input.in");
    ofstream fout("output.txt");

    fin >> t;

    for (int cn = 0; cn < t; cn++) {
        fin >> n;
        int tm = 0, om = 0, bm = 0, op = 1, bp = 1;

        for (int i = 0; i < n; i++) {
            fin >> r;
            fin >> b;
            if (r == 'O') {
                int mu = abs(b - op);
                mu = max(0, mu - om);
                tm += 1 + mu;
                bm += 1 + mu;
                om = 0;
                op = b;
                cout << i << " " << mu << endl;
            }
            if (r == 'B') {
                int mu = abs(b - bp);
                mu = max(0, mu - bm);
                tm += 1 + mu;
                om += 1 + mu;
                bm = 0;
                bp = b;
                cout << i << " " << mu << endl;
            }
        }
        fout << "Case #" << (cn + 1) << ": " << tm << endl;
    }

    return 0;
}
