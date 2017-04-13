#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int t;
char s[30];
int a[30];
int n;

char swap(int i, int j)
{
	char aux;
	aux = s[i];
	s[i] = s[j];
	s[j] = aux;
}

int main()
{
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);

	scanf("%d", &t);
	int i = 1;
	while(i <= t)
	{
		scanf("%s", s);
		n = strlen(s);
		if(next_permutation(s, s+n))
			printf("Case #%d: %s\n", i, s);
		else
		{
			s[n++] = '0';
			s[n] = NULL;
			sort(s, s+n);
			for(int j = 0; j < n; ++j)
				if(s[j] != '0')
				{
					swap(0, j);
					break;
				}
                        printf("Case #%d: %s\n", i, s);	
		}
		i++;
	}
	return 0;
}

