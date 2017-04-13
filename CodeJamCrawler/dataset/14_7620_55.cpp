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


int main() {
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int T;
    sf(T);
    FOR(peg,T) {
        double c,f,x;
         cin>>c>>f>>x;

        double cur_rate =2.0;

        double cur_best = x/cur_rate;

        double last =0.0;

        while(true) {

            last += c/cur_rate ;
            cur_rate += f;

            if(last+(x/cur_rate) < cur_best) {
                cur_best = last+(x/cur_rate) ;
            } else {
                break;
            }
        }
        //cout<<"Case #"<<1<<": "<<cur_best<<endl;
        printf("Case #%d: %0.9lf\n",(peg+1),cur_best);
    }


return 0;
}
