#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int t;
    fin >> t;
    int r1, r2;
    int c1[4][4];
    int c2[4][4];
    if (! fin.good()) {
        cout << " problem with input file" << endl;
        return -1;
    }
    for (int ncase = 0; ncase < t; ncase++) {
        fin >> r1;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                fin >> c1[i][j];
            }
        }
        fin >> r2;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                fin >> c2[i][j];
            }
        }
        int p = 0;
        int r = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (c1[r1-1][i] == c2[r2-1][j]) {
                    p++;
                    r = c1[r1-1][i];
                }
            }
        }
        fout << "Case #" << ncase + 1 << ": ";
        if (p == 0) {
            fout << "Volunteer cheated!" << endl;
        }
        else if (p == 1) {
            fout << r << endl;
        }
        else if (p > 1) {
            fout << "Bad magician!" << endl;
        }
    }
    fin.close();
    fout.close();
    return 0;
}
