#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

void solve () {
    vector<vector<int> > mat(4);
    int ans;
    cin>>ans;
    for (int i = 0; i < 4; ++i){
        mat[i] = vector<int>(4);
        for (int j = 0; j < 4; ++j){
            cin>>mat[i][j];
        }
    }
    set<int> a1 (mat[ans-1].begin(),mat[ans-1].end());
    cin>>ans;
    for (int i = 0; i < 4; ++i){
        mat[i] = vector<int>(4);
        for (int j = 0; j < 4; ++j){
            cin>>mat[i][j];
        }
    }
    set<int> a2 (mat[ans-1].begin(),mat[ans-1].end());
    vector<int> in (10);
    in.resize(set_intersection(a1.begin(),a1.end(),a2.begin(),a2.end(),in.begin())-in.begin());
    int n = in.size();
    if (n == 1){
        cout<<in[0]<<endl;
    }
    else if (n>1){
        cout<<"Bad magician!"<<endl;
    } else{
        cout<<"Volunteer cheated!"<<endl;
    }
    
}

int main () {
    int t;
    cin>>t;
    int cas = 1;
    while(cas <= t){
        cout<<"Case #"<<cas<<": ";
        solve();
        ++cas;
    }
}