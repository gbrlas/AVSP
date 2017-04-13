#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <iostream.h>

int m[10];
int ans = 10000;
char ch[2000];
char ch2[2000];
int l;
void check(int x)
{
	//mutation
	int i,j,sum;
	for (i=0;i<l/x;i++)
	{
		for (j=0;j<x;j++)
		{
			ch2[i*x + m[j]] = ch[i*x+j];
		}
	}
	//count

	sum=0;
	for (i=0;i<l-1;i++)
	{
		if (ch2[i]!=ch2[i+1]) sum++;
	}
	sum++;
	if (sum<ans) ans = sum;
}

void a2()
{
	for (m[0]=0;m[0]<=1;m[0]++)
	for (m[1]=0;m[1]<=1;m[1]++)
	{
		if (m[0]!=m[1])
		{
			check(2);
		}
	}
}
void a3()
{
	for (m[0]=0;m[0]<=2;m[0]++)
	for (m[1]=0;m[1]<=2;m[1]++)
	for (m[2]=0;m[2]<=2;m[2]++)
	{
		if (m[0]!=m[1] && m[0]!=m[2] && m[1]!=m[2])
		{
			check(3);
		}
	}
}
void a4()
{
	for (m[0]=0;m[0]<=3;m[0]++)
	for (m[1]=0;m[1]<=3;m[1]++)
	for (m[2]=0;m[2]<=3;m[2]++)
	for (m[3]=0;m[3]<=3;m[3]++)
	{
		if (m[0]!=m[1] && m[0]!=m[2] && m[0]!=m[3] && m[1]!=m[2] && m[1]!=m[3] && m[2]!=m[3])
		{
			check(4);
		}
	}
}

void a5()
{
	for (m[0]=0;m[0]<=4;m[0]++)
	for (m[1]=0;m[1]<=4;m[1]++)
	for (m[2]=0;m[2]<=4;m[2]++)
	for (m[3]=0;m[3]<=4;m[3]++)
	for (m[4]=0;m[4]<=4;m[4]++)
	{
		if (m[0]!=m[1] && m[0]!=m[2] && m[0]!=m[3] && m[1]!=m[2] && m[1]!=m[3] && m[2]!=m[3] 
			&& m[4]!=m[0] && m[4]!=m[1] && m[4]!=m[2] && m[4]!=m[3])
		{
			check(5);
		}
	}
}

int main()
{

	int i,j,k,cas,CASNO,N;

	freopen("D-small-attempt0.in","r",stdin);
	freopen("output.txt","w",stdout);
	gets(ch); sscanf(ch,"%d",&CASNO);
	for (cas=1;cas<=CASNO;cas++)
	{
		ans=1000;
    	gets(ch); sscanf(ch,"%d",&N);
		gets(ch); l = strlen(ch);
		if (N==2) a2();
		if (N==3) a3();
		if (N==4) a4();
		if (N==5) a5();
		printf("Case #%d: %d\n",cas,ans);
	}
	return 1;
}
	