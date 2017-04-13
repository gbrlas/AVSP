#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int T, A, B;
void strrev(char *p)
{
  char *q = p;
  while(q && *q) ++q;
  for(--q; p < q; ++p, --q)
    *p = *p ^ *q,
    *q = *p ^ *q,
    *p = *p ^ *q;
}

int isPalindrome(int x)
{
	char a[10000], b[10000];	
	sprintf(a,"%d",x);
	strcpy(b, a);
	strrev(a);
	if (strcmp(a, b) == 0)
		return 1;
	else
		return 0;	
}
int main()
{
	freopen("C-small-attempt0.in", "rt", stdin);
	freopen("C-small-attempt0.out", "wt", stdout);
	
	scanf ("%d", &T);
	for (int t = 0; t < T; t++)
	{
		scanf ("%d %d", &A, &B);
		int count = 0;
		for (int i = A; i <= B; i++)
		{
			if (isPalindrome(i))
			{
				int root = sqrt(i);
				if (root*root == i)
					if (isPalindrome((int)root))
						count++;
			}
		}
		
		printf ("Case #%d: %d\n", t+1, count);
	}
	
	return 0;
}