#include<iostream>
#include<vector>
using namespace std;


bool lawnable(int lawn[100][100], int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            //la seva fila o columna tenen tots els numeros menors o iguals a ell 
            bool foundGreater = false;
            for (int k = 0; k < n; ++k) {
                if (lawn[k][j] > lawn[i][j]) {
                    foundGreater = true;
                    break;
                }
            }
            if (foundGreater) {
                for (int l = 0; l < m; ++l) {
                    if (lawn[i][l] > lawn[i][j]) return false;
                }
            }
        }
    }   
 
       return true;
}


int main()
{
    int n, m;
    int num;

    int lawn[100][100];
    cin >> num;
    for (int numCase = 1; numCase <= num; ++numCase) {
        cin >> n >> m;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> lawn[i][j];
            }
        }
        
        cout << "Case #" << numCase << ": " << (lawnable(lawn, n, m) ? "YES":"NO")<< endl;
    }
}
