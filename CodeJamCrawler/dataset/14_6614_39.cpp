#include <vector>
#include <stack>
#include <cmath>
#include <algorithm>
#include <functional>
#include <vector>
#include <deque>
#include <sstream>
#include <iostream>
#include <queue>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <set>
#include <cstring>
#include <climits>
#include <map>
#include <cassert>
#define mod  1000000007
#define PHI 1000000006
#define ull unsigned long long
#define ill long long int
#define pii pair<int,int>
#define pb(x) push_back(x)
#define F(i,a,n) for(i=(a);i<(n);++i)
#define FD(i,a,n) for(i=(a);i>=(n);--i)
#define FE(it,x) for(it=x.begin();it!=x.end();++it)
#define V(x) vector<x>
#define S(x) scanf("%d",&x)
#define VI vector <int>
#define VII vector < vector <int> >
#define S1(x) scanf("%llu",&x)
#define MAX 100009
#define LOGMAXN 20
#define EPS 0.000001
using namespace std;

vector <int> get()
{
    int i;
    int x;
    cin >> x;
    x--;
    vector <int> s;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int xx;
            cin >> xx;
            if (i == x) {
                s.pb (xx);
            }
        }
    }
    return s;
}

int main()
{
   // freopen ("A-small-attempt0.in", "r", stdin);
   // freopen ("output.txt", "w", stdout);

    int t;
    S (t);
    int ii = 1;
    while (t--) {
        cout << "Case #" << ii++<< ": ";
        vector <int> a = get();
        vector <int> b = get();

        int i,xx,sum=0;

        for (i = 0; i < a.size(); i++) {
            for (int j = 0; j < b.size(); j++) {
                if (a[i] == b[j]) {
                    sum++;
                    xx = a[i];
                    break;
                }
            }
        }

        if (sum == 0) {
            cout << "Volunteer cheated!" << endl;
            continue;
        }
        if (sum > 1) {
            cout << "Bad magician!" << endl;
            continue;
        }
        cout << xx << endl;
    }

    return 0;
}
