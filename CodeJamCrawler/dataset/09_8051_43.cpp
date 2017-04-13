# include <iostream>

using namespace std;

char dict[20][5010], in[60][510];
int L, D, N;

void parse(char* s)
{
	int i, j;

	for(i = j = 0; s[i]; i++, j++)
	{
		if(s[i] != '(')
		{
			in[j][0] = s[i];
			in[j][1] = '\0';
		}

		else
		{
			int k = 0;
			i++;
			while(s[i] != ')')
			{
				in[j][k++] = s[i++];
			}

			in[j][k] = '\0';
		}
	}
}

bool isin(char c, char* s)
{
	int i;

	for(i = 0; s[i]; i++)
		if(c == s[i]) return true;
	return false;
}

int main()
{
	freopen("a-s.in", "r", stdin);
	int i, j, k, cnt, t = 1;;
	char str[15000];
	bool flag;
	freopen("a-s.out", "w", stdout);

	while(scanf("%d %d %d", &L, &D, &N) == 3)
	{
		for(i = 0; i < D; i++)
			scanf("%s", dict[i]);

		for(i = 0; i < N; i++)
		{
			scanf("%s", str);
			parse(str);
			cnt = 0;

			for(j = 0; j < D; j++)
			{
				flag = true;

				for(k = 0; k < L; k++)
				{
					if(!isin(dict[j][k], in[k]))
					{
						flag = false;
					}
				}

				if(flag) cnt++;
			}
			printf("Case #%d: %d\n", t++, cnt);
		}
	}

	return 0;
}
