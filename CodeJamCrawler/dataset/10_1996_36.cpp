#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cfloat>
#include <climits>
#include <cctype>
#include <cmath>
#include <cassert>
#include <ctime>

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define eps 1e-10
#define inf 0x3f3f3f3f

#define fr(x,y,z) for(int x = (y); x < (z); x++)

#define console cout
#define dbg(x) console << #x << " == " << x << endl
#define print(x) console << x << endl

int L,P,C;
int u = 0;
map<pair<int,int> ,int> opa;
int go(int l, int p){
    
    int a = C, b = inf,atual;
    if(l*C >= p) return 0;
    //if(u > 3) return 0;
    //else u++;
    //if( l*C >= ( (p + C - 1 ) / C ) ) return 1;
    if(opa.find(make_pair(l,p)) != opa.end() ) return opa[make_pair(l,p)];
    //printf("%d %d\n",l,p);
    for(int i = 1; a*l <= p; i++){
        if(l < a*l && a*l <= p && l < (p + a - 1 ) / a && (p + a - 1 ) / a <= p) atual = min( max( go(l,a*l), go(a*l,p) ),  max( go(l,(p + a - 1 ) / a), go( (p + a - 1 ) / a, p) ) );
        else if(l < a*l && a*l < p )atual = max( go(l,a*l), go(a*l,p));
        else if(l < (p + a - 1 ) / a && (p + a - 1 ) / a < p) atual = max( go(l,(p + a - 1 ) / a), go( (p + a - 1 ) / a, p) );
        else atual = inf;
        b = min( b , atual + 1);
        a *= C;
    }
    return b;
    //b = min( b , max( go(a*l,p) + 1, go(l,(p + a - 1 ) / a ) + 1 ) );
}

void read(){
    scanf("%d %d %d",&L,&P,&C);
    opa.clear();
    printf("%d\n", go(L,P));
}

int main(){
    int t;
    freopen("B-small-attempt0.in","r",stdin);
    freopen("saida.txt","w",stdout);
    scanf("%d",&t);
    for(int i = 0; i < t; i++){
        printf("Case #%d: ",i+1);
        read();
    }
}
