#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
double eps = 1e-8;

double done(double now, double rate, double target) {
    return (target - now) / rate;
}

int main() {
    
    ifstream cin("testB.in");
    ofstream cout("testB.out");

    int t; cin >> t;

    for(int t_case = 1; t_case <= t; ++t_case) {
        cout << "Case #" << t_case << ": ";

        double C, F, X; cin >> C >> F >> X;
        double r = 2;
        
        cout.precision(10);
        
        double ans = 0;

        while(1) {
            if(done(0, r, C) + done(0, r + F, X) < done(0, r, X)) {
                ans += done(0, r, C);
                r += F;
            } else { 
                ans += done(0, r, X);
                cout << ans << "\n";
                break;
            }
        }
    }
}
