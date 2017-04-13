#include <iostream>
#include <cstdio>
#include <string.h>
#include <string>
#include <algorithm>
#include <queue>
#include <map>
#include <vector>
#include <set>
#include <stack>
#include <cmath>

using namespace std;

#define N 300
#define inf 0x7fffffff
#define eps 1e-8

vector <pair <int,int> > move[2];

int main(){
    freopen("a.txt","r",stdin);
    freopen("D:/a.out","w",stdout);
    int T,cas=0,i,j,n,t,pos0,pos1,but,go;
    char rob;
    scanf("%d",&T);
    while (T--){
        cas++;
        scanf("%d",&n);
        getchar();
        for (i = 1; i <= n; ++i){
            scanf("%c %d",&rob,&but);
            getchar();
            if (rob == 'O'){
                move[0].push_back(make_pair(but,i));
            }
            else{
                move[1].push_back(make_pair(but,i));
            }
        }
        i = j = 0;
        pos0 = pos1 = 1;
        t = 0;
        while (i < move[0].size() || j < move[1].size()){
            if (pos0 == move[0][i].first && ((j < move[1].size() && move[0][i].second < move[1][j].second) || j == move[1].size())){
                i++;
                t++;
                if (j < move[1].size() && pos1 != move[1][j].first) {
                    if (pos1 < move[1][j].first) pos1++;
                    else pos1--;
                }
                continue;
            }
            if (pos1 == move[1][j].first && ((i < move[0].size() && move[1][j].second < move[0][i].second) || i == move[0].size())){
                j++;
                t++;
                if (i < move[0].size() && pos0 != move[0][i].first) {
                    if (pos0 < move[0][i].first) pos0++;
                    else pos0--;
                }
                continue;
            }
            go = 0;
            if (i < move[0].size() && pos0 != move[0][i].first) {
                if (pos0 < move[0][i].first) pos0++;
                else pos0--;
                go = 1;
            }
            if (j < move[1].size() && pos1 != move[1][j].first) {
                if (pos1 < move[1][j].first) pos1++;
                else pos1--;
                go = 1;
            }
            if (go == 1) t++;
        }
        printf("Case #%d: %d\n",cas,t);
        move[0].clear();
        move[1].clear();
    }
    return 0;
}
