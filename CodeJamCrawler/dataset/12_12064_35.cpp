#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

const int N = 205;

int id[N];

string a = "ejp mysljylc kd kxveddknmc re jsicpdrysi";
string b = "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
string c = "de kr kd eoya kw aej tysr re ujdr lkgc jv";

string sa = "our language is impossible to understand";
string sb = "there are twenty six factorial possibilities";
string sc = "so it is okay if you want to just give up";

void deal(string x, string y)
{
    for (int i = 0; i < x.size(); i++)
    {
        if (x[i] == ' ') continue;
        id[x[i] - 'a'] = y[i] - 'a';
    }
}

void preprocess()
{
    memset(id, -1, sizeof(id));
    deal(a, sa);
    deal(b, sb);
    deal(c, sc);
    id['q' - 'a'] = 'z' - 'a';
    id['z' - 'a'] = 'q' - 'a';
}

int main ()
{
    //freopen("A-small-attempt0.in", "r", stdin);
    //freopen("A-small.txt", "w", stdout);
    preprocess();
    int ca;
    cin >> ca;
    cin.get();
    string s;
    int K = 0;
    while (ca--)
    {
        getline(cin, s);
        cout << "Case #" << ++K << ": ";
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ') cout << " ";
            else cout.put(id[s[i] - 'a'] + 'a');
        }
        cout << endl;
    }
    return 0;
}
