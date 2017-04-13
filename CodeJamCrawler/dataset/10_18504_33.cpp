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
    int n;
    int t;
    s(t);
    int i,j=1,l;
    long long int k;
    while(j<=t){
           s(n);
           long long int cnt=1,z;
           scanf("%lld",&k);
           if(k==0){
                   printf("Case #");printf("%d",j);printf(": OFF\n");
           }
           else{
                z=(long long int)pow((double)2,n);
               cnt=z-1;
               bool b=false;
               while(true){
                     if(cnt==k){
                                   b=true;
                                   break;
                     }
                     if(cnt>k)
                            break;
                     
                     cnt=cnt+z;
               }            
               if(b){
                      printf("Case #");printf("%d",j);printf(": ON\n");
               }
               else{
                     printf("Case #");printf("%d",j);printf(": OFF\n");
               }
           }
           j++;
    }
   // system("pause");
}                     
