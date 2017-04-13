#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char instr[5010][20];
char pattern[510][450];
char machine[20][128];

int gen_machine(int pindex)
{
	char *pat=pattern[pindex];
	int i, len=strlen(pat), state=0,tag=0;
	for(i=0; i<len; i++)
	{
		if(pat[i]>='a'&&pat[i]<='z')
		{
			if(tag==1)
				machine[state][pat[i]]=1;
			else
			{	machine[state][pat[i]]=1;
				state++;
			}

		}
		else if(pat[i]=='(')
		{
			tag=1;
		}
		else if(pat[i]==')')
		{
			state++;
			tag=0;
		}
	}
	return 0;
}

int run_machine(int strindex)
{
	int i,len;
	char *ins=instr[strindex];
	len=strlen(ins);
	for(i=0; i<len&&machine[i][ins[i]]; i++);
	if(i>=len)
		return 1;
	return 0;
}

int get_res(int pindex, int d)
{
	int i, res=0;
	memset(machine, 0, sizeof(char)*20*128);
	gen_machine(pindex);
	for(i=0; i<d; i++)
		res+=run_machine(i);
	return res;
}

int main(int argc, char **argv)
{
	int i,l,d,n,res;
	scanf("%d%d%d", &l, &d, &n);
	memset(instr, 0, sizeof(char)*5010*20);
	memset(pattern, 0, sizeof(char)*510*450);
	if(l<1||d<1||n<1)
		return 1;
	for(i=0; i<d; i++)
		scanf("%s", instr[i]);
	for(i=0; i<n; i++)
		scanf("%s", pattern[i]);
	for(i=0; i<n; i++)
	{
		res=get_res(i,d);
		printf("Case #%d: %d\n",i+1, res);
	}
	return 0;
}
