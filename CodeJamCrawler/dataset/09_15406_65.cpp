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

using namespace std;

ifstream fin ("3.in");
ofstream fout ("3.out");

int t;
int base;
string s;
string ans;
int c[256];
bool used[256];

int main() {
    fin >> t;
    for(int i = 0; i < t; i++) {
        fin >> s;
        for(int i = 0; i < 256; i++) used[i] = 0;
        base = 1;
        c[s[0]] = '1';
        used[s[0]] = 1;
        int counter = 0;
        ans = "1";
        for(int i = 1; i < s.length(); i++) {
            if(!used[s[i]]) {
                used[s[i]] = 1;
                base++;
                c[s[i]] = counter + '0';
                counter++;
                if(counter == 1) counter = 2;
            }
            ans += c[s[i]];
        }
        if(base == 1) { cout << "Fixed " << endl; base++; }
        long long answer = 0;
        for(int i = 0; i < ans.length(); i++) {
            answer = answer*base+ans[i]-'0';
        }
       fout << "Case #" << i + 1 << ": " << answer << endl;
    }
    system("PAUSE");
    return 0;
}
