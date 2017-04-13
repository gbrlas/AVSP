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

ifstream fi("B.in");
ofstream fo("B.out");

int main()
{
    int t;
    fi>>t;
    for (int testcase=1;testcase<=t;testcase++)
    {
        fo<<"Case #"<<testcase<<": ";
        string s;
        fi>>s;
        vector<char> v;
        for (int i=0;i<s.size();i++) v.push_back(s[i]);
        int i=s.size()-2;
        for (;i>=0;i--)
            if (s[i]<s[i+1]) break;
        if (i<0)
        {
                v.push_back('0');
                sort(v.begin(),v.end());
                int j=0;
                for (;j<v.size();j++)
                    if (v[j]!='0') break;
                fo<<v[j];
//                cout<<"       "<<j<<" "<<v[j];cin.get();
                for (int k=0;k<j;k++)
                    fo<<"0";
                for (j=j+1;j<v.size();j++)
                    fo<<v[j];
                fo<<endl;
        }
        else
        {
            int mm=i+1;
            for (int j=i;j<s.size();j++)
                if (s[j]>s[i] && s[j]<s[mm]) mm=j;
            swap(v[i],v[mm]);
            for (int k=i+1;k<s.size();k++)
                for (int h=k+1;h<s.size();h++)
                    if (v[k]>v[h]) swap(v[k],v[h]);
            for (int j=0;j<v.size();j++)
                fo<<v[j];
            fo<<endl;
        }
    }
}
