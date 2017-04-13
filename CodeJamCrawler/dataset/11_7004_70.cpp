#include <iostream>
#include <fstream>

using namespace std;

int t, n, cn;

int main()
{
    ifstream fin("input.in");
    ofstream fout("output.txt");

    fin >> t;
    for (int tn = 0; tn < t; tn++) {
        fin >> n;
        int res = 0;
        int min = 2000000;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            fin >> cn;
            sum += cn;
            if (cn < min) {
                min = cn;
            }
            res ^= cn;
        }
        fout << "Case #" << (tn + 1) <<": ";
        if (0 != res) {
            fout << "NO" << endl;
        }
        else {
            fout << sum - min << endl;
        }
    }

    return 0;
}
