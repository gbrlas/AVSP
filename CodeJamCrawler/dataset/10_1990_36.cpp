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

int n;

pair<int,int> pares[1001];

void read(){
    int a,b,w;
    scanf("%d",&n);
    
    for(int i = 0; i < n; i++){
        scanf("%d %d",&a,&b);
        pares[i].first = a;
        pares[i].second = b;
    }
    w = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if( i != j && pares[i].first < pares[j].first && pares[i].second > pares[j].second) w++;
        }
    }
    
    printf("%d\n",w);
}

int main(){
    int t;
    freopen("A-large.in","r",stdin);
    freopen("saida.txt","w",stdout);
    scanf("%d",&t);
    for(int i = 0; i < t; i++){
        printf("Case #%d: ",i+1);
        read();
    }
}
