#include <stdlib.h>
#include <stdio.h>
#include <map>

#define MYDEBUG			0

using std::map;
using std::pair;

char G[35][105];
//char S[30][100];

//NOTE: The pair map will NOT change!!!

/*
map table:
		a	y
		b	h
		c	e
		d	s
		e	o
		f	c
		g	v
		h	x
		i	d
		j	u
		k	i
		l	g
		m	l
		n	b
		o	k
		p	r
		q	z
		r	t
		s	n
		t	w
		u	j
		v	p
		w	f
		x	m
		y	a
		z	q
*/


//char strbuf[100];
int T;
map<char, char> stmap;		//convert table.

int main(void)
{
	int i, j;
	char c, *pc;

	FILE *fp;

	//output file
	fp = fopen("result.txt", "w");

	stmap.insert(pair<char, char>('a','y'));
	stmap.insert(pair<char, char>('b','h'));
	stmap.insert(pair<char, char>('c','e'));
	stmap.insert(pair<char, char>('d','s'));
	stmap.insert(pair<char, char>('e','o'));
	stmap.insert(pair<char, char>('f','c'));
	stmap.insert(pair<char, char>('g','v'));

	stmap.insert(pair<char, char>('h','x'));
	stmap.insert(pair<char, char>('i','d'));
	stmap.insert(pair<char, char>('j','u'));
	stmap.insert(pair<char, char>('k','i'));
	stmap.insert(pair<char, char>('l','g'));
	stmap.insert(pair<char, char>('m','l'));
	stmap.insert(pair<char, char>('n','b'));

	stmap.insert(pair<char, char>('o','k'));
	stmap.insert(pair<char, char>('p','r'));
	stmap.insert(pair<char, char>('q','z'));
	stmap.insert(pair<char, char>('r','t'));
	stmap.insert(pair<char, char>('s','n'));
	stmap.insert(pair<char, char>('t','w'));
	stmap.insert(pair<char, char>('u','j'));

	stmap.insert(pair<char, char>('v','p'));
	stmap.insert(pair<char, char>('w','f'));
	stmap.insert(pair<char, char>('x','m'));
	stmap.insert(pair<char, char>('y','a'));
	stmap.insert(pair<char, char>('z','q'));

	stmap.insert(pair<char, char>((char)32, (char)32));	//space

	freopen("A-small-attempt3.in", "r", stdin);

	scanf("%d", &T);
#if MYDEBUG
	printf("T = %d \n", T);
#endif

	gets(G[0]);
	for(i = 0; i < T; i++)
	{
		gets(G[i]);
		fprintf(fp, "Case #%d: ", i + 1);

#if MYDEBUG
		printf("Original:\n");
		printf("%s\n", G[i]);
		printf("Converted:\n");
#endif

		pc = G[i];
		for(j = 0; j < 105; j++)
		{
			c = *pc++;
			//if((c != '\n') && (c != EOF))
			if(c != '\0')
			{
				fprintf(fp, "%c", stmap[c]);
			}
		/*	else if(c == ' ')
			{
				printf(" ");
			}	*/
			else
			{
				fprintf(fp, "\n");
				break;
			}
		}
	}
	

	//printf("%c\n", stmap['a']);

	fclose(fp);
	fclose(stdin);
	

	return 0;
}