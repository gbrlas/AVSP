#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;

int main(void)
{
    int n;
    char out = 'a';
    vector<string> s;

    cin >> n;
    cin.ignore();
    for(int i=0; i<n; i++)
    {
        string str;
        getline(cin, str);
        s.push_back(str);
    }

    for(int i=0; i<n; i++)
    {
        cout <<"Case #" << i+1 << ": ";
        for(int j=0; j<s[i].size(); j++)
        {
            //move code
            switch( s[i][j] )
            {
                case 'a':
                    out = 'y';
                    break;

                case 'b':
                    out = 'h';
                    break;

                case 'c':
                    out = 'e';
                    break;

                case 'd':
                    out = 's';
                    break;

                case 'e':
                    out = 'o';
                    break;

                case 'f':
                    out = 'c';
                    break;

                case 'g':
                    out = 'v';
                    break;

                case 'h':
                    out = 'x';
                    break;

                case 'i':
                    out = 'd';
                    break;

                case 'j':
                    out = 'u';
                    break;

                case 'k':
                    out = 'i';
                    break;

                case 'l':
                    out = 'g';
                    break;

                case 'm':
                    out = 'l';
                    break;

                case 'n':
                    out = 'b';
                    break;

                case 'o':
                    out = 'k';
                    break;

                case 'p':
                    out = 'r';
                    break;

                case 'q':
                    out = 'z';
                    break;

                case 'r':
                    out = 't';
                    break;

                case 's':
                    out = 'n';
                    break;

                case 't':
                    out = 'w';
                    break;

                case 'u':
                    out = 'j';
                    break;

                case 'v':
                    out = 'p';
                    break;

                case 'w':
                    out = 'f';
                    break;

                case 'x':
                    out = 'm';
                    break;

                case 'y':
                    out = 'a';
                    break;

                case 'z':
                    out = 'q';
                    break;

                case ' ':
                    out = ' ';
                    break;
            }
            cout << out;
        }
        cout << endl;
    }

    return 0;
}

