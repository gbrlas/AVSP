/*
    27 May 2014
*/
#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <string.h>
#define     pb      push_back
#define     mp      make_pair
#define     Z       100005
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
int a[2005],N,X;
bool solve(int  k){
    int i,mn;
    vector<int> b,c;
    b.clear(), c.clear();

    for(i = 0; i < k; i++)
        b.pb(a[i]);

    reverse(b.begin(), b.end());
    for(i = k; i < N; i++)
        c.pb(a[i]);

    mn = min(c.size(), b.size());
    bool flag = true;
    for(i = 0; i < mn ; i++){
        b[i] += c[i];
        if(b[i] > X) flag = false;
    }
    return flag;
}
int main(){

    int T,tc,i,lo,hi,mid; bool flag;
    freopen("A-small-attempt4.in","r",stdin);
    freopen("Asmall4.out","w",stdout);

    cin >> T;
    tc = 0;
    while(tc<T){
        tc++;
        cin >> N >> X;
        for(i = 0; i < N; i++)
            cin >> a[i];

        sort(a, a+ N);
        reverse(a, a+ N);

        lo = (N+1)/2; hi = N;
        while(lo < hi){

            mid = (hi + lo)/2;

            flag = solve(mid);
            if(flag == true) hi = mid;
            else lo = mid+1;

        }

        printf("Case #%d: %d\n",tc,lo);

    }
    return 0;
}

