#include<stdio.h>
#include<set>
#include<string>
using namespace std;
char z[1000][101];
int main()
{
	int n;
	scanf("%d",&n);
	for(int t=1;t<=n;t++)
	{
		int s;
		scanf("%d",&s);
		gets(z[0]);
		set<string> js;
		while(s--)
		{
			gets(z[0]);
			js.insert(string(z[0]));
		}
		int q;
		scanf("%d",&q);
		gets(z[0]);
		for(int i=0;i<q;i++)gets(z[i]);
		set<string> gz(js);
		int c=0,i=0;
		while(i<q)
		{
			while(i<q&&!gz.empty())gz.erase(string(z[i])),i++;
			if(gz.empty())gz=js,i--,c++;
		}
		printf("Case #%d: %d\n",t,c);
	}
}
