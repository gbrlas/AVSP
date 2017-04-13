#include <cassert>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<complex>
#include<vector>
#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<string>
#include<cstdlib>
#include<memory.h>
#include<ctime>
#include<bitset>


#define FOR(i,a,b)		for(int i=(a);i<(b);i++)
#define FORD(i,a,b)		for(int i=(b);i>=(a);i--)
#define REP(i,n)		FOR(i,0,n)
#define SORT(v)			sort((v).begin(),(v).end())
#define UN(v)			SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define pb                      push_back

//#define LocalHost  


using namespace std;
int fa,sa,t;
int f[4][4];
int s[4][4];



void next()
{
    cin>>fa;
    FOR(i,0,4)
        FOR(j,0,4)
        cin>>f[i][j];
    cin>>sa;
    FOR(i,0,4)
        FOR(j,0,4)
        cin>>s[i][j];
}


void solve(int num)
{
    vector<int> res;
    set<int> rs;
    FOR(i,0,4)
        rs.insert(f[fa-1][i]);
        
    FOR(i,0,4)
        if (rs.find(s[sa-1][i]) !=rs.end() )
            res.push_back(s[sa-1][i]);
        
    if (res.size()==1)
        cout<<"Case #"<<num<<": "<<res[0]<<endl;
 
    if (res.size()>1)
        cout<<"Case #"<< num <<": Bad magician!"<<endl;

    if (res.size()==0)
        cout<< "Case #"<<num<<": Volunteer cheated!"<<endl;
}


int main(int argc, char** argv) {
    
    
#ifdef LocalHost
    freopen("input.txt", "r", stdin);
     freopen("output.txt", "w", stdout);
#endif
    
    cin>> t;
    FOR(i,0,t)
    {
        next();
        solve(i+1);
    }
    
    return 0;
}

