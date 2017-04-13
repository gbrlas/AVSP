#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
using namespace std;
int main () {
    int t;
    cin >> t;
    for (int caso = 1; caso <= t; ++caso) {
        cout<<"Case #"<<caso<<":"<<endl;
        int n;
        cin >> n;
        double wp [n];
        double owp[n];
        double oowp[n];
        char mat [n][n];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> mat[i][j];   
            }
        }
        for (int i = 0; i < n; ++i) {
            int cont = 0;
            int cont2 = 0;
            for (int j = 0; j < n;++j) {
                if (mat[i][j] == '1'){
                ++cont;   
                ++cont2;
                }
                else if (mat[i][j] == '0') {
                    ++cont2;   
                }
                
            }
            wp[i] = (long double)cont/(long double)cont2;   
        }
        int oponentes [n][n];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                oponentes[i][j] = 0;  
            }   
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if  (mat[i][j] != '.')
                oponentes[i][j] = 1;  
            }   
        }
        for (int k = 0; k < n; ++k) {
            int oponentesk = 0;
            long double acum = 0;
            for (int i = 0; i < n; ++i) {
            int cont = 0;
            int cont2 = 0;
            if (oponentes[k][i]) {
            oponentesk++;
            for (int j = 0; j < n;++j) {
                if (j != k){
                if (mat[i][j] == '1'){
                ++cont;   
                ++cont2;
                }
                else if (mat[i][j] == '0') {
                    ++cont2;   
                }}
            }
            acum += (long double)cont/(long double)cont2;   }
        }          
        owp[k] = acum/(long double)(oponentesk);   
        }
        for (int i = 0; i < n; ++i) {
            long double acum = 0;
            int oponentesi = 0;
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] != '.') {
                    oponentesi++;
                    acum += owp[j];   
                }
            }
            oowp[i] = acum/(long double)oponentesi;  
        }
        for (int i = 0; i <n; ++i) {
          cout<<(long double)0.25 * wp[i] + (long double)0.50 * owp[i] + (long double)0.25 * oowp[i]<<endl;
          }
    }
    return 0;
}
