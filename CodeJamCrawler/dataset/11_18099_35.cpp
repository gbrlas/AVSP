#include <stdio.h>

int t, n, a[10000];
int max, left, right;
int sumLeft, sumRight;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    
    scanf("%d", &t);
    int k = 1;
    while(t--)
    {
    scanf("%d", &n);
     for (int i = 0; i < n; ++i)
         scanf("%d", &a[i]);

         max = -1;
     for (int i = 1; i < (1<<n)-1; ++i)
     {
         left = right = 0;
         sumLeft = sumRight = 0;
         for (int j = 0; j < n; ++j)
         {
             //printf("%d", (((1<<j) & i) > 0));
             if (((1<<j) & i) > 0)
             {

                left = left ^ a[j];
                 sumLeft += a[j];
             }
             else
             {
                 right = right ^ a[j];
                 sumRight += a[j];
             }
         }
         //printf("%d %d %d %d\n", sumLeft, sumRight, left, right);
         if (right == left)
         {
                       if (max < sumRight)
                          max = sumRight;
                       if (max < sumLeft)
                          max = sumLeft;

         }

     }
         
     printf("Case #%d: ", k++);
     if (max == -1)
        printf("NO\n");
     else
         printf("%d\n", max);
    }
    return 0;
}
