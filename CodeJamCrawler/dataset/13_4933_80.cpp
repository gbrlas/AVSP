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
    int arr[] = {1,4,9,121,484};
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        cout<<"Case #"<<i+1<<": ";
        int a,b;
        cin>>a>>b;
        int ans = 0;
        for (int i=0;i<5;i++)
            if (arr[i]>=a && arr[i]<=b) ans++;
        cout<<ans<<endl;
    }
    return 0;
}
