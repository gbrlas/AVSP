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

int n,m;
char T[111][111];
int W[111],L[111];
double OP[111];
double OPP[111];

int main(){
    freopen("A-small-attempt0.in","r",stdin);
    freopen("saida.txt","w",stdout);
    int TT,tt = 0;
    scanf("%d",&TT);
    while(tt++ < TT){
        scanf("%d",&n);
        memset(W,0,sizeof(W));
        memset(L,0,sizeof(L));
        for(int i = 0 ;i  < n; i++) OP[i] = OPP[i] = 0.0;
        
        for(int i = 0; i < n; i++){
            scanf("%s",T[i]);
        }
        
        for(int i = 0; i < n; i++){

            for(int j = 0; j < n; j++){
                if( T[i][j] == '1') W[i]++;
                else if(T[i][j] == '0') L[i]++;
            }
        }
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j) continue;
                else if((T[i][j] != '.'))OP[i] += ( W[j] - (T[j][i] == '1') )/ ((double)( W[j] + L[j] - 1) );
            }
        }
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j) continue;
                else if((T[i][j] != '.')){
                    OPP[i] += (OP[j]/(W[j]+L[j]));
                }
            }
        }
        cout << "Case #"<< tt <<":" << endl;
        for(int i = 0; i < n; i++){
            double resp = 0.25*(( (double)W[i] )/(W[i]+L[i])) + 0.5*(OP[i]/((double) (W[i] + L[i]))) + 0.25*(OPP[i]/((double)(W[i]+L[i])));
            //cout << (( (double)W[i] )/(W[i]+L[i])) << "  "  << (OP[i]/((double) (W[i] + L[i]))) << " " << (OPP[i]/((double) (W[i] + L[i]))) << endl;
            cout <<  setprecision( (int)(log(resp) + 8) ) << resp << endl;
        }
    }
    return 0;
}
