using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MP make_pair
#define PB push_back
#define FOR(i,n) for (int i = 0; i < n; i++)
#define FORT(i,a,b) for (int i = a; i < b; i++)
#define SZ(x) ((int)x.size())
#define sf(x) scanf("%d",&x)
#define pf(x) printf("%d\n",x)
#define gc getchar_unlocked
#define all(c) (c).begin(),(c).end()
#define PIII pair<int,pair<int,int> >
#define PII pair<int,int>

int p1[4][4];
int p2[4][4];

int main() {
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int T;
    sf(T);
    FOR(peg,T) {
        int a,b,temp;
        sf(a);
        a--;

        FOR(i,4) {
            FOR(j,4) {
                sf(temp);
                p1[i][j] =temp;
            }
        }

        sf(b);
        b--;

        FOR(i,4) {
            FOR(j,4) {
                sf(temp);
                p2[i][j] =temp;
            }
        }
        int tot =0;
        int cur =0;
        FOR(i,4) {
            FOR(j,4) {
                    if(p1[a][i]==p2[b][j]){
                        tot++;
                        cur=p1[a][i];
                    }
            }
        }
        if(tot==0) {
            cout<<"Case #"<<(peg+1)<<": Volunteer cheated!"<<endl;
        } else if(tot==1){
            cout<<"Case #"<<(peg+1)<<": "<<cur<<endl;
        } else {
            cout<<"Case #"<<(peg+1)<<": Bad magician!"<<endl;
        }
    }


return 0;
}
