#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cassert>
#include <cmath>
#include <ctime>
#include <complex>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,l,h) for(int i=(l);i<=(h);++i)
#define printcase(x) printf("Case #%d: ",x)

void mkdir(set<string> &root,const string &s,int k)
{
    while(k<(int)s.size()&&s[k]!='/') ++k;
    root.insert(s.substr(0,k));
    if(k<(int)s.size())
        mkdir(root,s,k+1);
}

void solvecase(int index){
    int n,m;
    set<string> root;
    string s;
    
    root.insert("/");
    cin>>n>>m;
    REP(i,n) {
        cin>>s;
        mkdir(root,s,1);
    }
    int cnt=root.size();
    REP(i,m){
        cin>>s;
        mkdir(root,s,1);
    }
    cnt=root.size()-cnt;
    printcase(index);
    cout<<cnt<<endl;
}

int main()
{   
    int t;
    cin>>t;
    FOR(index,1,t) solvecase(index);
    return 0;
}
