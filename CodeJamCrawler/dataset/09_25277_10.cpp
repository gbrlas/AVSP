#include <stdio.h>
#include <string.h>

#define MAX_LETTERS	26
#define MAX_WORDS	5000
#define MAX_CASES	500
#define MAX_LEN		1024
#define MAX_CHARS	26

//#define DBGOUT	printf
void DBGOUT(...) { }


// return matched=1, not matched=0
int matched(char* word, char** pat_list)
{
	int passed = 0;

	DBGOUT("Word match check: %s\n", word);

	for (int i = 0, len = strlen(word); i < len; i++)
	{
		DBGOUT("check %c among %s..", word[i], pat_list[i]);
		if (strchr(pat_list[i], word[i]))
		{
			DBGOUT("OK\n");
			passed++;
		}
		else
		{
			DBGOUT("Fail\n");
			return 0;
		}
	}

	return 1;
}

int pattern_analysis(char* pattern, char** pat_list)
{
	int 	len = strlen(pattern);
	char	token[MAX_CHARS] = "";
	int		token_len;

	int i, idx, mode;
	idx = 0;
	mode = 0;	
	for (i = 0; i < len; i++)
	{
		if (pattern[i] == '(')
		{
			mode = 1;
			token[0] = 0x0;
			token_len = 0;
		}
		else if (pattern[i] == ')')
		{
			mode = 0;
			token[token_len] = 0x0;
			pat_list[idx] = new char [MAX_CHARS];
			strcpy(pat_list[idx], token);
	 		idx++;
		}
		else 
		{
			if (mode == 1)
			{
				token[token_len++] = pattern[i];
			}
			else 
			{
				pat_list[idx] = new char [2];
				*pat_list[idx] = pattern[i];
				*(pat_list[idx] + 1) = 0x0;
				idx++;
			}
		}
	}

	return idx;
}

int match_count(char** pWords, int word_cnt, char* pattern)
{
	int	i;
	int count = 0;
	int pat_list_cnt = 0;

	char	*pat_list[MAX_LETTERS];
	memset(pat_list, 0, sizeof(char*) * MAX_LETTERS);
	pat_list_cnt = pattern_analysis(pattern, pat_list);

	DBGOUT("pat_list_cnt=%d\n", pat_list_cnt);
	for (i = 0; i < pat_list_cnt; i++)
		DBGOUT("PATTERN%d: [%s]\n", i+1, pat_list[i]);

	for (i = 0; i < word_cnt; i++)
	{
		if (matched(pWords[i], pat_list))
		{
			DBGOUT("Matched:%s\n", pWords[i]);
			count++;	
		}
	}

	for (i = 0; i < pat_list_cnt; i++)
		if (pat_list[i])
			delete [] pat_list[i];

	return count;
}

int main()
{
	int	letters;
	int words;
	int tcases;
	char	**pWords;

	scanf("%d %d %d", &letters, &words, &tcases);

	pWords = new char* [words + 1];
	for (int i = 0; i < words; i++)
	{
		pWords[i] = new char [MAX_LETTERS + 1];
		scanf("%s", pWords[i]);
	}

	char bufCase[MAX_LEN] = "";
	int	 cnt;

	for (int i = 0; i < tcases; i++)
	{
		scanf("%s", bufCase);
		cnt = match_count(pWords, words, bufCase);
		printf("Case #%d: %d\n", i + 1, cnt);
	}
}
