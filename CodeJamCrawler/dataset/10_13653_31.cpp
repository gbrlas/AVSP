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
#define MAXINT 10000000000000000ll

using namespace std;

int tc,p,a;
vector <int> M;
int cost[10][515];

long long f(int depth, int a, const vector <int> &v){
    long long cost1 = cost[depth][a] ,cost2 = 0;
    vector <int> A, B;
    if (depth == 0){
        if (v[0] < 0) return MAXINT;
        return 0;
    }
    for (int i = 0; i < v.size(); i++){
        if (v[i] < 0) return MAXINT;
        if (i < v.size()/2) A.push_back(v[i]);
        else B.push_back(v[i]);
    }
    cost1 += f(depth-1, 2*a, A) + f(depth-1, 2*a+1, B);
    for (int i = 0; i < A.size(); i++) A[i]--;
    for (int j = 0; j < B.size(); j++) B[j]--;
    cost2 = f(depth-1, 2*a, A) + f(depth-1, 2*a+1, B);
    //for (int i = 0; i < v.size(); i++) printf("%d ",v[i]); printf("\n");
    //printf("depth %d a %d cost1 %d cost2 %d\n",depth,a,cost1,cost2);
    return min(cost1, cost2);
}

int main(){
    freopen("B-small-attempt0.in","r",stdin);
    //freopen("input2.txt","r",stdin);
    scanf("%d ",&tc);
    for (int TC = 1; TC <= tc; TC++){
        printf("Case #%d: ",TC);
        scanf("%d",&p);
        //printf("p %d\n",p);
        M.clear();
        for (int i = 0; i < (1<<p); i++){
            scanf("%d",&a);
            M.push_back(a);
        }
        for (int i = 1; i <= p; i++){
            for (int j = 0; j < (1<<(p-i)); j++) scanf("%d ",&cost[i][j]);
        }
        printf("%d\n",f(p,0,M));
    }
    return 0;
}
