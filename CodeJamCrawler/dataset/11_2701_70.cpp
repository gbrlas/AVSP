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
#define PMASK(mask) for(int iiii = 20; iiii >= 0; iiii--) cout << !!(mask & (1<<iiii)); cout << endl

int n,C;

int main(){
    int t;
    freopen("C-small-attempt0.in","r",stdin);
    freopen("saida.txt","w",stdout);

    scanf("%d",&t);
    
    for(int tt = 0; tt < t; tt++){
        int Xor = 0;
        long long Sum = 0;
        int mini=inf;
        scanf("%d",&n);
        for(int i = 0; i < n; i++){
            scanf("%d",&C);
            
            Xor ^= C;
            Sum += C;
            mini = min(C,mini);
        }
        
        printf("Case #%d: ",tt+1);
        if(Xor) printf("NO\n");
        else{
            printf("%d\n",Sum - mini);
        }
        //for(int i = (1<<n)-1; )
        
    }
    
    return 0;
}
