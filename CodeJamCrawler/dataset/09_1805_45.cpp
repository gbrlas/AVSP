#include <algorithm>
#include <iostream>
#include <complex>
#include <numeric>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <map>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

string x;

void Solve(){
    cin>>x;
    string y=x;
    next_permutation(y.begin(),y.end());
    if(y>x)cout<<y<<endl;
    else{
        y="0"+x;
        next_permutation(y.begin(),y.end());
        cout<<y<<endl;
    }
}

int main(){
    #ifdef LocalHost
    freopen("x.in","r",stdin);
    freopen("x.out","w",stdout);
    #endif
    int a=0,b;
    for(cin>>b;a++<b;Solve())printf("Case #%d: ",a);
    return 0;
}
