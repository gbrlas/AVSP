#include <iostream> 
#include <vector>
#include <string>
#include <string.h>
#include <algorithm> 
#include <sstream>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <bitset>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cfloat>
#include <bitset> 
using namespace std;
 
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
string code="welcome to code jam",tengo;
int A,B;
int dp[20][502];

int go(int a,int b)
{

    if(a==A&&b==B)
        return 1;
    if(b==B)
        return 0;
    
    if(dp[a][b]!=-1)
    return dp[a][b];
    int ans=0;
    if(code[a]==tengo[b]){
        ans+=go(a+1,b+1);
        ans%=10000;
    }
    ans+=go(a,b+1);
    ans%=10000;
    dp[a][b]=ans;
    return ans;
}
int conv(string cad)
{
    int num;
    stringstream is(cad);
    is>>num;
    return num;
}
int main()
{

    int cases;           
   getline(cin,tengo);
   cases=conv(tengo);
   A=code.size();
   int ans;
    for(int k=1;k<=cases;k++)
    {
        getline(cin,tengo);
        B=tengo.size();
        memset(dp,-1,sizeof(dp));
        if(B<A)
        {
        cout<<"Case #"<<k<<": 0000"<<endl;
        continue;
        }
     
        ans=go(0,0);
        cout<<"Case #"<<k<<": ";
        if(ans==0)
            cout<<"0000"<<endl;
        else if(ans<10)
            cout<<"000"<<ans<<endl;
        else if(ans<100)
            cout<<"00"<<ans<<endl;
        else if(ans<1000)
            cout<<"0"<<ans<<endl;
        else cout<<ans<<endl;
        
    }

return 0;
}
