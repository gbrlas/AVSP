#include <iostream>
using namespace std;
int main() {
    int T, N;
    cin >> T;
    for(int i = 0; i < T; i++) {
        cin >> N;
        char tab[N][N];
        double WP[N];
        double OWP[N];
        double OOWP[N];
        char c;
        double all = 0, w = 0;

        // WP
        for(int j = 0; j < N; j++) {
            all = w = 0;
            for(int k = 0; k < N; k++) {
                cin >> c;
                tab[j][k] = c;
                switch(c) {
                case '.':
                    break;
                case '0':
                    all++;
                    break;
                case '1':
                    all++, w++;
                    break;
                }
            }
            WP[j] = w / all;
        }

        // OWP
        for(int j = 0; j < N; j++) {
            double temp1 = 0;
            double countOfOpponents = 0;
            for(int k = 0; k < N; k++) {
                if(tab[j][k] != '.') {
                    countOfOpponents++;
                    double a = 0, ww = 0;
                    for(int l = 0; l < N; l++) {
                        if(tab[k][l] == '0' && l != j) a++;
                        if(tab[k][l] == '1' && l != j) a++, ww++;
                    }
                    temp1 += (ww / a);
                }
            }
            OWP[j] = temp1 / countOfOpponents;
        }

        // OOWP
        for(int j = 0; j < N; j++) {
            double temp2 = 0;
            double cOO = 0;
            for(int k = 0; k < N; k++) {
                if(tab[j][k] != '.') {
                    temp2 += OWP[k];
                    cOO++;
                }
            }
            OOWP[j] = temp2 / cOO;
        }

        cout << "Case #" << (i + 1) << ":" << endl;
        for(int j = 0; j < N; j++) {
            cout << (WP[j] / 4) + (OWP[j] / 2) + (OOWP[j] / 4) << endl;
        }
    }
    return 0;
}
