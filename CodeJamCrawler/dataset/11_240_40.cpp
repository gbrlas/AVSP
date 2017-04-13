#include <cstdlib>
#include <cstdio>
#include <queue>
#define lli long long int
using namespace std;
int main()
{
    FILE *in = fopen("B-small-attempt2.in","r");
    FILE *out = fopen("out.txt","w+");
    int t;
    fscanf(in,"%d", &t);
 //   scanf("%d", &t);
    for(int tt = 1;tt <= t;tt++){
        int l, n, c;
        lli ti, walk = 0, total = 0;
        fscanf(in,"%d %I64d %d %d", &l, &ti, &n, &c);
    //    scanf("%d %I64d %d %d", &l, &ti, &n, &c);
        lli ans = ti;
        int d[c];
        priority_queue<int> q;
        for(int i = 0;i < c;i++){
            fscanf(in,"%d", &d[i]);
    //        scanf("%d", &d[i]);
        }
        int add = 0, dis;
        for(int i = 0;i < n;i++){
            if(ti >= 2 * d[add]){
                ti -= 2 * d[add];
                walk += d[add];
            }else{
                walk += ti / 2;
                dis = d[add] - ti / 2;
                q.push(dis);
                ti -= (ti / 2) * 2;
            }
            total += d[add];
            add = (add + 1) % c;
        }
        if(ti > 1){
            fprintf(out,"Case #%d: %I64d\n",tt, walk * 2);
      //      printf("Case #%d: %I64d\n",tt, walk * 2);
        }else{
            while(l--){
                ans += q.top();
                walk += q.top();
                q.pop();
            }
            ans += (total - walk) * 2;
      //      printf("Case #%d: %I64d\n",tt, ans);
            fprintf(out,"Case #%d: %I64d\n",tt, ans);
        }
    }
 //   system("PAUSE");
    return 0;
}
