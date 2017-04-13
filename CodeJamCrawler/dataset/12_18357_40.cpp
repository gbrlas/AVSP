#include <cstdio>
#include <map>
#include <cstring>
#include <iostream>

#define BUFFOR_SIZE 1000

using namespace std;

map<char, char> mapping;

int tests;

string buf;

int main(){

    mapping['a'] = 'y';
    mapping['b'] = 'h';
    mapping['c'] = 'e';
    mapping['d'] = 's';
    mapping['e'] = 'o';
    mapping['f'] = 'c';
    mapping['g'] = 'v';
    mapping['h'] = 'x';
    mapping['i'] = 'd';
    mapping['j'] = 'u';
    mapping['k'] = 'i';
    mapping['l'] = 'g';
    mapping['m'] = 'l';
    mapping['n'] = 'b';
    mapping['o'] = 'k';
    mapping['p'] = 'r';
    mapping['r'] = 't';
    mapping['s'] = 'n';
    mapping['t'] = 'w';
    mapping['w'] = 'f';
    mapping['u'] = 'j';
    mapping['v'] = 'p';
    mapping['x'] = 'm';
    mapping['y'] = 'a';
    mapping['z'] = 'q';
    mapping['q'] = 'z';

    cin >> tests;
    getline(cin, buf);

    for(int test = 1; test <= tests; test++){
        getline(cin, buf);

        cout << "Case #" << test << ": ";
        for(int i = 0; i < buf.length(); i++){
            if('a' <= buf[i] && buf[i] <= 'z'){
                cout << mapping[buf[i]];
            }
            else{
                cout << buf[i];
            }
        }
        cout << endl;
    }

    return 0;
}
