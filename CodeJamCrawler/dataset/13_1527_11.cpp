#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>

using namespace std;

const double eps = 1e-9;

int main() {
    int t;
    cin>>t;
    for (int tt = 1; tt <= t; ++tt) {
        double r, a;
        cin>>r>>a;
        int ct = 0;
        while (true) {
            double am = ((r + 1) * (r + 1) - r * r);
            if (am > a) {
                break;
            }
            a -= am;
            r += 2;
            ++ct;
        }
        cout<<"Case #"<<tt<<": "<<ct<<endl;
    }
    return 0;
}

