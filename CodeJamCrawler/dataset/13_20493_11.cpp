#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <utility>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <climits>
#include <cmath>
using namespace std;
#define PI 3.14159265359
int main()
{
int i, j, t;
long long r, tot, ans;
cin>>t;
for (int k=1; k<=t; ++k){
cin>>r>>tot;
ans=0;
while (((tot-1)>>1ll) >= r){
tot -= ((r<<1ll)+1);
r+=2ll;
++ans;
}
cout << "Case #" << k << ": " << ans <<endl;
}
return 0;
}