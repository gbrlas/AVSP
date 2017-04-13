/* Bismillahir Rahmanir Rahim */
/*Coder: Ahmad Faiyaz*/

#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <fstream>

# define FOR(i, a, b) for (int i=a; i<b; i++)
# define REP(i, a) FOR(i,0,a)

#define EPS 1e-11
#define inf 1234567891
#define LL long long

#define abs(x) (((x)< 0) ? (-(x)) : (x))
#define all(x) (x).begin(), (x).end()
#define ms(x, a) memset((x), (a), sizeof(x))

# define VI vector<int>
# define VS vector<string>
# define VC vector<char>

#define mp make_pair
#define pb push_back
#define sz(k) (int)(k).size()
#define FORIT(i,m) for(__typeof((m).begin()) i=(m).begin();i!=(m).end();i++)
#define pii pair<int,int>
#define UNIQUE(c) (c).resize( unique( all(c) ) - (c).begin() )

#define READ(f) {ifstream infile(f) ;if(infile.good()) freopen(f, "r", stdin);}
#define WRITE(f) freopen(f, "w", stdout)
#define DBG(vari) cerr<<#vari<<" = "<<(vari)<<endl;

///int rrr[]={1,0,-1,0};int ccc[]={0,1,0,-1}; //4 Direction
///int rrr[]={1,1,0,-1,-1,-1,0,1};int ccc[]={0,1,1,1,0,-1,-1,-1};//8 direction
///int rrr[]={2,1,-1,-2,-2,-1,1,2};int ccc[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
///int rrr[]={2,1,-1,-2,-1,1};int ccc[]={0,1,1,0,-1,-1}; //Hexagonal Direction
///int month[]={31,28,31,30,31,30,31,31,30,31,30,31}; //month

using namespace std;

template <class stl>
void DBGSTL (stl a) { // for deque, vector , set
    FORIT(i,a) {
        cerr<<*i<<" ";
    }
    cerr<<"\n";
    return;
}
char grid [8][8];

int check (char p) {
    for(int i=0; i<4; i++) { // row wise
        int ok = 1;
        for(int j=0; j<4; j++) {
            if(grid[i][j]!='T' && grid[i][j]!=p) {
                ok=0;
            }
        }
        if(ok){
          //  cout<<"row "<<i<<" milse\n";
            return 1;
        }
    }

    for(int j=0; j<4; j++) { // column wise
        int ok = 1;
        for(int i=0; i<4; i++) {
            if(grid[i][j]!='T' && grid[i][j]!=p) {
                ok=0;
            }
        }
        if(ok){
         //   cout<<"col "<<j<<" milse\n";
            return 1;
        }
    }
    int j=0;
    int ok=1;
    for(int i=0;i<4;i++){
        if(grid[i][j]!='T' && grid[i][j]!=p) {
                ok=0;
        }
        j++;
    }
    if(ok){
          //  cout<<"main dia te milse\n";
            return 1;
    }
    ok=1;
    j=3;
    for(int i=0;i<4;i++){
        if(grid[i][j]!='T' && grid[i][j]!=p) {
                ok=0;
        }
        j--;
    }
    if(ok) return 1;

    return 0;
}

int main() {
#if defined( faiyaz_pc )
    READ("A-small-attempt0.in");
    WRITE("out.txt");
#endif
    int t,chk=1;
    cin>>t;
    while(t--) {
        int cover=1;
        for(int i=0; i<4; i++) {
            for(int j=0; j<4; j++) {
                cin>>grid[i][j];
                if(grid[i][j]=='.') {
                    cover=0;
                }
            }
        }
        /*
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                cout<<grid[i][j];
            }
            cout<<endl;
        } */
        printf("Case #%d: ",chk++);
        int p1 = check ('X');
        int p2 = check ('O');


        if(p1){
            printf("X won\n");
            continue;
        }
        if(p2){
            printf("O won\n");
            continue;
        }
        if(!cover){
            printf("Game has not completed\n");
            continue;
        }

        printf("Draw\n");

    }
    return 0;
}
