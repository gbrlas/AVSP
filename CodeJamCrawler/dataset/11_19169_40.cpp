#include <cstdlib>
#include <iostream>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <stack>
#include <set>
#include <cstring>
#include <cassert>
#include <cmath>
#include <string>
#include <iomanip>
#include <algorithm>
#include <utility>
#include <fstream>
#include <climits>

#define rep(i,n) for(long long i=0;i<n;i++)
#define rrep(i,low,high) for(long long i=low;i<=high;i++)
#define irep(it,cls) for(typeof((cls).begin()) it=(cls).begin();it!=(cls).end();it++)
#define gprint(i) fout<<"Case #"<<i<<": ";
#define init(T) long long T;fin>>T; rep(pcount,T) 
#define min(a,b) (a<b)?a:b
#define max(a,b) (a>b)?a:b 
using namespace std;


ifstream fin;
ofstream fout;

long long l, t, n, c;
long long * p;

long long computeSave(long long regyet, long long bpos) {
    long long ttoj = ((bpos / c) * p[c] + p[bpos % c])*2 - regyet;
    long long ttoj1 = (((bpos + 1 )/ c) * p[c] + p[(bpos + 1) % c])*2 - regyet;

    long long reg;
    if (t < ttoj) {
        reg = (ttoj1 - ttoj) / 2;
    } else if (t < ttoj1) {
        reg = (ttoj1 - t) / 2;
    } else {
        reg = 0;
    }
    return reg + regyet;
}

int main(int argc, char** argv) {

    fin.open("in.txt", ifstream::in);
    fout.open("out.txt");

    init(T) {
        gprint(pcount + 1);
        fin >> l >> t >> n >> c;
        p = new long long[c + 1];
        long long sum = 0;
        long long temp;
        p[0] = 0;

        rrep(i, 1, c) {
            fin >> temp;
            sum += temp;
            p[i] = sum;

        }
        long long ans = 0;
        long long tton = ((n / c) * p[c] + p[n % c])*2 ;
        if (l == 2) {

            rep(i, n) {

                rep(j, i) {
                    //time to j
                    long long jsave = computeSave(0, j);
                    ans = max(ans, computeSave(jsave, i));
                }
            }
        }
        if (l == 1) {

            rep(i, n) {

                
                    ans = max(ans, computeSave(0, i));
                
            }
        }
        delete[] p;
        
        fout << tton-ans << endl;

    }




    fin.close();
    fout.close();
    return 0;
}
