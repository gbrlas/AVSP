// {{{
#include <algorithm>
#include <assert.h>
#include <bitset>
#include <cctype>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

typedef long double LD;
typedef long long LL;
typedef pair<LD,LD> PD;
typedef pair<int,int> PI;
typedef vector<int> VI;
typedef vector<VI> VII;
typedef vector<string> VS;

#define VAR(v,n) __typeof(n) v=(n)
#define REP(i,n) for(int i=0; i<(n); i++)
#define FOR(i,a,b) for(int i=(a); i<=(b); i++)
#define FORD(i,a,b) for(int i=(a); i>=(b); i--)
#define FORE(i,c) for(VAR(i,(c).begin()); i!=(c).end(); i++)

#define ALL(x) x.begin(),x.end()
#define CLR(A,v) memset((A),v,sizeof((A)))
#define FI first
#define MP make_pair
#define PB push_back
#define SE second
#define SIZE(x) ((int)(x).size())
// }}}
const int mod=10000;
const int bmx=1003;
const char key[]="welcome to code jam";
const int lmx=strlen(key);
int T[bmx][30];
char B[bmx];

int main()
{
    int z; scanf("%d\n",&z);
    REP(zz,z)
    {
        // ---- Cleaning !!! ----
        CLR(T,0);

        // ----------------------
        gets(B);
        int m=strlen(B);
        fprintf(stderr,"Working on %d / %d        len: %d\n",zz+1,z,m);  
        REP(i,m+1) T[i][lmx]=1;
        FORD(i,m-1,0)
            REP(j,lmx){
                T[i][j]=T[i+1][j];
                if(B[i]==key[j]) T[i][j]+=T[i+1][j+1];
                T[i][j]%=mod;    
            }
        int res=T[0][0];   
        int r[4];
        REP(i,4){ r[i]=(res%10); res/=10;}
        printf("Case #%d: ",zz+1);
        FORD(i,3,0) printf("%d",r[i]);
        puts("");
    }
    return 0;
}
