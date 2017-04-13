#include <stdio.h>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <string.h>

using namespace std;

#define LMAX 19
#define NMAX 513
#define DMAX 5012

char h[NMAX][LMAX];
int L, D, N;
int query[LMAX][30];
int grupe, ans;
string a;

int toInt(char c)
{
	return c-'a';
}

void read()
{
	scanf("%d %d %d\n", &L, &D, &N);
	
	for(int i = 0, j; i < D; ++i)
	{
		scanf("%s", h[i]);
	}
	
	memset(query, 0x3f3f3f3f, sizeof(query));
	
	char line[9000];
	for(int i = 0, z, q, j; i < N; ++i)
	{
		ans = 0;
		grupe = 0;
		scanf("%s\n", line);

		for(j = 0, z = 0; j < L; ++j)
		{
			
			if(line[z] == '(')
			{
				++z;
				while(line[z] != ')')
				{
	//				printf("%d%c", j, line[z]);
					query[j][ toInt(line[z]) ] = i;
					++z;
				}
				
				++z;
	//			printf(" ");
			}
			else
			{
				//printf("%d%c ", j, line[z]), ++z;
				query[j][ toInt(line[z]) ] = i, ++z;
			}
		}


		for(z = 0; z < D; ++z)
		{
			++ans;
			for(q = 0; q < L; ++q)
				if(query[q][ toInt(h[z][q]) ] != i)
				{
					--ans;
					break;
				}
	
		}
		
		printf("Case #%d: %d\n", i+1, ans);
	}	
}
		


int main()
{
	freopen("alien.in", "r", stdin);
	freopen("alien.out", "w", stdout);

	read();
	

	return 0;
}


	






























