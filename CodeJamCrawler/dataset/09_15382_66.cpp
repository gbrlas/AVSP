/*
ID: nilsmolin2
PROG: baying2
LANG: C++
*/
#include <iomanip>
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

using namespace std;

ifstream fin ("baying2.in");
ofstream fout ("baying2.out");

int n;

string msg = "welcome to code jam";
int a[19];

int proc(string s) {
    int length = s.length();
    for(int j = 0; j < 19; j++) a[j] = 0;
    for(int i = 0; i < length; i++)
        for(int j = 0; j < 19; j++)
            if(s[i] == msg[j]) {
                if(j == 0) a[j]++;
                else a[j] += a[j-1];
                a[j] = a[j] % 10000;
            }
    return a[18];
}

int main() {
    fin >> n;
    string s;
    getline(fin, s);
    for(int i = 0; i < n; i++) {
        getline(fin, s);
        fout << "Case #" << i+1 << ": "
            << setfill('0') << setw(4) << proc(s) << endl;
    }
    return 0;
}
