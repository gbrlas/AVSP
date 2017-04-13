#include <iostream>

using namespace std;

char s[33];
int d[33];

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int cc;
	scanf("%d",&cc);
	for(int z=1;z<=cc;++z)
	{
		printf("Case #%d: ",z);
		scanf("\n%s",s);
		int m=strlen(s);
		for(int i=0;i<m;++i) d[i]=s[i]-'0';
		int j=m-2;
		while(j>-1&&d[j]>=d[j+1]) --j;
		if(j<0)
		{
			sort(d,d+m);
			if(d[0]==0)
			{
				int k=1;
				for(;d[k]==0;++k);
				printf("%d",d[k]);
				for(int i=0;i<=k;++i) putchar('0');
				for(int i=k+1;i<m;++i) printf("%d",d[i]);
				putchar('\n');
			}
			else
			{
				printf("%d",d[0]);
				putchar('0');
				for(int i=1;i<m;++i) printf("%d",d[i]);
				putchar('\n');
			}
		}
		else
		{
			int p=m-1;
			while(d[p]<=d[j]) --p;
			swap(d[p],d[j]);
			sort(d+j+1,d+m);
			for(int i=0;i<m;++i) printf("%d",d[i]);
			putchar('\n');
		}
	}
	return 0;
}

