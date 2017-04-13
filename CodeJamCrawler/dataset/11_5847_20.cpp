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
    for (int caso = 1; caso <= t; caso++) {
        int r,c;
        cin >> r >> c;
        string rs [r];
        for (int i = 0; i < r; ++i) {
            cin >> rs[i];   
        }  
        bool test = true;
        for (int i = 0; i+1 < r && test; ++i) {
            for (int j = 0; j < c && test; ++j) {
                   if (rs[i][j] == '#') {
                        rs[i][j] = 47;
                        if (rs[i+1][j] == '#') {
                            rs[i+1][j] = 92;   
                        }   
                        else {
                            test = false;   
                        }
                        if (rs[i][j+1] == '#') {
                            rs[i][j+1] = 92;   
                        }
                        else {
                            test = false;   
                        }
                        if (rs[i+1][j+1] == '#') {
                            rs[i+1][j+1] = 47;   
                        }
                        else {
                            test = false;   
                        }
                    }
            }   
        }
        for (int i = 0; i < c; ++i) {
            if (rs[r-1][i] == '#') {
                test = false;   
            }   
        }
        if (!test) {
               cout << "Case #"<<caso<<":"<<endl<<"Impossible"<<endl;
        }
        else {
             cout<<"Case #"<<caso<<":"<<endl;
            for (int i = 0; i < r; ++i) {
                cout << rs[i]<<endl;   
            }   
        }
    } 
    return 0;
}
