/*
ID: nilsmolin2
PROG: baying
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

using namespace std;

ifstream fin ("baying.in");
ofstream fout ("baying.out");

int letters, dict, n;
string dictt[5000];

bool works(string s, string d) {
    int length = s.length();
    bool answer;
    for(int i = 0, j = 0; i < length; i++, j++) {
            bool t = false;
            if(s[i] == '(') {
                for(i++; s[i] != ')'; i++) {
                    if(s[i] == d[j]) t = true;
                }
            } else if(s[i] == d[j]) t = true;
            if(!t) return false;
        }
   // cout << d << " works on " << s << endl;
   // system("PAUSE");
    return true;
}

int main() {
    fin >> letters >> dict >> n;
    for(int i = 0; i < dict; i++) {
        fin >> dictt[i];
    }
    for(int i = 0; i < n; i++) {
        int count = 0;
        string temp;
        fin >> temp;
        for(int i = 0; i < dict; i++) {
            if(works(temp, dictt[i])) count++;
        }
        fout << "Case #" << i+1 << ": " << count << endl;
    }
    return 0;
}
