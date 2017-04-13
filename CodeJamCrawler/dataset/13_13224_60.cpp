#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#define LL long long
using namespace std;
#define mod 1000000007
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define LL long long
const LL INFL = 1e17;
int n,m,k,T;
char s[6][6];

int is_ok(int i,int j,char c){
    int sum = 0;
    for(int k = 1; k < 4; k++)
        if(j+k<4&&s[i][j+k]==c||s[i][j+k]=='T'){
            sum++;
        }
    if(sum >=3) return 1;
    sum = 0;
    for(int k = 1; k < 4; k++)
        if(i+k<4&&s[i+k][j]==c||s[i+k][j]=='T'){
            sum++;
        }
    if(sum >=3) return 1;
    sum = 0;
    for(int k = 1; k < 4; k++)
        if(i+k<4&&j+k<4&&s[i+k][j+k]==c||s[i+k][j+k]=='T'){
            sum++;
        }
    if(sum >=3) return 1;
    sum = 0;
    for(int k = 1; k < 4; k++)
        if(i+k<4&&j-k>=0&&s[i+k][j-k]==c||s[i+k][j-k]=='T'){
            sum++;
        }
    if(sum >=3) return 1;
    return 0;
}

int main(){

    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);

    scanf("%d",&T);
    for(int cas = 1; cas <= T; cas++){
        for(int i = 0; i < 4; i++)
            scanf("%s",s[i]);
        int flag = 0,sum =0;
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++){
                if(s[i][j]=='X' && is_ok(i,j,'X')){
                     flag = 1;
                     goto aaa;
                }
                if(s[i][j]=='O' && is_ok(i,j,'O')) {
                    flag = 2;
                    goto aaa;
                }
                if(s[i][j]=='.') sum++;
            }
        aaa:;
        if(!flag){
            if(!sum) flag = 3;
            else flag = 4;
        }
        if(flag == 1){
            printf("Case #%d: X won\n",cas);
        }else if(flag == 2){
            printf("Case #%d: O won\n",cas);
        }else if(flag == 3) {
            printf("Case #%d: Draw\n",cas);
        }else if(flag == 4){
            printf("Case #%d: Game has not completed\n",cas);
        }

    }
}