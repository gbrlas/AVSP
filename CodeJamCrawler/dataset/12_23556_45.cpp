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

string rotation(string s)
{
    s=s[s.size()-1]+s.substr(0,s.size()-1);
    return s;
}

int main()
{
#ifdef LOCAL
    ifstream in("input.txt");
    ofstream out("output.txt");
#endif
    int nb_cas;
    cin>>nb_cas;
    for(int c=0;c<nb_cas;c++)
    {
        map<pair<string,string>,bool> m;
        int a,b;
        cin>>a>>b;
        long long tot=0;
        for(long long int c2=a;c2<=b;c2++)
        {
            stringstream ss;
            string number;
            ss<<c2;
            ss>>number;
            string number2=number;
            for(int c3=0;c3<number.size()-1;c3++)
            {
                number2=rotation(number2);
                stringstream ss2(number2);
                long long z;
                ss2>>z;
                if(z<a||z>b||z==c2||m[make_pair(min(number,number2),max(number,number2))])
                    continue;
                m[make_pair(min(number,number2),max(number,number2))]=true;
                tot++;
            }
        }
        cout<<"Case #"<<c+1<<": "<<tot<<endl;
    }
}
