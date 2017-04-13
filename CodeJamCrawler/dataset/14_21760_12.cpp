/*
    31 May 2014
*/
#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <string.h>
#define     pb      push_back
#define     mp      make_pair
#define     Z       100005
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
vector<int > b,c;
int N, a[1005], tmp[1005];
int find_swap()
{
    int i,tot,j,now,rec;

    for(i = 0; i < N; i++)
        tmp[i] = a[i];

    tot = 0;
    for(i = 0; i < N; i++){
        now = b[i];
        if(tmp[i]== b[i]) continue;
        for(j = 0; j < N; j++){
            if(tmp[j]== now){
                rec = j;
                break;
            }
        }

        for(j = rec; j > i; j--){
            swap(tmp[j],tmp[j-1]);
            tot++;
        }
        if(b[i] != tmp[i]) cout<<"UH oh!!"<<endl;
    }

    return tot;
}
int main(){

    int T,tc,mx,i;

    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-Small_Ans.out","w",stdout);
    cin >> T;
    tc = 0;
    while(tc < T){
        tc++;

        cin >> N;
        mx = 0;
        for(i = 0; i < N; i++){
            cin >> a[i];
            mx = max(mx, a[i]);
        }

    int ans,mask,now;

        ans = N*N;
        for(mask = 0; mask < (1<<N); mask++){
            b.clear(); c.clear();
            for(i = 0; i < N; i++){
                if(a[i] == mx){
                    b.pb(a[i]);
                    continue;
                }
                if(mask & (1<<i)) b.pb(a[i]);
                else c.pb(a[i]);
            }
            sort(b.begin(), b.end());
            sort(c.begin(), c.end());
            reverse(c.begin(), c.end());

            for(i = 0; i < c.size(); i++)
                b.pb(c[i]);

            now = find_swap();
            ans = min(now,ans);
        }

        printf("Case #%d: %d\n",tc,ans);
    }

    return 0;
}
