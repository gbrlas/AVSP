#include <cstdio>
#include <cstdlib>
using namespace std;
const unsigned long long table[30]={2,4,8,16,32,64,128,256,512,1024,
2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,
2097152,4194304,8388608,16777216,33554432,67108864,134217728,
268435456,536870912,1073741824};
int n, k, t;
int i, j;

int main(){
    //freopen("A-large.in", "r", stdin);
    //freopen("A-large.out", "w", stdout); 
    scanf("%d", &t);
    for (i = 1; i <= t; ++i){
        scanf("%d%d", &n, &k);
        ++k;
        if (k % table[n - 1] == 0) printf("Case #%d: ON\n", i);
        else printf("Case #%d: OFF\n", i);
    }
    return 0;
}
