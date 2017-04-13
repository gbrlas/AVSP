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

int n;
char M[50][50];
long long mask[111],opp[50];
int pilha[111];
int p;
char a[111];

int main(){
    freopen("B-large.in","r",stdin);
    freopen("saida.txt","w",stdout);
    int t;
    scanf("%d",&t);
    int c;
    
    for(int tt = 0; tt < t; tt++){
        memset(M,-1,sizeof(M));
        memset(opp,0,sizeof(opp));
        
        scanf("%d",&c);
        for(int i = 0; i < c; i++){
            scanf("%s",a);
            M[ a[0] - 'A' ][ a[1] - 'A'] = M[ a[1] - 'A' ][ a[0] - 'A' ] = a[2] - 'A';
        }
        
        scanf("%d",&c);
        for(int i = 0; i < c; i++){
            scanf("%s",a);
            opp[ a[0] - 'A'] |= (1LL<<(a[1]-'A'));
            opp[ a[1] - 'A'] |= (1LL<<(a[0]-'A'));
        }
        
        scanf("%d",&n);
        scanf("%s",a);
        p = 0;   
        for(int i = 0; i < n; i++){
            if(p == 0){
                pilha[p++] = a[i]-'A';
                mask[0] = (1LL << (a[i] - 'A'));
            }
            else{
                //cout << (char)(pilha[p-1] + 'A') << charM[ pilha[p-1] ][ a[i] ]
                if( M[ pilha[p-1] ][ a[i] - 'A'] >= 0){
                    pilha[p-1] = M[pilha[p-1]][a[i] - 'A'];
                    if(p >= 2) mask[p-1] = mask[p-2];
                    else if(p == 1) mask[p-1] = 0;
                }
                else if( mask[p-1] & opp[ a[i] - 'A' ] ) p = 0;
                else{
                    mask[p] = mask[p-1] | (1LL<<(a[i] - 'A'));
                    pilha[p++] = a[i]-'A';
                }
            }
        }
        
        printf("Case #%d: ",tt+1);
        if(p == 0) printf("[]\n");
        else{
            printf("[%c",pilha[0]+'A');
            for(int i = 1; i < p; i++) printf(", %c",pilha[i]+'A');
            printf("]\n");
        }
        
    }
    return 0;
}
