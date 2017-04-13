#include <cstdio>
#include <string>
using namespace std;
char C[100][3],
     D[100][2];

int main()
{
	int T;
	scanf("%d", &T);
	for(int t = 1; t <= T; t++)
	{
		int c, d, n;
		char N[105];
		scanf("%d", &c);		
		for(int i = 0; i < c; i++) scanf(" %s", C[i]);
		scanf("%d", &d);
		for(int i = 0; i < d; i++) scanf(" %s", D[i]);
		scanf("%d %s", &n, N);
		
		int bylo[200];
		for(int i = 'A'; i <= 'Z'; i++) bylo[i] = 0;

		int pocz = 0;
		bylo[N[0]]++;
		for(int i = 1; i < n; i++)
		{
			bylo[N[i]]++;
			if(i <= pocz)
				continue;
			bool f = 1;
			while(f)
			{
				f = 0;
				for(int j = 0; j < c; j++)
					if((C[j][0] == N[i] && C[j][1] == N[i-1])
					|| (C[j][0] == N[i-1] && C[j][1] == N[i]))
					{
						bylo[N[i]]--;
						bylo[N[i-1]]--;
						bylo[C[j][2]]++;
						f = 1;
						N[i] = C[j][2];
						pocz++;
						for(int k = i-1; k >= pocz; k--)
							N[k] = N[k-1];
					}
			}
			for(int j = 0; j < d; j++)
			{
				if((bylo[D[j][0]] && D[j][1] == N[i])
				|| (bylo[D[j][1]] && D[j][0] == N[i]))
				{
					for(int k = 'A'; k <= 'Z'; k++)
						bylo[k] = 0;
					pocz = i+1;
				}
			}

		}
		printf("Case #%d: [", t);
		for(int i = pocz; i < n; i++)
		{
			printf("%c", N[i]);
			if(i < n-1)
				printf(", ");
		}
		printf("]\n");
	}
	return 0;
}
