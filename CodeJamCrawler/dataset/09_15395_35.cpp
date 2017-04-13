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

ifstream fin ("2.in");
ofstream fout ("2.out");

int t;
int n;
string s;
char sa[22];
int length;

int main() {
    fin >> t;
    cout << t << endl;
    getline(fin, s);
    for(int ii = 0; ii < t; ii++) {
        getline(fin, s);
        cout << s << endl;
        length = s.length();
        sa[0] = '0';
        for(int i = 0; i < length; i++) {
            sa[i+1] = s[i];
        }
        int i;
        for(i = length-1; i>0; i--) {
            if(sa[i] < sa[i+1]) break;
        }
        char min = '9'+1;
        int mini;
        for(int i2 = i+1; i2 <= length; i2++)
            if(sa[i2] < min && sa[i2] > sa[i]) { 
                min = sa[i2];
                mini = i2;
            }
        char temp = sa[i];
        sa[i] = min;
        sa[mini] = temp;
        sort(sa+i+1, sa+length+1);
        fout << "Case #" << ii+1 << ": ";
        if(i == 0) {
            s = "";
            for(int i = 0; i <= length; i++) {
                s+=sa[i];
            }
            fout << s << endl;
        } else {
            for(int i = 0; i < length; i++) {
                s[i] = sa[i+1];
            }
            fout << s << endl;
        }
        cout << s << endl;
    }
    system("PAUSE");
    return 0;
}
