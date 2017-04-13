#include <stdio.h>

int main()
{
  int T;
  scanf("%d", &T);
  for(int t=1; t<=T; t++)
  {
    char possible[17] = { 0 };
    for (int q=0; q<2; q++)
    {
      int ans;
      scanf("%d", &ans);
      for (int i=1; i<=4; i++)
        for (int j=0; j<4; j++)
        {
          int x;
          scanf("%d", &x);
          if (i == ans)
            possible[x]++;
        }
      
    }
    int twos = 0;
    int bt = 0;
    for (int i=1; i<=16; i++)
      if (possible[i] == 2)
      {
        bt = i;
        twos++;
      }
    printf("Case #%d: ", t);
    if (twos == 0)
      printf("Volunteer cheated!");
    else if (twos >= 2)
      printf("Bad magician!");
    else
      printf("%d", bt);
    printf("\n");
  }
}
