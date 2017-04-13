// Template By Fendy Kosnatha (Seraph)
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
#include <cstring>
#include <string.h>

#define fs first
#define sc second
#define mp make_pair
#define pii pair<int, int>

using namespace std;
int main()
{
    int tc;
    cin>>tc;
    int count=1;
    while (tc--)
    {
        int r,t;
        cin>>r>>t;
        cout<<"Case #"<<count++<<": ";
        int ans = 0;
        while (true)
        {
            int temp = r+1;
            int butuh = (temp*temp) - (r*r);
            if (t-butuh>=0)
            {
                ans++;
                t-=butuh;
                r+=2;
            }
            else
            {
                break;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
