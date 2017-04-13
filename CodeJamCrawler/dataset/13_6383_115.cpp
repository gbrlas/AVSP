#include <iostream>
using namespace std;
#include <stdio.h>
#include <string.h>

#define SIZE 100
class Lawnmover
{
    int N,M;
    int row_m[SIZE];
    int col_m[SIZE];
    int a[SIZE][SIZE];
    char *ans[2]={"NO","YES"};
public:
     void solution(char *,char *);
     int isPossible();
};

int Lawnmover::isPossible()
{
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            if(a[i][j]!=row_m[i] && a[i][j]!=col_m[j])
                return 0;
        }
    }
    return 1;
}
void Lawnmover::solution(char *in,char *out)
{
    freopen(in,"r",stdin);
    freopen(out,"w",stdout);
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++) {
        memset(row_m,0,sizeof(int)*N);
        memset(col_m,0,sizeof(int)*M);
        scanf("%d%d",&N,&M);
        for(int i=0;i<N;i++) {
            for(int j=0;j<M;j++) {
                scanf("%d",&a[i][j]);
                    if(row_m[i]<a[i][j]) row_m[i]=a[i][j];
                    if(col_m[j]<a[i][j]) col_m[j]=a[i][j];
            }
        }
        printf("Case #%d: %s\n",t,ans[isPossible()]);
    }
}
int main()
{
    Lawnmover lm;
    lm.solution("B-large.in","out.txt");
    return 0;
}
