#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <sstream>
#include <fstream>
#include <cstring>
#include <string>
#include <cmath>
#include <queue>
#include <stack>

using namespace std;

int a,b,k;

void solve () {
    cin>>a>>b>>k;
    int ans = 0;
    for (int i = 0; i < k; ++i){
        for (int j = 0; j < a; ++j){
            for (int l = 0; l < b; ++l){
                if ((j&l) == i){
                    ++ans;
                }
            }
        }
    }
    cout<<ans<<endl;
}

int main () {
    int cas = 0;
    int t;
    cin>>t;
    for (cas = 1; cas <= t; ++cas){
        cout<<"Case #"<<cas<<": ";
        solve();
    }
}