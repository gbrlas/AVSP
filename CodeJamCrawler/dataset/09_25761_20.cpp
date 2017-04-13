#include<stdio.h>
#include<string.h>
#include<memory.h>
#include<stdlib.h>


#define NMAX 500

char input[NMAX+1];
char *welcome = "welcome to code jam";
int wel_len;
FILE *fp;

int cmp(int,int,int);

int main()
{
	int N;
	int result;
	int len;
	int nCase=0;

	fp = fopen("C-small-attempt1.in","r");

	fgets(input,500,fp);
	N = atoi(input);

	wel_len = strlen(welcome);

	while(N--)
	{
		nCase++;
		result = 0;
		memset(input,0,sizeof(input));
		fgets(input,NMAX,fp);
		//scanf("%s",input);
		len = strlen(input);
		result = cmp(0,len,0);

		printf("Case #%d: %04d\n",nCase,result);
	}

	fclose(fp);

	return 0;

}

int cmp(int idx,int len,int ptr)
{
	int i;
	int result=0;
	if(idx != wel_len)
	{
		for(i=ptr;i<len;i++)
		{
			if(welcome[idx]==input[i])
				result += cmp(idx+1,len,i+1);
		}
		return result;
	}
	else
	{
		return 1;
	}
}