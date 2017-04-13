#include <iostream>
#include <fstream>

using namespace std;

int t;
int n;
char mat[40][40];
int val[40];

int main()
{
    ifstream fin("rows.in");
    ofstream fout("rows.out");

    fin>>t;
    for (int ncase=0; ncase<t; ncase++) {
        fin>>n;
        for (int i=0; i<n; i++) {
            val[i] = -1;
            for (int j=0; j<n; j++) {
                fin>>mat[i][j];
                if (mat[i][j] == '1')
                    val[i] = j;
            }
            fin>>ws;
        }
        int answ = 0;
        for (int i=0;i<n;i++) {
            if (val[i]>i) {
                int tch = -1;
                for (int j=i+1; j<n; j++) {
                    if (val[j] <= i) {
                        tch = j;
                        break;
                    }
                }
                for (int j= tch; j>i; j--) {
                    int aux = val[j];
                    val[j] = val[j-1];
                    val[j-1] = aux;
                    answ++;
                }
            }
        }
        fout<<"Case #"<<ncase+1<<": "<<answ<<endl;
    }
    fin.close();
    fout.close();
}
