#include <iostream>
#include <fstream>

using namespace std;

int mat[101][101];

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    if (fin.bad()) {
        cout << "Cannot open input file" << endl;
        return -1;
    }
    int t;
    fin >> t;
    for (int tcase = 0; tcase < t; tcase++) {
        int n, m;
        fin >> n >> m;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                fin >> mat[i][j];
            }
        }
        for (int i = 0; i < n; i++) {
            int maxh = 0;
            for (int j = 0; j < m; j++) {
                maxh = max(maxh, mat[i][j]);
            }
            mat[i][m] = maxh;
        }
        for (int i = 0; i < m; i++) {
            int maxh = 0;
            for (int j = 0; j < n; j++) {
                maxh = max(maxh, mat[j][i]);
            }
            mat[n][i] = maxh;
        }
        bool canbe = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if ((mat[i][j] < mat[i][m]) && (mat[i][j] < mat[n][j])) {
                    canbe = false;
                }
            }
        }
        fout << "Case #" << tcase + 1 << ": " << ((canbe)?"YES":"NO") << endl;
    }
    return 0;
}
