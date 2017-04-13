#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;
void solve () {
    double c,f,x;
    cin>>c>>f>>x;
    double best = 1e100;
    for (int buys = 0; buys <= 100000; ++buys){
        double cost = 0;
        double prod = 2;
        for (int i = 0; i < buys; ++i){
            cost += c/prod;
            prod += f;
        }
        cost += x/prod;
        if (cost < best){
            best = cost;
        }
        else {
            break;
        }
    }
    printf("%.10lf\n",best);
}

int main () {
    int t;
    cin>>t;
    for (int cas = 1; cas <= t; ++cas){
        cout<<"Case #"<<cas<<": ";
        solve();
    }
}