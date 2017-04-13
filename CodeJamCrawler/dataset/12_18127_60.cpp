#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <fstream>

using namespace std;
typedef long long LL;

char ch[30];

void mp(string s1, string s2)
{
     for (int i=0;i<s1.size();i++)
         if (s1[i]!=' ') ch[s1[i]-'a']=s2[i];
}
int main()
{
    freopen("googlerese.in","r",stdin);
    freopen("googlerese.out","w",stdout);
    mp("ejp mysljylc kd kxveddknmc re jsicpdrysi","our language is impossible to understand");
    mp("rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd","there are twenty six factorial possibilities");
    mp("de kr kd eoya kw aej tysr re ujdr lkgc jv","so it is okay if you want to just give up");
    ch['z'-'a']='q';
    ch['q'-'a']='z';
    int tc;
    cin>>tc;
    string s;
    getline(cin,s);
    for (int i=1;i<=tc;i++)
    {
        getline(cin,s);
        cout<<"Case #"<<i<<": ";
        for (int j=0;j<s.size();j++)
            if (s[j]==' ') cout<<' ';
            else cout<<ch[s[j]-'a'];
        cout<<endl;
    }
}
