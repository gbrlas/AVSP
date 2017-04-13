/* 
 * File:   main.cpp
 * Author: nraprolu
 *
 * Created on May 21, 2011, 6:37 AM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 */
int gcd(int u, int v) {
    if (u == v || u == 0 || v == 0)
        return u | v;
    if (u % 2 == 0) { // if u is even
        if (v % 2 == 0) // if u and v are even
            return (2 * gcd(u / 2, v / 2));
        else // u is even and v is odd
            return gcd(u / 2, v);
    } else if (v % 2 == 0) // if u is odd and v is even
        return gcd(u, v / 2);
    else { // both are odd
        if (u >= v)
            return gcd((u - v) / 2, v);
        else
            return gcd((v - u) / 2, u);
    }
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

bool valid(int a, int N) {
    if (lcm((100 / gcd(a, 100)), (100 / gcd(100 - a, 100))) <= N) {
        return true;
    }
    return false;
}

int main(int argc, char** argv) {
    int T;
    long long N;
    int pg, pd;
    int i = 0;
    cin >> T;
    while (T--) {
        i++;
        cin >> N >> pd >> pg;
        bool ans = false;
        if (pg == 100) {
            if (pd == 100) {
                ans = true;
            }


        }else if(pg==0){
            if(pd==0){
                ans=true;
            }
        }
        else if (valid(pd, N)) {


            ans = true;

        }
        cout << "Case #" << i << ": ";
        if (ans) {
            cout << "Possible" << endl;
        } else {
            cout << "Broken" << endl;
        }
    }
    return 0;
}

