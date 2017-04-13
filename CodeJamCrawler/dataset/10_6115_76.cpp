
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <cstring>

using namespace std;

#define MAXN 550
int N, M;
int m[MAXN][MAXN];
int width[MAXN][MAXN];
int num[MAXN];


bool canbe(int size, int x, int y){
      
        if(x - size + 1 < 0)return false;
        if(width[x][y] < size)return false;
        for(int i = 1; i < size; i++){
                if(width[x-i][y] < size)return false;
                if(m[x - i][y] != (!m[x - i + 1][y]))return false;
                if(m[x - i][y] == 2)return false;
        }
        return true;
}

void ini(int size, int x, int y){
        for ( int i = 0; i < size; i++)
                for ( int j = 0; j < size; ++j)
                        m[x - i][y - j] = 2;
}

void cnt(){
        memset(width, 0, sizeof(width));
        for ( int i=0; i<M; ++i){
                if (m[i][0] != 2)
                        width[i][0] = 1;
        }

        for ( int i=0; i<M; ++i){                     
                for ( int j=1; j<N; ++j){

                        if (m[i][j] == 2)
                                width[i][j] = 0;
                        else if (m[i][j] == (!m[i][j - 1]))
                                width[i][j] = width[i][j-1] + 1;
                        else
                                width[i][j] = 1;
                }
        }
}

void deal(int size){



        for ( int i = 0; i < M; ++i)
                for ( int j = 0; j < N; ++j) {
                        if(canbe(size, i, j)){
                                num[size]++;
                                ini(size, i, j);
                                cnt();
                        }

                }

}


int main()
{
        int c = 1, cases;
        char in[MAXN];
        freopen("C-small-attempt0.in", "r", stdin);
        freopen("CSout.txt", "w", stdout);
		int tmp;
        scanf("%d", &cases);
        while(cases--){
                memset(num, 0, sizeof(num));
                memset(m, 0, sizeof(m));
                scanf("%d%d", &M, &N);
                for(int i = 0;i < M; i++){
                        scanf("%s", in);
                        for(int j = 0;j < (N/4); j++){
							{
                               	if(in[j]>= '0' && in[j] <= '9')
                					tmp = in[j]-'0';
                				else
        							tmp = in[j]-'A'+10;
        						for(int k=0;k<4;k++)
									m[i][4*j+k] = (tmp >> (3-k))%2 ;	
            				   
							}
						}
                }

                cnt();
        
        
                int ans = 0;
                for(int i = min(M, N); i >= 1; i--){
                        deal(i);
                        if(num[i] != 0)ans++;
                }





                printf("Case #%d: %d\n", c++, ans);
                for(int i = min(M, N); i >= 1; i--){
                        if(num[i] != 0)
                                printf("%d %d\n", i, num[i]);
                }

        }
        return 0;
}
 

 
