#include<iostream>
#include<cmath>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
int main () {
    int t;
    cin >> t;
    for (int cases = 1; cases <= t; ++cases) {
        int res = 0;
        int n = 0;
        int posb = 1;
        int poso = 1;
        map < int ,  int > o;
        map < int , int > b;
        cin >> n;
        char a;
        int k;
        int i;
        for (i = 0; i < n; ++i) {
              cin >> a >> k;
              if (a == 'O') {
                    o[i] = k;   
                }
                else {
                    b[i] = k;   
                }
        }
        o[n+100] = 2;
        b[n+101] = 2;
        map < int ,  int >::iterator ito = o.begin();
        map < int ,  int >::iterator itb = b.begin();
        for (int i = 0; i < n; ++i) {
            if ((*ito).first < (*itb).first) {
                   while (poso < (*ito).second) {
                        if (posb < (*itb).second) {
                            posb++;   
                        }  
                        else if (posb > (*itb).second) {
                            posb--;   
                        }
                        ++poso;
                        ++res;
                    }
                    while (poso > (*ito).second) {
                        if (posb < (*itb).second) {
                            posb++;   
                        }  
                        else if (posb > (*itb).second) {
                            posb--;   
                        }
                        --poso;
                        ++res;
                    }
                    if (posb < (*itb).second) {
                            posb++;   
                        }  
                        else if (posb > (*itb).second) {
                            posb--;   
                        }
                    ++ito;
                    ++res;
                }
                else if ((*itb).first < (*ito).first) {
                   while (posb < (*itb).second) {
                        if (poso < (*ito).second) {
                            poso++;   
                        }  
                        else if (poso > (*ito).second) {
                            poso--;   
                        }
                        ++posb;
                        ++res;
                    }
                    while (posb > (*itb).second) {
                        if (poso < (*ito).second) {
                            poso++;   
                        }  
                        else if (poso > (*ito).second) {
                            poso--;   
                        }
                        --posb;
                        ++res;
                    }
                    if (poso < (*ito).second) {
                            poso++;   
                        }  
                        else if (poso > (*ito).second) {
                            poso--;   
                        }
                    ++itb;
                    ++res;
                }
                    
            }
            cout << "Case #"<<cases<<": "<<res << endl;
        }
    }
