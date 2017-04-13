#include <string>
#include <iostream>
#include <map>
using namespace std;
#pragma warning (disable:4996)

int main(void)
{
	int n,i,j,len;
	char a[105];
	char c;
	map <char,char> alpha;
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

	alpha['a']='y'; alpha['b']='h'; alpha['c']='e'; alpha['d']='s'; alpha['e']='o'; alpha['f']='c'; 
	alpha['g']='v'; alpha['h']='x'; alpha['i']='d'; alpha['j']='u'; alpha['k']='i'; alpha['l']='g'; 
	alpha['m']='l'; alpha['n']='b'; alpha['o']='k'; alpha['p']='r'; alpha['q']='z'; alpha['r']='t'; 
	alpha['s']='n'; alpha['t']='w'; alpha['u']='j'; alpha['v']='p'; alpha['w']='f'; alpha['x']='m'; 
	alpha['y']='a'; alpha['z']='q'; alpha[' ']=' ';
	cin >> n;
	c=getchar();
	for (i=1;i<n;i++)
	{
		len=0;
		c=getchar();
		a[len++]=c;
		while (c!='0' && c!='\n')
			{c=getchar(); a[len++]=c;}
		a[len]=0;
		for (j=0;j<len;j++)
			a[j]=alpha[a[j]];
		printf("Case #%d: %s\n",i,a);
	}
	len=0;
	c=getchar();
	a[len++]=c;
	while (c!='0' && c!='\n' && c!=-1)
	{
		c=getchar();
		a[len++]=c;
	}
	a[len]=0;
	for (j=0;j<len;j++)
		a[j]=alpha[a[j]];
	printf("Case #%d: %s",i,a);
	return 0;
}