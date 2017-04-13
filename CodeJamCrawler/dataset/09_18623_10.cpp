//Qualification Round 2009
//Problem A

#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <string>
using namespace std;

void JooPoo()
{
	//freopen("test.in", "r", stdin);
	freopen("e:\\Program Files\\System\\Desktop\\A-small-attempt1.in", "r", stdin);
	freopen("e:\\Program Files\\System\\Desktop\\A-small-practice.out", "w", stdout);
	//freopen("e:\\Program Files\\System\\Desktop\\A-large-practice.in", "r", stdin);
	//freopen("e:\\Program Files\\System\\Desktop\\A-large-practice.out", "w", stdout);
}

#define BASE_LETTER 'a'
#define MAX_TREE 3500000
#define MAX_BRANCH 26

struct{
	int next[MAX_BRANCH];
	int c[MAX_BRANCH];
	int flag; 
}trie[MAX_TREE];

struct node
{
	bool flag;
	int cnt;
	char ch[30];
}letter[15];

int cnt, res;
char word[20];
int now;

void init()
{
	now = 0;
	memset(&trie[now], 0, sizeof(trie[now]));
	now ++;
}

int add ()
{
	memset(&trie[now], 0, sizeof(trie[now]));
	return now++;
}

int insert( char *str)
{
	int pre = 0, addr;
	while( *str != 0 )
	{
		addr = *str - BASE_LETTER;
		if( !trie[pre].next[addr] )
			trie[pre].next[addr] = add();

		trie[pre].c[addr]++;
		pre = trie[pre].next[addr];
		str ++;
	}
	trie[pre].flag = 1;

	return pre;
}

int search( char *str )
{
	int pre = 0, addr;
	while( *str != 0 )
	{
		addr = *str - BASE_LETTER;
		if ( !trie[pre].next[addr] )
			return 0;
		pre = trie[pre].next[addr];
		str ++;
	}
	if( !trie[pre].flag )
		return 0;

	return pre;
}

void DFS(int j, int pre)
{
	if (j == cnt)
	{
		res++;
		return;
	}
	int addr;
	if (letter[j].flag == true)
	{	
		for (int i=0; i<letter[j].cnt; i++)
		{	
			addr = letter[j].ch[i] - BASE_LETTER;
			if ( !trie[pre].next[addr] )
				continue;
			DFS(j+1, trie[pre].next[addr]);
		}
	}
	else
	{
		for (int i=0; i<letter[j].cnt; i++)
		{
			addr = letter[j].ch[i] - BASE_LETTER;
			if ( !trie[pre].next[addr] )
				return;
			pre = trie[pre].next[addr];
		}
		DFS(j+1, pre);
	}
}

int main()
{
	JooPoo();
	
	int L, D, N, i, j;
	scanf("%d%d%d", &L, &D, &N);

	init();
	for (i=0; i<D; i++)
	{
		scanf("%s", word);
		insert(word);
	}

	char ch=1;
	getchar();
	for (i=0; i<N; i++)
	{
		cnt = 0;
		for (j=0; j<L; j++) 
		{
			letter[j].cnt = 0;
			letter[j].flag = false;
		}
		while ((ch=getchar()) && ch!='\n')
		{
			if (ch == ')') letter[cnt].flag = true;
			if ((ch==')'||ch=='(') && letter[cnt].cnt!=0) cnt++;
			else if (ch==')'||ch=='(') continue;
			else
			{
				letter[cnt].ch[letter[cnt].cnt++] = ch;
			}
		}
		if (letter[cnt].cnt != 0) cnt++;
		res = 0;
		DFS(0, 0);
		printf("Case #%d: %d\n", i+1, res);
	}
}