#include <iostream>
#include <stdio.h>
#include <vector>
#define FOR(i,a,b) for(int i=a;i<=b;i++)

using namespace std;

vector <int > list[2];
vector <pair <int,int> > a;
int pos[2],served[2];

int main() {
    freopen("bottrust.inp","r",stdin);
    freopen("bottrust.out","w",stdout);
    int t;
    cin >> t;
    FOR(_,1,t) {
        int n;
        scanf("%d",&n);
        a.clear();
        list[0].clear();
        list[1].clear();
        
        FOR(i,1,n) {
            char c=' ';
            int x;
            while(c==' ') scanf("%c",&c);
            scanf("%d",&x);
            if (c=='O') {
                list[0].push_back(x);
                a.push_back(make_pair(0,x));
            }
            else {
                list[1].push_back(x);
                a.push_back(make_pair(1,x));
            }
        }
        //FOR(i,0,n-1) cerr << a[i].first << " " << a[i].second << endl;
        //FOR(i,1,n) cerr << a[i].first <<" " << a[i].second<< endl;
        
        pos[0]=1,pos[1]=1,served[0]=0,served[1]=0;
        int current=0;
        int res=0;
        while (current<n) {
            res++;
            bool sastified[2]={false,false};
            FOR(i,0,1) 
                if (served[i]<list[i].size()) {
                    int target=list[i][served[i]];
                    if (target==pos[i] && a[current].first==i && a[current].second==pos[i]) sastified[i]=true;
                    else if (target<pos[i]) pos[i]--;
                    else if (target>pos[i]) pos[i]++;
                }
            FOR(i,0,1) 
                if (sastified[i]) {
                    served[i]++;
                    current++;
                }
            //cout << pos[0] <<" " << pos[1] << served[0] << " " <<served[1] << " " << current <<" " << sastified[0] << " " << sastified[1] << endl;
        }
        cout << "Case #" << _ << ": " << res << endl;
    }
}