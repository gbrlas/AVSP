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


int a[5000001], q[5000001], h[5000001];
bool isUgly(ll n){ return !(n%2) || !(n %3) || !(n%5 ) || !(n%7);};

ll opt(int op, ll src, ll dst){ if(op == 0 || op == 2){return src+dst;} else{ return src - dst ;}; }

void Enum(vector<ll> &nums, int curIndex,int size,int op,ll last,ll current,ll * ans )
{
    if ( curIndex >= size  ) {
//         if(op == 0){
//             *ans += isUgly(last+current);
//         } else if(op == 1) {
//             *ans += isUgly(last-(current));
//         } else {
            *ans += isUgly(opt(op,last,current));
//        }
        return;
    }
    Enum(nums,curIndex+1,nums.size(),0,opt(op,last,current),nums[curIndex],ans);
    Enum(nums,curIndex+1,nums.size(),1,opt(op,last,current),nums[curIndex],ans);
    Enum(nums,curIndex+1,nums.size(),op,last,current * 10 +nums[curIndex],ans);
    return;
}

int main()
{
    int i, j, k, m, n, l, o, p;
    int caseCounter = 0;
    cin>>n;
    while(n--){
        string str;
        vector<ll> nums;
        ll ans = 0;
        ll last,current;
        cin>>str;
        F0(i,str.length()) {nums.push_back(str[i]-'0');}
        last = 0;
        current = nums[0];
        if(str.length()>1){
            Enum(nums,1,str.length(),2,last,current,&ans);
        } else {
            ans += isUgly(nums[0]);
        }

        cout<<"Case #"<<++caseCounter<<": "<<ans<<endl;
    }
    return 0;
}