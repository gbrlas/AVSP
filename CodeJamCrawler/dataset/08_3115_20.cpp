#include <algorithm>
#include <vector>

using namespace std;

int M, V;

const int MAXN = 65536;
const int INF = 100000000;

struct TNode
{
    int gate, change,value;    
} tree[MAXN];

int opt[MAXN][2];

int solve(int t, int v)
{
    if (opt[t][v] >= 0) return opt[t][v];
    int &ret = opt[t][v];
    ret = INF;
    if (t > (M-1)/2) {
         if (v == tree[t].value) ret = 0;
         else ret = INF;    
    } else {
        if (v == 0) {
            int _and = INF;
            _and = min(_and, solve(t*2, 0)+solve(t*2+1, 0));
            _and = min(_and, solve(t*2, 0)+solve(t*2+1, 1));
            _and = min(_and, solve(t*2, 1)+solve(t*2+1, 0));
            int add = 0;
            if (tree[t].gate == 1) {
                add = 0;            
            } else if (tree[t].change) add = 1;
            else add = INF;
            _and += add;
            ret = min(ret, _and);  
            
            int _or = INF;
            _or = min(_or, solve(t*2, 0)+solve(t*2+1, 0));
            if (tree[t].gate == 0)  add =0;
            else if (tree[t].change==1) add =1;
            else add=INF;
            _or+=add;
            ret = min(ret, _or);
        } else {
            int _and = INF;
            _and = min(_and, solve(t*2, 1)+solve(t*2+1, 1));
            int add = 0;
            if (tree[t].gate == 1) {
                add = 0;            
            } else if (tree[t].change) add = 1;
            else add = INF;
            _and += add;
            ret = min(ret, _and);  
            
            int _or = INF;
            _or = min(_or, solve(t*2, 0)+solve(t*2+1, 1));
            _or = min(_or, solve(t*2, 1)+solve(t*2+1, 0));
            _or = min(_or, solve(t*2, 1)+solve(t*2+1, 1));
            if (tree[t].gate == 0)  add =0;
            else if (tree[t].change==1) add =1;
            else add=INF;
            _or += add;
            ret = min(ret, _or);
        }   
    }
    return ret;
}

int main()
{
    freopen("d:\\in.txt", "r", stdin);
    freopen("d:\\out.txt", "w", stdout);
    int N;
    scanf("%d", &N);
    for (int cs = 1;cs<=N;cs++) {
        scanf("%d %d", &M, &V);
        for (int i=1;i<=(M-1)/2;i++) {
            scanf("%d %d", &tree[i].gate, &tree[i].change);    
        }       
        for (int i=(M-1)/2+1;i<=M;i++) {
            scanf("%d", &tree[i].value);    
        }
        memset(opt, -1, sizeof(opt));
        int ret = solve(1, V);
        printf("Case #%d: ", cs);
        if (ret == INF) printf("IMPOSSIBLE\n");
        else printf("%d\n", ret); 
    }   
  
    return 0;    
}
