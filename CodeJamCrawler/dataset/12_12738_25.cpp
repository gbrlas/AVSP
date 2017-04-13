#include <map>
#include <string>
#include <iostream>
#include <cassert>
using namespace std;

map<char, char> T;
void init(string gr, string en)
{
    assert(gr.length() == en.length());
    for (unsigned i = 0; i < gr.length(); ++i)
    {
        if (gr[i] == ' ') continue;
        assert(gr[i] >= 'a' && gr[i] <= 'z');
        if (T[gr[i]])
        {
            assert(T[gr[i]] == en[i]);
        }
        T[gr[i]] = en[i];
    }
}

void process(char* input)
{
    while(*input)
    {
        cout << T[*input];
        input++;
    }
    cout << endl;
}

int main()
{
    string g0 = "y qee";
    string g1 = "ejp mysljylc kd kxveddknmc re jsicpdrysi";
    string g2 = "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
    string g3 = "de kr kd eoya kw aej tysr re ujdr lkgc jv";
    string e0 = "a zoo";
    string e1 = "our language is impossible to understand";
    string e2 = "there are twenty six factorial possibilities";
    string e3 = "so it is okay if you want to just give up";
    init(g0, e0);
    init(g1, e1);
    init(g2, e2);
    init(g3, e3);
    T['z'] = 'q';
    T[' '] = ' ';
    assert(T.size() == 27);
    int t;
    cin >> t;
    for (unsigned i = 0; i <= t; ++i)
    {
        char buf[1024];
        memset(buf, 0, 1024);
        cin.getline(buf, 1024);
        if (i == 0) continue;
        cout << "Case #" << i << ": ";
        process(buf);
    }
    return 0;
}
