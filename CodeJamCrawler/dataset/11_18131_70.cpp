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

int main()
{
    ifstream fi("magicka.in");
    ofstream fo("magicka.out");
    int t;
    fi>>t;
    for (int tc=1;tc<=t;tc++)
    {
        int c, d, n;
        map<pair<char, char>, char> sc;
        map<pair<char, char>, int> sd;
        string s, st;
        fi>>c;
        for (int i=0;i<c;i++) {fi>>st;sc[make_pair(st[0],st[1])]=st[2];sc[make_pair(st[1],st[0])]=st[2];}
        fi>>d;
        for (int i=0;i<d;i++) {fi>>st;sd[make_pair(st[0],st[1])]=1;sd[make_pair(st[1],st[0])]=1;}
        fi>>n;
        fi>>s;
        string ret="";
        for (int i=0;i<n;i++)
        {
            if (ret=="") ret+=s[i];
            else
            {
                if (sc.count(make_pair(ret[ret.size()-1],s[i])))
                {
                                                                ret[ret.size()-1]=sc[make_pair(ret[ret.size()-1],s[i])];
                }
                else
                {
                    ret+=s[i];
                    for (int j=0;j<ret.size()-1;j++)
                        if (sd[make_pair(ret[ret.size()-1],ret[j])])
                        {
                                                                    ret="";
                                                                    break;
                        }
                }
            }
        }
        fo<<"Case #"<<tc<<": [";
        for (int i=0;i+1<ret.size();i++) fo<<ret[i]<<", ";
        if (ret.size()>=1) fo<<ret[ret.size()-1];
        fo<<"]"<<endl;
    }
}
