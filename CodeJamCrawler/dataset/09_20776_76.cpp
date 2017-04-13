#include <stdio.h>

#include <stdlib.h>

unsigned long long megoldas(char * input,char * search)
{
if (strlen(search)==0)
	return 1;
if (strlen(input)==0)
	return 0;
	
unsigned long long retval=0;
int i;
for (i=0;i<strlen(input);i++ )
	{if (input[i]==search[0]) retval+=megoldas(input+i,search+1);
	}
return retval;	
}

int main()
{
int casenum=0;
scanf("%d",&casenum);
int i;
char felejtos[2];
	fgets(felejtos,502,stdin);
for (i=0;i<casenum;i++)
	{
	printf("Case #%d: ",i+1);
	//printf("%d %d\n",i,casenum);
	char str[502];
	//scanf("%s",str);
	fgets(str,502,stdin);
	//printf("%s",str);
	unsigned long long r=megoldas(str,"welcome to code jam");
	printf("%04lld\n",r);
	
	}
}
