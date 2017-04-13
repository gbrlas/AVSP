//
//  main.cpp
//  testcpp
//
//  Created by 陈 建飞 on 12-11-11.
//  Copyright (c) 2012年 陈 建飞. All rights reserved.
//
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

template<class T> inline void checkmin(T &a,T b){if(b<a) a=b;}
template<class T> inline void checkmax(T &a,T b){if(b>a) a=b;}
template<class T> inline T gcd(T a,T b){return a==0?b:gcd(b%a,a);}
template<class T> inline int countbit(T n){return n==0?0:(1+countbit(n&(n-1)));}
template<class T> inline void pout(T A[],int n){cout<<"{";for (int i=0;i<n;i++)cout<<A[i]<<", ";cout<<"}\n";}
template<class T> inline void pout(vector<T> A,int n=-1){if (n==-1) n=A.size();cout<<"{";for (int i=0;i<n;i++)cout<<A[i]<<", ";cout<<"}\n";}

#define REP(i,n) for(i=0;i<(n);++i)
#define FOR(i,l,h) for(i=(l);i<=(h);++i)
#define FORD(i,h,l) for(i=(h);i>=(l);--i)
#define FORIT(a,aa) for(a=aa.begin();a!=aa.end();++a)
#define split(str) {vs.clear();istringstream sss(str);while(sss>>(str))vs.push_back(str);}

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long ll;
typedef pair<ll,ll> PII;
typedef pair<double,double> PDD;

const double eps=1e-9;

ll solve();

int main()
{
    //   freopen("/Users/cjf/Desktop/testcpp/testcpp/A-large.in","r",stdin);
    
    freopen("/Users/cjf/Desktop/testcpp/testcpp/A-small-attempt4.in","r",stdin);
	freopen("/Users/cjf/Desktop/testcpp/testcpp/A.txt","w",stdout);
    
	int T,l;
	cin>>T;
	for (l=1;l<=T;l++)
	{
        ll ans = solve();
		printf("Case #%d: ",l); cout<<ans<<endl;//printf("%.6f\n",res);
	}
	return 0;
}
map<int, map<int,int> > mp;
ll MOD=1000002013;

ll N;
ll f(ll x)
{
    return (2*N+1-x)*x/2;
}

struct Node{
    ll o,e,p;
};
bool cmp(Node a, Node b)
{
    if (a.o!=b.o) return a.o<b.o;
    if (a.e!=b.e) return a.e<b.e;
    return a.p<b.p;
}
Node v[20000];
ll good(Node &a, Node &b){
    ll ans = (f(a.e-a.o)-f(b.e-a.o)+f(b.e-b.o)-f(a.e-b.o))*min(a.p,b.p);
    return ans;
}
ll solve()
{
    ll M,i,ans=0;
    cin>>N>>M;
    REP(i,M){
        Node &nd=v[i];
        cin>>nd.o>>nd.e>>nd.p;
    }

    ll k=0;
    while (k<M-1) {
        sort(v+k,v+M,cmp);
        ll best=0,id=-1;
     //   cout<<k<<endl;
        for (i=k+1;i<M;i++) if (v[k].o!=v[i].o&&v[k].e>=v[i].o&&v[k].e<v[i].e){
     //       cout<<k<<" k "<<v[k].o<<" "<<v[k].e<<" "<<v[k].p<<endl;
      //      cout<<i<<" i "<<v[i].o<<" "<<v[i].e<<" "<<v[i].p<<endl;
            ll d=good(v[k],v[i]);
            if (d>best) best=d,id=i;
            ans%=MOD;
        }
        if (best==0) {k++;continue;}
        i=id;
        {
            //       cout<<k<<" k "<<v[k].o<<" "<<v[k].e<<" "<<v[k].p<<endl;
            //      cout<<i<<" i "<<v[i].o<<" "<<v[i].e<<" "<<v[i].p<<endl;
            ans += good(v[k],v[i]);
            ans%=MOD;
            Node nd1=v[k],nd2=v[i];
            ll cm=min(v[k].p,v[i].p);
            swap(v[k].e,v[i].e);
            v[k].p=v[i].p=cm;
            if (nd1.p>cm) nd1.p-=cm,v[M++]=nd1;
            else if (nd2.p>cm) nd2.p-=cm,v[M++]=nd2;
        }

            
    }
    return ans;
}

