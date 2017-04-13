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
#include <set>

#include <cassert>
#include <cmath>
#include <string>
#include <iomanip>
#include <algorithm>
#include <utility>

#define rep(i,n) for(int i=0;i<n;i++)
#define irep(it,cls) for(typeof((cls).begin()) it=(cls).begin();it!=(cls).end();it++)
#define gprint(i) cout<<"Case #"<<i<<": ";
using namespace std;

/*
 * 
 */


char c[70][3];
char d[70][2];
int cz, dz, oz;
string p;
char out[100];

bool dest(char a, char b) {

    rep(i, dz) {
        if ((d[i][0] == a && d[i][1] == b) || (d[i][0] == b && d[i][1] == a)) {
            return true;
        }
    }
    return false;
}

void dest(char a) {

    rep(i, oz) {
        if (dest(out[i], a)) {
            oz = 0;
            return;
        }
    }
}

char comb(char a, char b) {

    rep(i, cz) {
        if ((c[i][0] == a && c[i][1] == b) || (c[i][0] == b && c[i][1] == a)) {
            return c[i][2];
        }
    }
    return 'f';
}

void process() {
    //cout<<p<<endl;
    rep(i, p.size()) {
        if (oz > 0) {
            char ca, cb;
            ca = out[oz - 1];
            cb = p[i];
           if(comb(ca, cb) != 'f' && oz != 0) {
                oz--;
                //cout<<"comb " <<ca <<" "<<cb<<"=";
                cb = comb(ca, cb);
                
            }
            out[oz] = cb;
            //cout<<"out["<<oz<<"]="<<cb<<endl;
            oz++;
            dest(cb);


        } else {
            out[oz] = p[i];
            //cout<<"out["<<oz<<"]="<<p[i]<<endl;
            oz++;
        }
    }

    cout << "[";

    rep(i, oz) {
        if (i != 0) {
            cout << ", ";
        }
        cout << out[i];
    }
    cout << "]"<<endl;

}

int main() {
    int T;
    cin >> T;
    int ccz,ddz,r;
    string s;
    int pcount = 0;
    while (T--) {
        cin >> cz;
        
        rep (i,cz) {
            cin >> s;
            //cout<<s<<endl;
            c[i][0] = s[0];
            c[i][1] = s[1];
            c[i][2] = s[2];
            
        }
        cin>>dz;
        oz = 0;
        rep(i,dz) {
            cin >> s;
            d[i][0] = s[0];
            d[i][1] = s[1];
            
        }
        cin>>r;
        cin >> p;
        pcount++;
        gprint(pcount);
        process();
    }

}