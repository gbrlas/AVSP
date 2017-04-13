#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>

using namespace std;

int t, n, m;
int a[100][100];
bool ok1, ok2;

int main()
{
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
  
  scanf("%d\n", &t);
  
  for (int l = 0; l < t; l++)
  {
    cout << "Case #" << l + 1 << ": ";
    
    cin >> n >> m;
    
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        scanf("%d", &a[i][j]);
        
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
      {
        ok1 = 1;
        
        for (int l = 0; l < m; l++)
          if (a[i][l] > a[i][j])
            ok1 = 0;
            
        ok2 = 1;
        
        for (int l = 0; l < n; l++)
          if (a[l][j] > a[i][j])
            ok2 = 0;
            
        if (!ok1 && !ok2)
        {
          printf("NO\n");
          goto exit;
        }
      }
      
    printf("YES\n");
    exit:;
  }
}
