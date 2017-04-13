/*
Author Name::Himanshu Tomar (A lousy COd3r)
Lang::C++
*/
 
#include <bits/stdc++.h>
 
// definitions
 
#define pii pair<int,int>
#define piii pair<int,pii>
#define mp(a,b) make_pair(a,b)
#define pf(a) push_front(a)
#define pb(a) push_back(a)
#define ppf() pop_front()
#define ppb() pop_back()
#define ll long long int
#define ull unsigned long long
#define s(a) scanf("%d",&a)
#define ss(a,b) scanf("%d%d",&a,&b)
#define sl(a) scanf("%lld",&a)
#define clr(x) memset(x,0,sizeof(x))
#define FOR(x,y,z) for(int x=y;x<z;x++)
#define RFOR(x,y,z) for(int x=y;y>=z;x--)
#define bs(a,b,c) binary_search(a,b,c)
#define ub(a,b,c) upper_bound(a,b,c)
#define lb(a,b,c) lower_bound(a,b,c)
const int INF = (int)1e9;
const int NINF = -(int)1e9;
const int MOD = (int)1e9 + 7;
const double PI=acos(-1.0);
const double EPS=1e-11;
 
 
using namespace std;
 
/*
int dx[]={1,0,0,-1};
int dy[]={0,1,-1,0};
 
 
 
int dx[]={1,0,0,-1,1,1,-1,-1};
int dy[]={0,-1,1,0,1,-1,1,-1};
*/
 
template<class T>
T gcd(T a, T b) { while(b) b ^= a ^= b ^= a %= b; return a; }
 
template<class T>
T lcd(T a,T b) { return abs(a*b)/gcd(a,b); }
 
/*
void seive(int N)
{
    memset(prime,1,sizeof(prime));
    prime[0]=prime[1]=false;
     
    for(int i = 4; i < N; i+= 2) prime[i]=false;
     
    for(int i = 3; i*i < N;i+= 2)
    if(prime[i])
        for(int j = i*i; j < N; j+= (i<<1))
            prime[j]=false;
}
*/
 
/*
template<class T>
T pow(T x,T n)
{
    if(n==0) return 1;
    T r=1,y=x;
    while(n>1)
    {
        if(r>=l) { flag=true; break; }
        if(n&1) { r*=y;  }
        y*=y; 
        n/=2;
    }
    r*=y; 
    return r;
}
*/
 
vector<ll> v1,v2;

int main()
{
    //clock_t startTime = clock();
 
    int tc; s(tc); int times=1;
    while(tc--)
    {
        int n; s(n); v1.clear(); v2.clear();
        for(int i=0;i<n;i++) {
            float a; scanf("%f",&a); v1.pb(a*1000000);
        }
        for(int i=0;i<n;i++) {
            float a; scanf("%f",&a); v2.pb(a*1000000);
        }
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        int res1=0,res2=0;

        int i=n-1,j=n-1;
        while(i>=0 && j>=0){
            if(v2[j]>v1[i]) { res1++; j--; i--; }
            else i--;
        }
        i=n-1,j=n-1;
        while(i>=0 && j>=0){
            if(v1[i]>v2[j]) { res2++; j--; i--; }
            else j--;
        }
        printf("Case #%d: %d %d\n",times,res2,(n-res1));
        times++;
    }
   
    
    //cout << " Execution time is :: "<<double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
    return 0;
} 