#include <stdio.h>
#include <string.h>

char words[5010][20];
int pattern[20][32];

int main()
{
	FILE* fin = fopen("in.txt", "r");
	FILE* fout = fopen("out.txt", "w");
	int L, D, N;
	fscanf(fin, "%d %d %d", &L, &D, &N);
	for(int i = 0; i < D; ++i)
		fscanf(fin, "%s", words[i]);
	for(int i = 0; i < N; ++i)
	{
		memset(pattern, 0, sizeof(pattern));
		char pat[1024];
		fscanf(fin, "%s", pat);
		int pat_len = strlen(pat), token = 0;
		for(int j = 0; j < pat_len; )
		{
			if(pat[j] == '(')
			{
				++j;
				while(pat[j] != ')')
				{
					pattern[token][pat[j] - 'a'] = 1;
					++j;
				}
				++j;
			}
			else pattern[token][pat[j++] - 'a'] = 1;
			++token;
		}
		int res = 0;
		for(int j = 0; j < D; ++j)
		{
			bool can = true;
			for(int k = 0; k < L; ++k)
				if(pattern[k][words[j][k] - 'a'] != 1)
				{
					can = false;
					break;
				}
			if(can) ++res;
		}
		fprintf(fout, "Case #%d: %d\n", i + 1, res);
	}

	return 0;
}