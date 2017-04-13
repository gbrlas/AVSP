/*
ID: nilsmolin2
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <math.h>
#include <bitset>
#include <queue>
#include <set>

#define inf 99999
#define max 20000000
#define maxb 10

using namespace std;

ifstream fin ("1.in");
ofstream fout ("1.out");

int t;
int n;
string start;
set<string> a;

void print(string s) {
    for(int i = 0; i < n; i++) {
        cout << (int) s[i] << endl;
    }
}

string cur;
int moves;
int stop;
char temp;

bool recur(int moves) {
    if(moves == stop || a.count(cur + (char) moves) > 0) return false;
    a.insert(cur + (char) moves);
  //  print(cur); system("PAUSE");
    bool good = true;
    for(int i = 0; i < n-1; i++) {
        if(cur[i] > i) good = false;
        if(cur[i] > cur[i+1]) {
            temp = cur[i];
            cur[i] = cur[i+1];
            cur[i+1] = temp;
            if(recur(moves+1)) return true;
            temp = cur[i];
            cur[i] = cur[i+1];
            cur[i+1] = temp;
        }
    }
   /*if(good) {
        cout << "FOUND IT IN " << moves << " MOVES" << endl;
        system("PAUSE");
    }*/
    return good;
}

int main() {
    fin >> t;
    for(int i = 0; i < t; i++) {
        fin >> n;
        start = "";
        for(int i = 0; i < n; i++) {
            string s;
            fin >> s;
            char last1 = 0;
            for(int j = 0; j < n; j++)
                if(s[j]=='1') last1 = j;
            start += last1;
            print(start);
        }
        for(stop = 1; ;stop++) {
         //   cout << "STARTING " << stop << endl;
            a.clear();
            cur = start;
            if(recur(0)) break;
        }
        fout << "Case #" << i+1 << ": " << stop-1 << endl;
    }
    system("PAUSE");
    return 0;
}
