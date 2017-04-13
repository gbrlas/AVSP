#include <stdio.h>
#include <string.h>
#define infile "number.in"
#define outfile "number.out"
#define nmax 33
char v[nmax];

void change(char *a, char *b)
{
	char c=*a; *a=*b; *b=c;
}

void sort(int a, int b)
{
	int i,j;
	for(i=a;i<=b;i++)
		for(j=i+1;j<=b;j++)
			if(v[j]<v[i])
				change(&v[i],&v[j]);
}

void next()
{
	int n=strlen(v)-1;
	int i,j;
	int pmin;
	char vmin;
	
	for(i=n-1;i>=0;i--)
	{
		pmin=n; vmin=100;
		for(j=n-1;j>i;j--)
			if(v[j]>v[i] && v[j]<vmin && (i>0 || v[j]!='0'))
			{
				vmin=v[j];
				pmin=j;
			}
		if(pmin<n) //am gasit solutie
		{
			change(&v[i],&v[pmin]);
			sort(i+1,n-1);
			break;
		}
	}
	if(pmin==n)
	{
		sort(0,n-1);
		for(i=n+1;i>0;i--)
			v[i]=v[i-1];
		v[n+2]=0;
		v[1]='0';
		for(i=1;v[0]=='0';i++)
			change(&v[0],&v[i]);
	}
	printf("%s",v); //show
}

int main()
{
	int i,t;
	freopen(infile,"r",stdin);
	freopen(outfile,"w",stdout);
	
	scanf("%d\n",&t);
	for(i=1;i<=t;i++)
	{
		fgets(v,nmax,stdin);
		printf("Case #%d: ",i);
		next();
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}