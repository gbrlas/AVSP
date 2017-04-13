#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <sstream>
#include <stdio.h>
#include <math.h>
#include <memory.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define SZ(x) (int)(x.size())
#define F0(i,n) for(i=0;i<n;i++)
#define F1(i,n) for(i=1;i<=n;i++)
const int inf = 1000000009;
const double pi = atan(1.0)*4.0;
const double eps = 1e-8;

int i, j, k, m, n, l, o, p;
int a[5000001], q[5000001], h[5000001];

int main()
{
    int caseCounter = 0;
    cin>>n;
    while(n--){
        cin>>p>>k>>l;
        vector<int> freq;
        vector<int> keys;
        int ans = 0;
        F0(i,l) {cin>>j;freq.push_back(j);}
        F0(i,k) keys.push_back(1);

        sort(freq.begin(),freq.end(),greater<int>());
        F0(i,l) {
            sort(keys.begin(),keys.end());
            ans += keys[0] * freq[0];
            keys[0]++;
            freq.erase(freq.begin());
        }
        cout<<"Case #"<<++caseCounter<<": "<<ans<<endl;
    }
    return 0;
}