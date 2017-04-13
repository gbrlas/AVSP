#include <iostream>
#include <fstream>

using namespace std;


long long n;
int t, pd, pg;


int main()
{
    ifstream fin("input.in");
    ofstream fout("output.txt");

    fin >> t;

    for (int nc = 0; nc < t; nc++) {
        fin >> n >> pd >> pg;
        if (n > 1000) {
            n = 1000;
        }
        int pds = pd;
        int fp = 100;
        int aux;
        while (pd != 0) {
            fp %= pd;
            aux = fp;
            fp = pd;
            pd = aux;
        }
        if ((100 / fp) <= n) {
            if ((pds != 0) && (pg == 0)) {
                fout << "Case #" << (nc + 1) <<": Broken" << endl;
            }
            else if ((pds != 100) && (pg == 100)) {
                fout << "Case #" << (nc + 1) <<": Broken" << endl;
            }
            else {
                fout << "Case #" << (nc + 1) <<": Possible" << endl;
            }
        }
        else {
            fout << "Case #" << (nc + 1) <<": Broken" << endl;
        }
    }


    return 0;
}
