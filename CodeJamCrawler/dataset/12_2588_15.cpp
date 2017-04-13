#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <fstream>
#include <map>
#include <set>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

#define INF (1<<29)
#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)

using namespace std;

vector<int> get(string s)
{
    vector<int> vi;
    string a = "";
    for(int i = 0; i < (int)s.length(); ++i)
    {
        if(s[i] == ' ')
        {
            vi.push_back(atoi(a.c_str()));
            a = "";
            continue;
        }
        a += s[i];
    }
    vi.push_back(atoi(a.c_str()));
    return vi;
}

string G;

char mp['z' + 10];


int main (int argc, char const *argv[])
{
    mp['a'] = 'y';
    mp['b'] = 'h';
    mp['c'] = 'e';
    mp['d'] = 's';
    mp['e'] = 'o';
    mp['f'] = 'c';
    mp['g'] = 'v';
    mp['h'] = 'x';
    mp['i'] = 'd';
    mp['j'] = 'u';
    mp['k'] = 'i';
    mp['l'] = 'g';
    mp['m'] = 'l';
    mp['n'] = 'b';
    mp['o'] = 'k';
    mp['p'] = 'r';
    mp['q'] = 'z';
    mp['r'] = 't';
    mp['s'] = 'n';
    mp['t'] = 'w';
    mp['u'] = 'j';
    mp['v'] = 'p';
    mp['w'] = 'f';
    mp['x'] = 'm';
    mp['y'] = 'a';
    mp['z'] = 'q';
    
    ifstream in("A-small-attempt0.in");
    ofstream out("A-small-solution.out");
    string cases;
    getline(in,cases);
    int case_num = atoi(cases.c_str());
    int Case = 1;
    while(Case <= case_num)
    {
        getline(in,G);
        for(int i = 0; i < G.length(); ++i)
        {
            if(G[i] != ' ')
            {
                G[i] = mp[G[i]];
            }
        }
        out << "Case #" << Case << ": ";
        out << G << endl;
        Case++;
    }
    return 0;
}