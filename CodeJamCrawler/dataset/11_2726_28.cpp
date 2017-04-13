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
int R,C;
string T[55];
int X[55][55];
bool possible;

int main(){
    freopen("A-large.in","r",stdin);
    freopen("saida.txt","w",stdout);
    int TT,tt = 0;
    cin >> TT;
    while(tt++ < TT){
        cin >> R >> C;
        for(int i = 0; i < R; i++){
            cin >> T[i];
        }
        memset(X,0,sizeof(X));
        possible = true;
        for(int i = 0; i < R; i++){
            for(int j = 0; j < C; j++){
                if( 0 < j && X[i][j-1] == 1 ){
                    //cout << "B";
                    if(T[i][j] == '#' && i < R-1){
                        X[i][j] = 2;
                        T[i][j] = '\\';
                    }
                    else possible = false;
                }
                else if((0 < i && X[i-1][j] == 1) ){
                    //cout << "C";
                    if(T[i][j] == '#' && j < C-1 ){
                        T[i][j] = '\\';
                        X[i][j] = 3;
                    }
                    else possible = false;
                }
                else if( (0 < j && 0 < i && X[i-1][j-1] == 1) ){
                    //cout << "D";
                    if(T[i][j] == '#'){
                        X[i][j] = 4;
                        T[i][j] = '/';
                    }
                    else possible = false;
                }
                else if( ( (0 == i) || X[i-1][j] == 0 || X[i-1][j] == 3 || X[i-1][j] == 4 ) &&
                            ( (j == 0) || X[i][j-1] == 0 || X[i][j-1] == 2 || X[i][j-1] == 4) && T[i][j] == '#'){
                                //cout << "A";
                                if( i < R-1 && j < C-1 ){
                                    X[i][j] = 1;
                                    T[i][j] = '/';
                                }
                                else possible = false;
                }
                else{
                    //possible = false;
                    //cout << 'E';
                }
            }
            //cout <<endl;
        }
        cout << "Case #"<<tt <<":" << endl;
        if(possible){
            for(int i = 0; i < R; i++){
                for(int j = 0; j < C; j++){
                    cout << T[i][j];
                }
                cout << endl;
            }
        }
        else cout << "Impossible"  << endl;
    }
    return 0;
}

