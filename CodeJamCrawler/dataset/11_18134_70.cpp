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
    ifstream fi("candysplitting.in");
    ofstream fo("candysplitting.out");
    int t;
    fi>>t;
    for (int tc=1;tc<=t;tc++)
    {
        int n, m=1000000000, ret=0, cur=0;
        fi>>n;
        for (int i=0;i<n;i++)
        {
            int x;
            fi>>x;
            ret+=x;
            m<?=x;
            cur^=x;
        }
        fo<<"Case #"<<tc<<": ";
        if (cur!=0) fo<<"NO"<<endl;
        else fo<<ret-m<<endl;
    }
}
