#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve () {
    int n;
    cin>>n;
    vector<double> a(n);
    vector<double> b(n);
    
    for (int i = 0; i < n; ++i){
        cin>>a[i];
    }
    
    for (int i = 0; i < n; ++i){
        cin>>b[i];
    }
    
    if (n == 1){
        if (a[0] > b[0]){
            cout<<"1 1"<<endl;
        }
        else {
            cout<<"0 0"<<endl;
        }
        return;
    }
    
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    vector<bool> ua(n),ub(n);
    
    vector<double> ca,cb;
    ca = a;
    cb = b;
    //Cheating
    int points = 0;
    for (int i = 0; i < n; ++i){
        if (a.back() > b.back()){
            ++points;
            a.pop_back();
            b.pop_back();
        }
        else {
            b.pop_back();
            a.erase(a.begin());
        }
    }
    cout<<points<<" ";
    //Not cheating
    points = 0;
    a = ca;
    b = cb;
    for (int i = 0; i < n; ++i){
        vector<double>::iterator it = lower_bound(b.begin(),b.end(), a.back());
        a.pop_back();
        if (it == b.end()){
            b.erase(b.begin());
            ++points;
        }
        else {
            b.erase(it);
        }
    }
    cout<<points<<endl;
}

int main () {
    int t;
    cin>>t;
    for (int cas = 1; cas <= t; ++cas){
        cout<<"Case #"<<cas<<": ";
        solve();
    }
}