//
//  main.cpp
//  codejamA
//
//  Created by Martin Goffan on 4/13/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>
#include <limits>

using namespace std;

int main (int argc, const char * argv[])
{
	freopen("A-small-attempt4.in", "r", stdin);
	freopen("output.out", "w", stdout);
	
    map<char, char> alphabet;
    alphabet['y'] = 'a';
    alphabet['n'] = 'b';
    alphabet['f'] = 'c';
    alphabet['i'] = 'd';
    alphabet['c'] = 'e';
    alphabet['w'] = 'f';
    alphabet['l'] = 'g';
    alphabet['b'] = 'h';
    alphabet['k'] = 'i';
    alphabet['u'] = 'j';
    alphabet['o'] = 'k';
    alphabet['m'] = 'l';
    alphabet['x'] = 'm';
    alphabet['s'] = 'n';
    alphabet['e'] = 'o';
    alphabet['v'] = 'p';
    alphabet['z'] = 'q';
    alphabet['p'] = 'r';
    alphabet['d'] = 's';
    alphabet['r'] = 't';
    alphabet['j'] = 'u';
    alphabet['g'] = 'v';
    alphabet['t'] = 'w';
    alphabet['h'] = 'x';
    alphabet['a'] = 'y';
    alphabet['q'] = 'z';
    
    string current = "";
    int nCases;
    cin >> nCases;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    for (int i = 1; i <= nCases; i++) {
		getline(std::cin, current);
        string result = "";
        for (unsigned int j = 0; j < current.size() ; j++) {
            char c = current[j];
            result += (c == (char)32) ? ' ' : alphabet[c];
        }
        cout << "Case #" << i << ": " << result << endl;
    }
}
