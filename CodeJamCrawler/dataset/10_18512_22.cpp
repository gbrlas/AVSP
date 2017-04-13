#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<sstream>
#include<math.h>
#include<set>
#include<fstream>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<stack>

#define oo (int)13e7
#define s(n) scanf("%d",&n)
#define sl(n) scanf("%lld",&n)
#define sf(n) scanf("%lf",&n)
#define fill(a,v) memset(a, v, sizeof a)
#define fr(i,s,e) for(int i=s; i < e; i++)
#define fir(i,s,e) for(int i=s; i <= e; i++)
#define ull unsigned long long
#define ll long long
#define bitcount __builtin_popcount
#define all(x) x.begin(), x.end()
#define pb( z ) push_back( z )
#define MEM(a,b) memset(a,(b),sizeof(a))
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))	

using namespace std;

template<class T>
T gcd(T a,T b){return b==0 ? a : gcd(b,a%b);}

string int2str(int x){ stringstream ss ;ss<<x; return ss.str();}

int str2int(string s){int i;stringstream ss(s);ss>>i;return i;}

int main(){
    int t,i,j,k,l,m,n;
    int casen =1 ;
    s(t);
    while(t--){
            s(n);
            vector< pair<int,int> > v;
            fr(i,0,n){
                   s(j);
                   s(k);
                   v.pb(make_pair(j,k));
            }
            int sum=0;
            fr(i,0,n){
                 int x=v[i].first;
                 int y=v[i].second;     
                fr(j,i+1,n){
                     int x1=v[j].first;
                     int y1=v[j].second;     
                     if(i!=j)
                        if((x>x1 && y<y1) || (x<x1 && y>y1))
                                 sum++;
                }
            }
            printf("Case #%d: %d\n",casen,sum);
            casen++;
    }               
   // system("pause");
}           
