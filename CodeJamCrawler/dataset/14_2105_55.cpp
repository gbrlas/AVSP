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
 
  
int main()
{
    //clock_t startTime = clock();
 
    int tc; s(tc); int x=1;
    while(tc--)
    {
        int row1,row2,arr1[4][4],arr2[4][4];
        s(row1);
        for(int i=0;i<4;i++)
        for(int j=0;j<4;j++) s(arr1[i][j]);

        s(row2);
        for(int i=0;i<4;i++)
        for(int j=0;j<4;j++) s(arr2[i][j]); 

        vector<int> v; v.clear();
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++) {
                if(arr2[row2-1][j]==arr1[row1-1][i]) {
                    v.pb(arr2[row2-1][j]);
                    break;
                }
            }
        }

        int l=(int)v.size();
        if(l==0) { printf("Case #%d: Volunteer cheated!\n",x); x++; }
        else if(l>1) { printf("Case #%d: Bad magician!\n",x); x++; }
        else { printf("Case #%d: %d\n",x,v[0]); x++; }    
    }
   //cout << " Execution time is :: "<<double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
    return 0;
} 