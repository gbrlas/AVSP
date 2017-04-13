#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <queue>
#include <set>

using namespace std;

typedef long long LL;

ifstream fi("A.in");
ofstream fo("A.out");
int main()
{
    int n;
    fi>>n;
    for (int i=0;i<n;i++)
    {
        int s, q;
        string a[110];
        string b[1010];
        map<string, bool> mp;
        fi>>s;
        string t;
        getline(fi,t);
        for (int j=0;j<s;j++)
        {
            getline(fi,a[j]);
            mp[a[j]]=true;
        }
        fi>>q;
        getline(fi,t);
        for (int j=0;j<q;j++) getline(fi,b[j]);
        set<string> ss;
        int ret=0;
        for (int j=0;j<q;j++)
        {
            if (mp[b[j]]) ss.insert(b[j]);
            if (ss.size()>=s)
            {
                       ret++;
                       ss.clear();
                       ss.insert(b[j]);
            }
//            cout<<ss.size()<<" "<<ret<<endl;
        }
//        cin.get();
        fo<<"Case #"<<(i+1)<<": "<<ret<<endl;
    }
    fi.close();
    fo.close();
}
