#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    freopen("d:\\in.txt", "r", stdin);
    freopen("d:\\out.txt", "w", stdout);
    int C, N, M, A;
    
    scanf("%d", &C);
    for (int cs=1;cs<=C;cs++) {
        scanf("%d %d %d", &N, &M, &A);
        int x1=0, y1=0, x2, y2, x3, y3;
        bool find = 0;
        for(x2=0;x2<=N;x2++)for(x3=0;x3<=N;x3++)
        for(y2=0;y2<=M;y2++)for(y3=0;y3<=M;y3++)
        {
            int s = x2*y3-y2*x3;     
            if (s<0)s=-s;
            if (s==A) {
                find = 1;
                goto end;    
            } 
        }   
        end:
        printf("Case #%d: ", cs);
        if (find) {
            printf("%d %d %d %d %d %d\n", x1, y1, x2, y2, x3, y3);    
        }  else{
            printf("IMPOSSIBLE\n");    
        }
    }
  
    return 0;    
}
