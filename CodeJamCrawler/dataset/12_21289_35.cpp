#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
 
using namespace std;

ifstream fin("B-large.in");
ofstream fout("B-large.out");

bool gpAndSup[31];
bool gpAndNotSup[31];
bool lpAndSup[31];
bool lpAndNotSup[31];

void setup(int p) {
    for(int tp = 0; tp <=30; tp++) {
        gpAndSup[tp] = false;
        gpAndNotSup[tp] = false;
        lpAndSup[tp] = false;
        lpAndNotSup[tp] = false;
        for (int i = 0; i <= 10; i++)
            for (int j = i; j <= i+2; j++)
                for (int k = j; k <= i+2; k++) {
                    if (i+j+k == tp) {
                        int best = max(max(i, j), k);
                        bool sup = (abs(i-k) == 2)? true : false;
                        if (best>=p && sup) gpAndSup[tp] = true;
                        if (best>=p && !sup) gpAndNotSup[tp] = true;
                        if (best < p && sup) lpAndSup[tp] = true;
                        if (best < p && !sup) lpAndNotSup[tp] = true;
                    }
                 }
    }
}
                        

void solve(int cn, int S, int p, vector<int> totalPoints) {
    setup(p);

    int N = totalPoints.size();
    int ans = 0, sup = 0, extraSup = 0;
    for (int i=0 ; i < N; i++) {
        int tp = totalPoints[i];
        if (gpAndNotSup[tp] || gpAndSup[tp]) ans++;
        if (gpAndNotSup[tp] && gpAndSup[tp]) extraSup++;
        if (!gpAndNotSup[tp] && gpAndSup[tp]) sup++;
        if (lpAndSup[tp] && !gpAndNotSup[tp] && !gpAndSup[tp]) extraSup++;
    }
    if (sup > S) ans -= sup - S;
    else if (sup + extraSup < S) ans = 0;
        
    fout << "Case #" << cn << ": " << ans << endl;
}

int main() {

    int CASES;
    fin >> CASES;
    string dummieLine;
    getline(fin, dummieLine);    // New line.
    for (int i=1; i<=CASES; i++) {
        string line; 
        getline(fin, line);
        stringstream ss(line);
        int N; int S; int p;
        ss >> N;
        ss >> S;
        ss >> p; 
        //cout << "N, S, p " << N << " " << S << " " << p << endl;
        vector<int> totalPoints;
        int tp;
        while(ss >> tp) {
            totalPoints.push_back(tp);
            //cout << " " << tp << " ";
        }

        solve(i, S, p, totalPoints);
    }
    return 0;
}

