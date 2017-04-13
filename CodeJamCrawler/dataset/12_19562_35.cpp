#include <iostream>
#include <cmath>
#include <vector>
#include <string>
using namespace std;

int main()
{
    freopen("A-small.in", "r", stdin);
    freopen("output-small.out", "w", stdout);
    char translation[26] = {'y', 'h', 'e', 's', 'o',
                            'c', 'v', 'x', 'd', 'u',
                            'i', 'g', 'l', 'b', 'k', 
                            'r', 'z', 't', 'n', 'w',
                            'j', 'p', 'f', 'm', 'a', 'q'};
    int t;
    cin >> t;
    getchar();
    for (int casenum = 1; casenum <= t; ++casenum) {
        string g;
        getline(cin, g);        
        cout << "Case #" << casenum << ": ";
        for (int i = 0; i < g.length(); ++i) {
            if (g[i] != ' ')
                cout << translation[g[i]-'a'];
            else
                cout << g[i];
        }
        cout << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
