#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <set>
#include <queue>
#include <vector>
#include <map>
#include <stack>
#include <list>
#include <numeric>

#define pii pair<int,int>
#define FOR(i,n) for (int i = 1, _n = n; i <= _n; i++)
#define FOD(i,n) for (int i = n; i >= 0; i--)
#define MAXINT 1000000000

using namespace std;

int tc,n,m;
char c;
int M[35][35];
vector <pii> A;
map <int,int> mymap;

int C(int color, int len){
    len %= 2;
    if (len == 0) return color;
    else return 1-color;
}

int find(int y, int x){
    int i;
    if (M[y][x] == -1) return 0;
    int color = M[y][x];
    for (i = 1; y+i < m && x+i < n; i++){
        if (M[y+i][x+i] != color) return i;
        for (int j = 0; j < i; j++){
            if (M[y+j][x+i] != C(color, i+j)) return i;
            if (M[y+i][x+j] != C(color, i+j)) return i;
        }
    }
    return i;
}

int main(){
    freopen("C-small-attempt0.in","r",stdin);
    scanf("%d",&tc);
    for (int TC = 1; TC <= tc; TC++){
        mymap.clear();
        scanf("%d %d ",&m,&n);
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n/4; j++){
                scanf("%c ",&c);
                if (c >= 'A' && c <= 'F') c = c - 'A' + 10;
                else c -= '0';
                for (int k = 0; k < 4; k++){
                    int tmp = c & 1;
                    c /= 2;
                    M[i][j*4+3-k] = tmp;
                }
            }
        }
        /*for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++) printf("%d",M[i][j]);
            printf("\n");
        }*/
        int x, y;
        while (true){
            int Ms = 0;
            for (int i = 0; i < m; i++){
                for (int j = 0; j < n; j++){
                    int s = find(i,j);
                    if (Ms < s){
                        Ms = s;
                        x = j; y = i;
                    }
                }
            }
            if (Ms == 0) break;
            mymap[Ms]++;
            for (int i = 0; i < Ms; i++) for (int j = 0; j < Ms; j++){
                M[y+i][x+j] = -1;
            }
        }
        printf("Case #%d: %d\n",TC, mymap.size());
        for (map <int,int>::reverse_iterator it = mymap.rbegin(); it!= mymap.rend(); it++) printf("%d %d\n",it->first,it->second);
    }
    return 0;
}
