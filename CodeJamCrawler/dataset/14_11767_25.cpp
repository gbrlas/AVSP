#include<iostream>
#include<queue>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<string>
#include<cstring>
#include<map>
#include<numeric>
#include<sstream>
#include<cmath>
using namespace std;
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).end,(v).begin
#define pb push_back
#define f(i,x,y) for(int i=x;i<y;i++)
#define FOR(it,A) for(typeof A.begin() it = A.begin();it!=A.end();it++)
#define sqr(x) (x)*(x)
#define mp make_pair
#define clr(x,y) memset(x,y,sizeof x)
#define eps 1e-07
#define SGN(x) ((x)<-eps?-1:(x)>eps?1:0)

typedef pair<int,int> pii;
typedef long long ll;
typedef long double ld;
int main(){
    int cases;
    cin>>cases;
    long double C,F,X;
    f(t,1,cases+1){
        cin>>C>>F>>X;
        long double res=X/2.0;
        long double cur=0.0;
        long double V=2.0;
        while(cur<res){
            res=min(res,cur+X/V);
            cur+=C/V;
            V+=F;
        }
        printf("Case #%d: %.7Lf\n",t,res);
    }
    return 0;
}
