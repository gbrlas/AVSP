/*
 * =====================================================================================
 *
 *       Filename:  prob1.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Thursday 03 September 2009 09:37:31  IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Rohit Agrawalla (akrohit), akrohit@iitk.ac.in
 *        Company:  Personal
 *
 * =====================================================================================
 */

#include <stdio.h>

int no_words, no_letters, no_queries;

char dict[5000][16];

int main()
{
	int i, j, count;
	char query[501];
	scanf("%d%d%d", &no_letters, &no_words, &no_queries);
	for(i = 0; i < no_words; i++)
	{
		scanf("%s", dict[i]);
	}
	for(i=0;i<no_queries;i++)
	{
		count=0;
		scanf("%s", query);
		for(j=0; j < no_words; j++)
			if(match(query, dict[j]))
				count++;
		printf("Case #%d: %d\n", i+1, count);
	}
	return 0;
}

int match(char *query, char *word)
{
	int i, count = 0;
	for(i = 0; i < no_letters; i++)
	{
		if(word[i] == query[count])
		{
			count++;
			continue;
		}
		else if(query[count] == '(')
		{
			count++;
			while((word[i] != query[count]) && (query[count] != ')')) count++;

			if(query[count] == ')')
				return 0;
			else
			{
				while(query[count] != ')')count++;
				count++;
				continue;
			}
		}
		else
			return 0;
	}
	if(i==no_letters)
		return 1;
	else
		return 0;
}
