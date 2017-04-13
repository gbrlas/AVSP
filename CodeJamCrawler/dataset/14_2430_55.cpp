#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

main()
{
  int TC, T = 0;
  int N;
  vector<double> a, b;
  scanf("%d", &TC);
  while (T++ < TC)
  {
    scanf("%d", &N);
    
    a.clear();
    for (int i = 0; i < N; i++)
    {
      double temp;
      scanf("%lf", &temp);
      a.push_back(temp);
    }
    
    b.clear();
    for (int i = 0; i < N; i++)
    {
      double temp;
      scanf("%lf", &temp);
      b.push_back(temp);
    }
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    int cheating = 0;
    int fair = 0;
    for (int i = 0, j = 0; i < N; i++)
    {
      if (a[i] > b[j])
      {
        cheating++;
        j++;
      }
    }
    
    for (int i = 0, j = 0; i < N; i++)
    {
      while (j < N && a[i] > b[j])
      {
        j++;
      }
      
      if (j == N)
      {
        fair = N - i;
        break;
      }
      
      j++;
    }
    
    printf("Case #%d: %d %d\n", T, cheating, fair);
  }
}