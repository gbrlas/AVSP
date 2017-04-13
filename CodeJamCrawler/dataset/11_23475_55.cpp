#include <stdio.h>
#include <stdlib.h>
#define MAXC 36
#define MAXD 28
#define MAXN 101

char equiv[MAXC][3];
char oppos[MAXD][2];

/* Return 0 if there is no opposite */
char seek_oppos(char E, int opc)
{
	int i;
	for(i=0; i < opc; i++)
	{
		if(oppos[i][0] == E)
			return oppos[i][1];
		if(oppos[i][1] == E)
			return oppos[i][0];
	}
	return 0;
}

/* Return 0 if there is no equivalence */
char seek_equiv(char A, char B, int eqc)
{
	int i;
	for(i=0; i < eqc; i++)
	{
		if((A == equiv[i][0] && B == equiv[i][1]) || (A == equiv[i][1] && B == equiv[i][0]))
			return equiv[i][2];
	}
	return 0;
}

void mk_elem_list(int eqc, int opc, char *el, int elc, char *str)
{
	int lc = 1;
	int i, j;
	char equiv_elem, oppos_elem;
	char lst[elc];
	
	lst[0] = el[0];
	for(i=1; i < elc; i++)
	{
		equiv_elem = seek_equiv(lst[lc-1], el[i], eqc);
		if(equiv_elem)
		{
			lst[lc-1] = equiv_elem;
		}
		else
		{
			oppos_elem = seek_oppos(el[i], opc);
			if(oppos_elem)
			{
				for(j=0; j < lc; j++)
					if(lst[j] == oppos_elem)
					{
						lc = 0;
						i++;
						break;
					}
			}
			lst[lc] = el[i];
			lc++;
		}
	}
	str[0] = '[';
	j = 1;
	for(i=0; i < lc-1; i++)
	{
		str[j] = lst[i];
		str[j+1] = ',';
		str[j+2] = ' ';
		j += 3;
	}
	if(lc > 0)
	{
		str[j] = lst[lc-1];
		str[j+1] = '\0';
	}
	else
		str[j] = '\0';

}

int main(int argc, char *argv[])
{
	
	char elem[MAXN];
	int i, j, N, T, C, D;
	char list[MAXN*4];
	
	fscanf(stdin, "%i", &T);
	for(i=0; i < T; i++)
	{
		fscanf(stdin, "%i", &C);
		for(j=0; j < C; j++)
		{
			fscanf(stdin, " %3c", equiv[j]);
		}
		fscanf(stdin, "%i", &D);
		for(j=0; j < D; j++)
		{
			fscanf(stdin, " %2c", oppos[j]);
		}
		fscanf(stdin, "%i", &N);
		fscanf(stdin, "%s", elem);
		mk_elem_list(C, D, elem, N, list);
		printf("Case #%i: %s]\n", i+1, list);
	}
	
	return 0;
}
