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

#define pb push_back

using namespace std;

int n;
string s [105];

void solve () {
    cin>>n;
    for (int i = 0; i < n; ++i){
        cin>>s[i];
    }
    
    vector<char> ch;
    ch.pb(s[0][0]);
    for (int i = 1; i < s[0].size(); ++i){
        if (s[0][i] != s[0][i-1]){
            ch.pb(s[0][i]);
        }
    }
    for (int i = 1; i < n; ++i){
        if (s[i][0] != ch[0]){
            cout<< "Fegla Won"<<endl;
            return;
        }
        int k = 1;
        for (int j = 1; j < s[i].size(); ++j) {
            if (s[i][j] != s[i][j-1]){
                
                if (k == ch.size() || s[i][j] != ch[k++]){
                    cout<<"Fegla Won"<<endl;
                    return;
                }
            }
        }
        if (k != ch.size()){
            cout<<"Fegla Won"<<endl;
            return;
        }
    }
    
    vector<double> avg;
    
    avg.pb(1.0);
    int k = 0;
    for (int i = 1; i < s[0].size(); ++i){
        if (s[0][i] == s[0][i-1]){
            avg[avg.size()-1]+=1.0;
        }
        else {
            avg.pb(1.0);
        }
    }
    
    for (int i = 1; i < n; ++i){
        int k = 0;
        avg[0]+= 1.0;
        for (int j = 1; j < s[i].size(); ++j){
            if (s[i][j] == s[i][j-1]){
                avg[k]+=1.0;
            }
            else {
                avg[++k] += 1.0;
            }
        }
    }
    
    for (int i = 0; i < avg.size(); ++i){
        avg[i] = floor(avg[i]/n+0.5);
    }
    
    
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int k = 0;
        int acum = 1;
        for (int j = 1; j < s[i].size(); ++j){
            if (s[i][j] != s[i][j-1]){
                ans += abs(acum-avg[k++]);
                acum = 1;
            }
            else {
                ++acum;
            }
        }
        ans += abs(acum-avg[k]);
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