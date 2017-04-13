#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <map>
#include <cstdio>
#include <set>
#include <ctime>
#include <queue>
#include <climits>
#include <iterator>
#define LOCAL
#ifdef ONLINE_JUDGE
#undef LOCAL
#endif

#ifdef LOCAL
#define cin in
#define cout out
#endif
#define FOREACH(i, n) for (typeof(n.begin()) i = n.begin(); i != n.end(); ++i)
#define MEMSET(p, c) memset(p, c, sizeof(p))

using namespace std;


int main()
{
#ifdef LOCAL
    ifstream in("input.txt");
    ofstream out("output.txt");
#endif

    string s="ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv";
    string s2="our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up";
    for(int c=0;c<s.size();c++)
        if(s[c]==' ')
            s.erase(s.begin()+c--);
    for(int c=0;c<s2.size();c++)
        if(s2[c]==' ')
            s2.erase(s2.begin()+c--);
    map<char,char> m;
    for(int c=0;c<s.size();c++)
        m[s[c]]=s2[c];
    m['q']='z';
    m['e']='o';
    m['y']='a';
    m['z']='q';
    int T;
    cin>>T;
    cin.ignore();
    for(int c=0;c<T;c++)
    {
        string s3;
        getline(cin,s3);
        cout<<"Case #"<<c+1<<": ";
        for(int c2=0;c2<s3.size();c2++)
            if(s3[c2]!=' ')
            {
                cout<<m[s3[c2]];
            }
            else
                cout<<' ';
        cout<<endl;
    }
}
