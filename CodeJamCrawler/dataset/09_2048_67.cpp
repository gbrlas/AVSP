#include <stdio.h>
#include <string.h>

#define MAX 11814485

int goods[MAX+1];

int iterate(int n, int b)
{
  int s = 0;
  while(n > 0)
  {
    s += (n%b)*(n%b);
    n /= b;
  }
  return s;
}

int ishappy(int n, int b)
{
  int m = n;
  int mask = (1<<b);
  do
  {
    n = iterate(n, b);
    if (goods[n] & mask) return 1;
    m = iterate(iterate(m, b), b);
  } while(m != n);
  return 0;
}

int main()
{
  int t;
  char buf[1024];
  
  goods[1] = (1<<11)-2;
  for (int n = 2; n <= MAX; n++)
  {
    for (int b=2; b<=10; b++)
    {
      int mask = (1<<b);
      if (ishappy(n, b)) goods[n] |= mask;
    }
  }
  scanf("%d ", &t);
  for (int c=1; c<=t; c++)
  {
    int mask = 0;
    char *p, *q;
    int x;
    
    gets(buf);
    strcat(buf, " ");
    for (q = p = buf; *p; )
    {
      p++;
      if (*p == ' ')
      {
        int b;
        *p = 0;
        sscanf(q, "%d", &b);
        mask |= (1<<b);
        q = ++p;
      }
    }
    
    for (int x = 2; x <= MAX; x++)
      if ((goods[x] & mask) == mask)
      {
        printf("Case #%d: %d\n", c, x);
        break;
      }
  }
  return 0;
}
