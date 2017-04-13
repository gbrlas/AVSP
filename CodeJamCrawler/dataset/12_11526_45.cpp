#include <sstream>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

ifstream in;
ofstream out;
char substmap[] = "yhesocvxduiglbkrztnwjpfmaq";

void solve() 
{
    char buf[111];
    in.getline(buf, 111);
    
    string s(buf);
    
    for(auto itr = s.begin(); itr != s.end(); ++itr)
    {
    	if(islower(*itr))
            *itr = substmap[*itr-'a'];
    }

    out << s;
}

int main(int argc, char* argv[])
{
    string of = argv[1];
    of = of.substr(0, of.find('.')) + ".out";
    
    in.open(argv[1]);
    out.open(of);

    int T; in >> T;
    in.get();
    for(int i=1; i<=T; ++i)
    {
        out << "Case #" << i << ": ";
        solve();
        out << endl;
    }

    out.close();
    in.close();
    system("pause");
}