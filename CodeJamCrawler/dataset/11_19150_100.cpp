/* 
 * File:   main.cpp
 * Author: nraprolu
 *
 * Created on May 4, 2011, 9:45 AM
 */

#include <cstdlib>
#include <iostream>

//stl containers
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <stack>

#include <cassert>
#include <cmath>
#include <string>
#include <iomanip>
#include <algorithm>

#define rep(i,n) for(int i=0;i<n;i++)
#define irep(it,cls) for(typeof((cls).begin()) it=(cls).begin();it!=(cls).end();it++)
#define gprint(i) cout<<"Case #"<<i<<": ";
using namespace std;

/*
 * 
 */

int O[100];
int B[100];
char S[100];
int os, bs, n;

int process() {
    int ot, bt, t, op, bp, oc, bc;
    ot = 0;
    bt = 0;
    t = 0;
    op = 1;
    bp = 1;
    oc = 0;
    bc = 0;

    rep(i, n) {
        if (S[i] == 'O') {
            if (O[oc] > op) {
                t = max(t + 1, ot + (O[oc] - op) + 1);
            } else {
                t = max(t + 1, ot + (op - O[oc]) + 1);
            }
            ot = t;
            op = O[oc];
            oc++;
        }
        if (S[i] == 'B') {
            if (B[bc] > bp) {
                t = max(t + 1, bt + B[bc] - bp + 1);
            }
            else{
                t = max(t + 1, bt + bp - B[bc] + 1);
            }
            bt = t;
            bp = B[bc];
            bc++;
        }
    }
    cout << t << endl;
}

int main() {
    int T, p;
    char c;
    cin >> T;
    int pcount = 0;
    while (T--) {
        pcount++;
        cin >> n;
        os = 0;
        bs = 0;

        rep(i, n) {
            cin >> c >> p;
            S[i] = c;
            if (c == 'O') {
                O[os] = p;
                os++;
            } else {
                B[bs] = p;
                bs++;
            }
        }
        gprint(pcount);
        process();
    }
}