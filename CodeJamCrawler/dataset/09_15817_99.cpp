#include <iostream>
#include <sstream>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <deque>

using namespace std;

string GCJ,s;
int memo[501][501];

int count(int n, int m){
    if(m==GCJ.size()) return 1;
    if(n==s.size()) return 0;
    
    if(memo[n][m]!=-1) return memo[n][m];
    
    int aux=0;
    
    if(GCJ[m]==s[n]) aux=count(n+1,m+1)+count(n+1,m);
    else aux=count(n+1,m);
    
    memo[n][m]=aux%10000;
    return memo[n][m];
}

void Solve(){
    getline(cin,s);
    
    memset(memo,-1,sizeof(memo));
    int ans=count(0,0);
    
    ostringstream os;
    os<<ans;
    
    s=os.str();
    while(s.size()!=4) s='0'+s;
    
    cout<<s<<endl;
}

int main(){
    freopen("C-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    
    int T;
    scanf("%d\n",&T);
    
    GCJ="welcome to code jam";
    
    for(int tc=1;tc<=T;tc++){
        cout<<"Case #"<<tc<<": ";
        Solve();
    }
    
    return 0;
}
