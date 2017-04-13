#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
const int Maxn = 100+10;
int mat[Maxn][Maxn];
int flag[Maxn][Maxn];
int list[Maxn * Maxn];
int N, M;
int is_cutable()
{
    memset(flag, 0, sizeof(flag));
    int ok = 1;
    for ( int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            if(mat[i][j] && !flag[i][j])
            {
                int line =1;
                int row = 1;
                for (int k = 0; k < M; k++)
                {
                    if (mat[i][k] == 0)
                    {
                        row = 0;
                        break;
                    }
                }
                if(row){
                for (int k =0; k < M; k++) flag[i][k] = 1;
                }
                if(!row){
                    for (int k = 0; k < N; k++)
                    {
                        if(mat[k][j] == 0)
                        {
                            line = 0;
                            break;
                        }
                    }
                    if(line){
                    for (int k = 0; k < M; k++) flag[k][j] = 1;
                    }
                }
                if( !row && !line) {ok = 0; return ok;}
            }
        }
        return ok;
}
void cut(int n)
{
    for (int i =0; i < N; i++)
        for ( int j = 0; j < M; j++)
        {
            if(mat[i][j]) mat[i][j] -= list[n];
        }
    int temp = list[n];
    for ( int i = n; i < (N*M); i++) list[i] = list[i]-temp;
}

int main()
{
//	freopen ("data.in", "r",stdin);
//	freopen ("data.out","w",stdout);
	int T;
	scanf("%d", &T);
	for (int num = 1; num < T+1; num++)
	{
        scanf("%d %d", &N, &M);
        int idx = 0;
	    for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++ )
            {
                scanf("%d", &mat[i][j]);
                mat[i][j] = 100 - mat[i][j];
                list [idx++] = mat[i][j];
            }
        sort (list,list+idx);

        int cur = 0;
        int iscutable = 1;
        while(list[N*M -1])
        {
            if ( is_cutable())
            {
                for (int i = 0; i < N*M; i++) if (list[i] != 0){ cur = i; break;}
                cut(cur);
            }
            else {
                iscutable = 0;
                break;
            }
        }
        if(iscutable) printf("Case #%d: YES\n",num);
        else printf("Case #%d: NO\n", num);

	}



	return 0;
}
