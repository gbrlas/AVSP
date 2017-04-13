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

int T,N,K;

int main(){
    freopen("A-large.in","r",stdin);
    freopen("saida.txt","w",stdout);
    scanf("%d",&T);
    int pot;
    for(int i = 0; i < T; i++){
        scanf("%d %d",&N,&K);
        pot = (1<<N);
        if(K%pot == pot - 1) printf("Case #%d: ON\n",i+1);
        else printf("Case #%d: OFF\n",i+1);
    }
    return 0;
}
