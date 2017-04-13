#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*
The first line of the input file contains the number of cases, N. N test cases follow. 

Each case begins with M and V. M represents the number of nodes in the tree and will be odd to ensure all nodes have 0 or 2 children. V is the desired value for the root node, 0 or 1. 

M lines follow describing each of the tree's nodes. The Xth line will describe node X, starting with node 1 on the first line. 

The first (M?1)/2 lines describe the interior nodes. Each line contains G and C, each being either 0 or 1. If G is 1 then the gate for this node is an AND gate, otherwise it is an OR gate. If C is 1 then the gate for this node is changeable, otherwise it is not. Interior node X has nodes 2X and 2X+1 as children. 

The next (M+1)/2 lines describe the leaf nodes. Each line contains one value I, 0 or 1, the value of the leaf node. 

To help visualize, here is a picture of the tree in the first sample input.

*/

const int INF = 1000000000;
const int maxn = 100001;

int n, v;
int f[maxn][2];
int leaf[maxn];
int c[maxn], g[maxn];

void solve()
{
     for (int i = 1; i <= n; i++) f[i][1] = f[i][0] = INF;
     for (int i = n; i >= 1; i--) {
         if (i > (n - 1) / 2) { f[i][leaf[i]] = 0; f[i][1 - leaf[i]] = INF; continue; }
         int s1 = i * 2, s2 = i * 2 + 1;
         for (int a = 0; a <= 1; a++)
           for (int b = 0; b <= 1; b++) if (f[s1][a] != INF && f[s2][b] != INF) {
               if (g[i] == 1) {
                     f[i][a & b] = min(f[i][a & b], f[s1][a] + f[s2][b]);
                     if (c[i]) 
                     f[i][a | b] = min(f[i][a | b], f[s1][a] + f[s2][b] + 1);   
               }
               if (g[i] == 0) {
                     f[i][a | b] = min(f[i][a | b], f[s1][a] + f[s2][b]);
                     if (c[i])
                     f[i][a & b] = min(f[i][a & b], f[s1][a] + f[s2][b] + 1);
               }
           }
     }
}

int main()
{
   // freopen("input.txt", "r", stdin);
//    freopen("A-large.in", "r", stdin);
    freopen("A-small-attempt0.in", "r", stdin);    
    freopen("a.out", "w", stdout);
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) { 
        memset(f, 0, sizeof(f));
        cin >> n >> v;
        for (int i = 1; i <= (n - 1) / 2; i++) {
            cin >> g[i] >> c[i];            
        }
        for (int i = 1; i <= (n + 1) / 2; i++) cin >> leaf[i + (n - 1) / 2];
        cout << "Case #" << test << ": "; 
        solve();
        if (f[1][v] == INF) cout << "IMPOSSIBLE" << endl;
        else cout << f[1][v] << endl;
    }
//    while (1);
    return 0;
}
