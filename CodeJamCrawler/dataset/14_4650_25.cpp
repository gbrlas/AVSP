/**
 * Tournament: Google Code Jam 2014 - Round 1
 * Task: A
 * Author: Vasil Sarafov
 * 12.04.2014, Varna, Bulgaria
 * **/
 
#include <iostream>
#include <cstdio>
#include <fstream>
#include <cstring>
#define space " "
#define ln "\n"
using namespace std;

const int MAXN = (int)(1 << 4);

int checker;
int cnt[MAXN + 10], tmp, ret;
int testCases, answerFirst, answerSecond;

inline void countNumbers(int answer)
{
	for(int i = 1; i <= 4; i++)
	{
		for(int j = 1; j <= 4; j++)
		{
			scanf("%d", &tmp);
			if(i == answer) cnt[tmp] ++;
			else continue;
		}
	}
	
	return;
}

int main(int argc, char **argv)
{
	freopen("A.in", "rt", stdin);
	freopen("A.out", "wt", stdout);
	
	scanf("%d", &testCases);
	
	for(int test = 1; test <= testCases; test++)
	{
		
		checker = 0; ret = 0;
		memset(cnt, 0, sizeof(cnt));
		
		scanf("%d", &answerFirst);
		countNumbers(answerFirst);
		
		scanf("%d", &answerSecond);
		countNumbers(answerSecond);
		
		for(int i = 1; i <= MAXN; i++)
		{
			if(cnt[i] == 2)
			{
				checker ++;
				ret = i;
			}
		}
		
		if(checker == 1) printf("Case #%d: %d\n", test, ret);
		else if(checker > 1) printf("Case #%d: Bad magician!\n", test);
		else printf("Case #%d: Volunteer cheated!\n", test);
	}
	
	return 0;
}
