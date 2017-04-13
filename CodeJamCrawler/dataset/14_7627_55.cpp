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

vector<double> m1,m2;

int main() {
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int T;
    sf(T);
    FOR(peg,T) {
            int n;
            sf(n);
            m1.resize(n);
            m2.resize(n);

            double a;

            FOR(i,n) {
                cin>>m1[i];
            }
            FOR(i,n) {
                cin>>m2[i];
            }

            sort(m1.begin(),m1.end());
            sort(m2.begin(),m2.end());

            int y=0,z=0;
            //optimal deceit War

            int i=n-1;
            int j =0;
            int k =n-1;
            while(i>=j) {
                if(m1[i]>m2[k]) {
                    i--;
                    k--;
                    y++;
                } else {
                    j++;
                    k--;
                }
            }
            //y +=n;
            //optimal War policy

            i=n-1;
            j=0;
            k=n-1;

            while(i>=j) {
                if(m1[i]>m2[k]) {
                    i--;
                    z++;
                } else {
                    i--;
                    k--;
                }
            }
        //cout<<"Case #"<<1<<": "<<cur_best<<endl;
        printf("Case #%d: %d %d\n",(peg+1),y,z);
    }


return 0;
}
