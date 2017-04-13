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

int N,L,H;
ll A[111];

int gcd(int a, int b){
    if(a%b) return gcd(b,a%b);
    else return b;
}

int main(){
    freopen("C-small-attempt0.in","r",stdin);
    freopen("saida.txt","w",stdout);
    int TT,tt = 0;
    long long X = 1;
    cin >> TT;
    ll atual;
    while(tt++ < TT){
        cin >> N >> L >> H;
        for(int i = 0; i < N; i++){
            cin >> A[i];
        }
        
        bool opa = false;
        ll resp = -1;
        for(int i = L; i <= H && !opa; i++){
            opa = true;
            for(int j = 0; j < N && opa; j++){
                if((i <= A[j] && (A[j]%i == 0) ) || (A[j]< i && (i%A[j] == 0)) )continue;
                else opa = false;
            }
            if(opa) resp = i;
        }
        cout << "Case #" << tt <<": ";
        
        if( resp != -1) cout << resp << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
