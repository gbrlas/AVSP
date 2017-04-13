#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>

#define D(x) //cout << #x " is " << (x) << endl;

using namespace std;

const int MAXN = 1005;
int c, z, a, b, cont;
bool pal[MAXN];
string s;

string
aStr(int x) {
    stringstream ss;
    ss << x;
    s = ss.str();
    return s;
}

int
aInt(string x) {
    stringstream ss(x);
    int u;
    ss >> u;
    return u;   
}

int
main() {
    for (int i = 0; i < MAXN; i++) {
        s = aStr(i);
        if (s.length() == 1) pal[i] = true;
        else pal[i] = false;   
    }
    cin >> c;
    z = 1;
    while (c--) {
        cin >> a >> b;
        printf("Case #%d: ", (z++));
        for (int i = 10; i < b + 3; i++) {
            s = aStr(i);
            char r, t;
            r = s[0];
            t = s[s.size()-1];
            string resto = s.substr(1, s.size()-2);
            if (resto != "") pal[i] = (r == t) && pal[aInt(resto)];
            else if (r == t) pal[i] = true;
            else pal[i] = false;
        }
        cont = 0;
        for (int i = a; i <= b; i++) {
            int raiz = (int) sqrt(i);
            //printf("i: %d, raiz: %d\n", i, raiz);
            if (raiz*raiz != i) {
                //puts("No son las mismas");
                continue;
            }
            //puts("Son las mismas");
            //printf("Pal de i = %d y pal de raiz %d\n", i, raiz);
            if (pal[i] && pal[raiz]) {
                //puts("Entro");
                cont++;
            }
        }
        cout << cont << endl;
    }
    return 0;
}
